#include "includes/CompFab.h"
#include "math.h"
#include "curand.h"
#include "curand_kernel.h"
#include "includes/cuda_math.h"

#include <iostream>
#include <string>
#include <sstream>
#include "stdio.h"
#include <vector>

#define RANDOM_SEEDS 1000
#define EPSILONF 0.00000000001
#define E_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062

// check cuda calls for errors
#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }

#define X 0
#define Y 1
#define Z 2

#define CROSS(dest,v1,v2) \
          dest[0]=v1[1]*v2[2]-v1[2]*v2[1]; \
          dest[1]=v1[2]*v2[0]-v1[0]*v2[2]; \
          dest[2]=v1[0]*v2[1]-v1[1]*v2[0];

#define DOT(v1,v2) (v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2])

#define SUB(dest,v1,v2) \
          dest[0]=v1[0]-v2[0]; \
          dest[1]=v1[1]-v2[1]; \
          dest[2]=v1[2]-v2[2];

#define FINDMINMAX(x0,x1,x2,min,max) \
  min = max = x0;   \
  if(x1<min) min=x1;\
  if(x1>max) max=x1;\
  if(x2<min) min=x2;\
  if(x2>max) max=x2;

__device__ int planeBoxOverlap(float normal[3],float d, float maxbox[3])
{
  int q;
  float vmin[3],vmax[3];
  for(q=X;q<=Z;q++)
  {
    if(normal[q]>0.0f)
    {
      vmin[q]=-maxbox[q];
      vmax[q]=maxbox[q];
    }
    else
    {
      vmin[q]=maxbox[q];
      vmax[q]=-maxbox[q];
    }
  }
  if(DOT(normal,vmin)+d>0.0f) return 0;
  if(DOT(normal,vmax)+d>=0.0f) return 1;

  return 0;
}


/*======================== X-tests ========================*/
#define AXISTEST_X01(a, b, fa, fb)             \
    p0 = a*v0[Y] - b*v0[Z];                    \
    p2 = a*v2[Y] - b*v2[Z];                    \
        if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;} \
    rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];   \
    if(min>rad || max<-rad) return 0;

#define AXISTEST_X2(a, b, fa, fb)              \
    p0 = a*v0[Y] - b*v0[Z];                    \
    p1 = a*v1[Y] - b*v1[Z];                    \
        if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
    rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];   \
    if(min>rad || max<-rad) return 0;

/*======================== Y-tests ========================*/
#define AXISTEST_Y02(a, b, fa, fb)             \
    p0 = -a*v0[X] + b*v0[Z];                   \
    p2 = -a*v2[X] + b*v2[Z];                       \
        if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;} \
    rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];   \
    if(min>rad || max<-rad) return 0;

#define AXISTEST_Y1(a, b, fa, fb)              \
    p0 = -a*v0[X] + b*v0[Z];                   \
    p1 = -a*v1[X] + b*v1[Z];                       \
        if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
    rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];   \
    if(min>rad || max<-rad) return 0;

/*======================== Z-tests ========================*/

#define AXISTEST_Z12(a, b, fa, fb)             \
    p1 = a*v1[X] - b*v1[Y];                    \
    p2 = a*v2[X] - b*v2[Y];                    \
        if(p2<p1) {min=p2; max=p1;} else {min=p1; max=p2;} \
    rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];   \
    if(min>rad || max<-rad) return 0;

#define AXISTEST_Z0(a, b, fa, fb)              \
    p0 = a*v0[X] - b*v0[Y];                \
    p1 = a*v1[X] - b*v1[Y];                    \
        if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;} \
    rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];   \
    if(min>rad || max<-rad) return 0;

