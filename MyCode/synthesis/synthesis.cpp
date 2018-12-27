#include "io/TglMeshReader.hpp"
#include "utils/macros.h"
#include "utils/term_msg.h"
#include "AudioProducer.h"
#include "synthesis.h"

using namespace std;



int synthesis(string filename, int selTriId_,double density,double alpha,double beta){
	TriangleMesh<double>    mesh_;

	AudioProducer*      audio_ = new AudioProducer(filename,density,alpha,beta);
	
	if ( _FAILED( MeshObjReader::read((filename + ".obj").c_str(), mesh_) ) )
    	{
        	PRINT_ERROR("Cannot load the mesh file: %s\n", 
                    filename.c_str());
        	SHOULD_NEVER_HAPPEN(-1);
    	}
	PRINT_MSG("mesh_.generate_pseudo_normals\n");
	if ( !mesh_.has_normals() ) mesh_.generate_pseudo_normals();

	PRINT_MSG("selected triangle ID:%d\n",selTriId_);	

    	//// Now synthesize sound and play

        const vector<Point3d>&  vtx = mesh_.vertices();
        const vector<Tuple3ui>& tgl = mesh_.surface_indices();
        Vector3d nml = Triangle<double>::normal( 
                vtx[tgl[selTriId_].x], 
                vtx[tgl[selTriId_].y], 
                vtx[tgl[selTriId_].z] );
        nml.normalize();
        PRINT_MSG("audio_play\n");  
 	audio_->play( mesh_.triangle_ids(selTriId_), nml);
    	
	return 0;	


}
