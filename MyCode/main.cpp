#include "mesh2mesh/mesh2mesh.h"



TetMesh<double>* callmesh2mesh(){
	char *argv[5] = {"mesh2mesh","1.obj","1.tet","-R","4"};
	return mesh2mesh(5,argv);
}
int main(){
	
	TetMesh<double>* pmesh = callmesh2mesh();
	
	



}