__device__ int triBoxOverlap(float boxcenter[3],float boxhalfsize[3],float triverts[3][3])
{

  /*    use separating axis theorem to test overlap between triangle and box */
  /*    need to test for overlap in these directions: */
  /*    1) the {x,y,z}-directions (actually, since we use the AABB of the triangle */
  /*       we do not even need to test these) */
  /*    2) normal of the triangle */
  /*    3) crossproduct(edge from tri, {x,y,z}-directin) */
  /*       this gives 3x3=9 more tests */
   float v0[3],v1[3],v2[3];
   float min,max,d,p0,p1,p2,rad,fex,fey,fez;
   float normal[3],e0[3],e1[3],e2[3];

   /* This is the fastest branch on Sun */
   /* move everything so that the boxcenter is in (0,0,0) */
   SUB(v0,triverts[0],boxcenter);
   SUB(v1,triverts[1],boxcenter);
   SUB(v2,triverts[2],boxcenter);

   /* compute triangle edges */
   SUB(e0,v1,v0);      /* tri edge 0 */
   SUB(e1,v2,v1);      /* tri edge 1 */
   SUB(e2,v0,v2);      /* tri edge 2 */

   /* Bullet 3:  */
   /*  test the 9 tests first (this was faster) */
   fex = fabs(e0[X]);
   fey = fabs(e0[Y]);
   fez = fabs(e0[Z]);
   AXISTEST_X01(e0[Z], e0[Y], fez, fey);
   AXISTEST_Y02(e0[Z], e0[X], fez, fex);
   AXISTEST_Z12(e0[Y], e0[X], fey, fex);

   fex = fabs(e1[X]);
   fey = fabs(e1[Y]);
   fez = fabs(e1[Z]);
   AXISTEST_X01(e1[Z], e1[Y], fez, fey);
   AXISTEST_Y02(e1[Z], e1[X], fez, fex);
   AXISTEST_Z0(e1[Y], e1[X], fey, fex);

   fex = fabs(e2[X]);
   fey = fabs(e2[Y]);
   fez = fabs(e2[Z]);
   AXISTEST_X2(e2[Z], e2[Y], fez, fey);
   AXISTEST_Y1(e2[Z], e2[X], fez, fex);
   AXISTEST_Z12(e2[Y], e2[X], fey, fex);

   /* Bullet 1: */
   /*  first test overlap in the {x,y,z}-directions */
   /*  find min, max of the triangle each direction, and test for overlap in */
   /*  that direction -- this is equivalent to testing a minimal AABB around */
   /*  the triangle against the AABB */

   /* test in X-direction */
   FINDMINMAX(v0[X],v1[X],v2[X],min,max);
   if(min>boxhalfsize[X] || max<-boxhalfsize[X]) return 0;

   /* test in Y-direction */
   FINDMINMAX(v0[Y],v1[Y],v2[Y],min,max);
   if(min>boxhalfsize[Y] || max<-boxhalfsize[Y]) return 0;

   /* test in Z-direction */
   FINDMINMAX(v0[Z],v1[Z],v2[Z],min,max);
   if(min>boxhalfsize[Z] || max<-boxhalfsize[Z]) return 0;

   /* Bullet 2: */
   /*  test if the box intersects the plane of the triangle */
   /*  compute plane equation of triangle: normal*x+d=0 */
   CROSS(normal,e0,e1);
   d=-DOT(normal,v0);  /* plane eq: normal.x+d=0 */
   if(!planeBoxOverlap(normal,d,boxhalfsize)) return 0;

   return 1;   /* box and triangle overlaps */
}

inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess) 
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}

// generates a random float between 0 and 1
__device__ float generate( curandState* globalState , int ind) 
{
    curandState localState = globalState[ind];
    float RANDOM = curand_uniform( &localState );
    globalState[ind] = localState; 
    return RANDOM;
}
// set up random seed buffer
__global__ void setup_kernel ( curandState * state, unsigned long seed )
{
    int id = threadIdx.x;
    curand_init ( seed, id, 0, &state[id] );
} 


