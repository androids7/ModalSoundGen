#include "mesh2mesh/mesh2mesh.h"
#include "tet2matrices/modal_eigen.h"
#include "tet2matrices/extract_matrices.h"


void  callmesh2mesh(){
	char *argv[] = {"mesh2mesh","1.obj","1.tet","-R","4","-M","7"};
	int ret = mesh2mesh(7,argv);
}
void calltet2matrices(){
	char *argv1[] = {"extmat","-f","1","-y","70","-p","0.2","-m","-k","-g"};
	int ret1 = extmat(10, argv1);
	char *argv2[] = {"modal_eigen","-s","1.stiff.csc","-m","1.mass.csc","-o","1.ev","-v"};
	int ret2 = modal_eigen(7,argv2);

}

int main(){
	
	callmesh2mesh();
	calltet2matrices();
	



}
