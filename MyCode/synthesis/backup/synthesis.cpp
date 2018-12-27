#include "io/TglMeshReader.hpp"
#include "utils/macros.h"
#include "utils/term_msg.h"
#include "AudioProducer.h"
#include "synthesis.h"

using namespace std;



int synthesis(string filename, int selTriId_){
	TriangleMesh<double>    mesh_;

	AudioProducer*      audio_ = new AudioProducer(filename,1,1,1);
	
	if ( _FAILED( MeshObjReader::read(filename.c_str(), mesh_) ) )
    	{
        	PRINT_ERROR("Cannot load the mesh file: %s\n", 
                    filename.c_str());
        	SHOULD_NEVER_HAPPEN(-1);
    	}
    	
	if ( !mesh_.has_normals() ) mesh_.generate_pseudo_normals();
	
    	cout << "selected triangle ID:  " << selTriId_ << endl;

    	//// Now synthesize sound and play

        const vector<Point3d>&  vtx = mesh_.vertices();
        const vector<Tuple3ui>& tgl = mesh_.surface_indices();
        Vector3d nml = Triangle<double>::normal( 
                vtx[tgl[selTriId_].x], 
                vtx[tgl[selTriId_].y], 
                vtx[tgl[selTriId_].z] );
        nml.normalize();
        audio_->play( mesh_.triangle_ids(selTriId_), nml);
    	
	return 0;	


}