__device__ bool inside(unsigned int numIntersections, bool double_thick) {
	// if (double_thick && numIntersections % 2 == 0) return (numIntersections / 2) % 2 == 1;
	if (double_thick) return (numIntersections / 2) % 2 == 1;
	return numIntersections % 2 == 1;
}

// adapted from: https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
__device__ bool intersects(CompFab::Triangle &triangle, float3 dir, float3 pos) {
	float3 V1 = {triangle.m_v1.m_x, triangle.m_v1.m_y, triangle.m_v1.m_z};
	float3 V2 = {triangle.m_v2.m_x, triangle.m_v2.m_y, triangle.m_v2.m_z};
	float3 V3 = {triangle.m_v3.m_x, triangle.m_v3.m_y, triangle.m_v3.m_z};

	//Find vectors for two edges sharing V1
	float3 e1 = V2 - V1;
	float3 e2 = V3 - V1;
	
	// //Begin calculating determinant - also used to calculate u parameter
	float3 P = cross(dir, e2);

	//if determinant is near zero, ray lies in plane of triangle
	float det = dot(e1, P);
	
	//NOT CULLING
	if(det > -EPSILONF && det < EPSILONF) return false;
	float inv_det = 1.f / det;

	// calculate distance from V1 to ray origin
	float3 T = pos - V1;
	//Calculate u parameter and test bound
	float u = dot(T, P) * inv_det;
	//The intersection lies outside of the triangle
	if(u < 0.f || u > 1.f) return false;

	//Prepare to test v parameter
	float3 Q = cross(T, e1);
	//Calculate V parameter and test bound
	float v = dot(dir, Q) * inv_det;
	//The intersection lies outside of the triangle
	if(v < 0.f || u + v  > 1.f) return false;

	float t = dot(e2, Q) * inv_det;

	if(t > EPSILONF) { // ray intersection
		return true;
	}

	// No hit, no win
	return false;
}

__device__ float distance( CompFab::Triangle &triangle ,  float3 pos) 
{
	float3 V1 = {triangle.m_v1.m_x, triangle.m_v1.m_y, triangle.m_v1.m_z};
	float3 V2 = {triangle.m_v2.m_x, triangle.m_v2.m_y, triangle.m_v2.m_z};
	float3 V3 = {triangle.m_v3.m_x, triangle.m_v3.m_y, triangle.m_v3.m_z}; 
	float3 mid = (V1+V2+V3)/3.f;
	float3 d = pos - mid;
	return length(d);
	
}


// Decides whether or not each voxel is within the given mesh
__global__ void voxelize_kernel( 
	bool* R,int* I, CompFab::Triangle* triangles, const int numTriangles, 
	const float spacing, const float3 bottom_left,
	const int w, const int h, const int d, bool double_thick)
{
	// find the position of the voxel
	unsigned int xIndex = blockDim.x * blockIdx.x + threadIdx.x;
	unsigned int yIndex = blockDim.y * blockIdx.y + threadIdx.y;
	unsigned int zIndex = blockDim.z * blockIdx.z + threadIdx.z;
	// pick an arbitrary sampling direction
	float3 dir = make_float3(1.0, 0.0, 0.0);

	if ( (xIndex < w) && (yIndex < h) && (zIndex < d) )
	{
		// find linearlized index in final boolean array
		unsigned int index_out = zIndex*(w*h)+yIndex*h + xIndex;
		
		// find world space position of the voxel
		float3 pos = make_float3(bottom_left.x + spacing*xIndex,bottom_left.y + spacing*yIndex,bottom_left.z + spacing*zIndex);

		// check if the voxel is inside of the mesh. 
		// if it is inside, then there should be an odd number of 
		// intersections with the surrounding mesh
		unsigned int intersections = 0;
		bool yes = 0;
		for (int i = 0; i < numTriangles; ++i){
			if (intersects(triangles[i], dir, pos)){
				intersections += 1;
			}
			float boxcenter[3];
			float boxhalfsize[3];
			boxcenter[0] = pos.x;boxcenter[1] = pos.y;boxcenter[2] = pos.z;
			boxhalfsize[0] = boxhalfsize[1] = boxhalfsize[2] = spacing*0.5;
			CompFab::Triangle &triangle = triangles[i];
			float triverts[3][3] = {
			{triangle.m_v1.m_x, triangle.m_v1.m_y, triangle.m_v1.m_z},
			{triangle.m_v2.m_x, triangle.m_v2.m_y, triangle.m_v2.m_z},
			{triangle.m_v3.m_x, triangle.m_v3.m_y, triangle.m_v3.m_z}};
			if (triBoxOverlap(boxcenter,boxhalfsize,triverts) == 1)
				yes = 1;

		}
		// store answer
		R[index_out] = inside(intersections, double_thick) || yes;
///////////////////////////////////////////////////////////////////////////
/*		I[index_out] = -1;
		if (R[index_out]){
			float mndist = distance(triangles[0],pos);
			int index = 0;
			for (int i = 1; i < numTriangles; ++i)
				if (distance(triangles[i],pos) < mndist){
					mndist = distance(triangles[i],pos);
					index = i;
				}

			// store answer
			I[index_out] = index;

		}*/
///////////////////////////////////////////////////////////////////////////
	}
}


// Decides whether or not each voxel is within the given partially un-closed mesh
// checks a variety of directions and picks most common belief
__global__ void voxelize_kernel_open_mesh( 
	// triangles of the mesh being voxelized
	bool* R, int* I, CompFab::Triangle* triangles, const int numTriangles, 
	// information about how large the samples are and where they begin
	const float spacing, const float3 bottom_left,
	// number of voxels
	const int w, const int h, const int d, 
	// sampling information for multiple intersection rays
	const int samples, curandState* globalState, bool double_thick
	)
{
	// find the position of the voxel
	unsigned int xIndex = blockDim.x * blockIdx.x + threadIdx.x;
	unsigned int yIndex = blockDim.y * blockIdx.y + threadIdx.y;
	unsigned int zIndex = blockDim.z * blockIdx.z + threadIdx.z;

	if ( (xIndex < w) && (yIndex < h) && (zIndex < d) )
	{
		// find linearlized index in final boolean array
		unsigned int index_out = zIndex*(w*h)+yIndex*h + xIndex;
		// find world space position of the voxel
		float3 pos = make_float3(bottom_left.x + spacing*xIndex,bottom_left.y + spacing*yIndex,bottom_left.z + spacing*zIndex);
		float3 dir;

		// we will randomly sample 3D space by sending rays in randomized directions
		int votes = 0;
		float theta;
		float z;

		for (int j = 0; j < samples; ++j)
		{
			// compute the random direction. Convert from polar to euclidean to get an even distribution
			theta = generate(globalState, index_out % RANDOM_SEEDS) * 2.f * E_PI;
			z = generate(globalState, index_out % RANDOM_SEEDS) * 2.f - 1.f;

			dir.x = sqrt(1-z*z) * cosf(theta);
			dir.y = sqrt(1-z*z) * sinf(theta);
			dir.z = sqrt(1-z*z) * cosf(theta);

			// check if the voxel is inside of the mesh. 
			// if it is inside, then there should be an odd number of 
			// intersections with the surrounding mesh
			unsigned int intersections = 0;
			for (int i = 0; i < numTriangles; ++i)
				if (intersects(triangles[i], dir, pos)) 
					intersections += 1;
			if (inside(intersections, double_thick)) votes += 1;
		}
		// choose the most popular answer from all of the randomized samples
		R[index_out] = votes > (samples / 2.f);
	}
}

// voxelize the given mesh with the given resolution and dimensions
void kernel_wrapper(int samples, int w, int h, int d, CompFab::VoxelGrid *g_voxelGrid, CompFab::IndexVoxelGrid *g_index_voxelGrid, std::vector<CompFab::Triangle> triangles, bool double_thick)
{
	int blocksInX = (w+8-1)/8;
	int blocksInY = (h+8-1)/8;
	int blocksInZ = (d+8-1)/8;

	dim3 Dg(blocksInX, blocksInY, blocksInZ);
	dim3 Db(8, 8, 8);

	curandState* devStates;
	if (samples > 0) {
		// set up random numbers
		dim3 tpb(RANDOM_SEEDS,1,1);
	    cudaMalloc ( &devStates, RANDOM_SEEDS*sizeof( curandState ) );
	    // setup seeds
	    setup_kernel <<< 1, tpb >>> ( devStates, time(NULL) );
	}
	
	// set up boolean array on the GPU
	bool *gpu_inside_array;
	gpuErrchk( cudaMalloc( (void **)&gpu_inside_array, sizeof(bool) * w * h * d ) );
	gpuErrchk( cudaMemcpy( gpu_inside_array, g_voxelGrid->m_insideArray, sizeof(bool) * w * h * d, cudaMemcpyHostToDevice ) );

//////////////////////////////////////////////////////////////////////////////////////////
	//// set up int array on the GPU
	int *gpu_inside_index_array;
	gpuErrchk( cudaMalloc( (void **)&gpu_inside_index_array, sizeof(int) * w * h * d ) );
	gpuErrchk( cudaMemcpy( gpu_inside_index_array, g_index_voxelGrid->m_insideArray, sizeof(int) * w * h * d, cudaMemcpyHostToDevice ) );
	gpuErrchk( cudaMemcpy( gpu_inside_array, g_voxelGrid->m_insideArray, sizeof(bool) * w * h * d, cudaMemcpyHostToDevice ) );
////////////////////////////////////////////////////////////////////////////////////////////
	// set up triangle array on the GPU
	CompFab::Triangle* triangle_array = &triangles[0];
	CompFab::Triangle* gpu_triangle_array;
	gpuErrchk( cudaMalloc( (void **)&gpu_triangle_array, sizeof(CompFab::Triangle) * triangles.size() ) );
	gpuErrchk( cudaMemcpy( gpu_triangle_array, triangle_array, sizeof(CompFab::Triangle) * triangles.size(), cudaMemcpyHostToDevice ) );

	float3 lower_left = make_float3(g_voxelGrid->m_lowerLeft.m_x, g_voxelGrid->m_lowerLeft.m_y, g_voxelGrid->m_lowerLeft.m_z);
	//printf("spacing:%lf\n",(float) g_voxelGrid->m_spacing);
	if (samples > 0) {
		voxelize_kernel_open_mesh<<<Dg, Db>>>(gpu_inside_array, gpu_inside_index_array, gpu_triangle_array, triangles.size(), (float) g_voxelGrid->m_spacing, lower_left, w, h, d, samples, devStates, double_thick);
	} else {
		voxelize_kernel<<<Dg, Db>>>(gpu_inside_array, gpu_inside_index_array, gpu_triangle_array, triangles.size(), (float) g_voxelGrid->m_spacing, lower_left, w, h, d, double_thick);
	}

	gpuErrchk( cudaPeekAtLastError() );
	gpuErrchk( cudaDeviceSynchronize() );

	gpuErrchk( cudaMemcpy( g_voxelGrid->m_insideArray, gpu_inside_array, sizeof(bool) * w * h * d, cudaMemcpyDeviceToHost ) );
//////////////////////////////////////////////////////////////////////////////////////////////////////

	gpuErrchk( cudaMemcpy( g_index_voxelGrid->m_insideArray, gpu_inside_index_array, sizeof(int) * w * h * d, cudaMemcpyDeviceToHost ) );
	gpuErrchk( cudaFree(gpu_inside_index_array) );
//////////////////////////////////////////////////////////////////////////////////////////////
	gpuErrchk( cudaFree(gpu_inside_array) );
	gpuErrchk( cudaFree(gpu_triangle_array) );
}
