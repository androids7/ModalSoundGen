#include "AudioProducer.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include "utils/term_msg.h"
#include "utils/macros.h"

using namespace std;

AudioProducer::AudioProducer(string filename,double density,double alpha,double beta) 
{
    // --- load vertex map ---

    load_vertex_map(filename + ".geo.txt");

    // --- load modal shape matrix ---

    modal_ = new ModalModel(
        filename + ".ev",
        density,
        alpha,
        beta);

    mForce_.resize( modal_->num_modes() );
    init();
}

AudioProducer::~AudioProducer()
{
    
}

/*
 * Vertex map to map from surface vertex to tet vertex
 */
void AudioProducer::load_vertex_map(string filename)
{
    int id1, id2;

    std::ifstream fin( filename.c_str() );
    if ( fin.fail() )
    {
        PRINT_ERROR("Cannot read file: %s\n", filename.c_str());
        SHOULD_NEVER_HAPPEN(2);
    }
    fin >> numFixed_ >> id1;    // # of fixed vertices in tet mesh 
                                // & total number of surface vertices
    PRINT_MSG("  # of fixed vertices: %d\n", numFixed_);
    vidS2T_.resize(id1);
    for(size_t i = vidS2T_.size();i > 0;-- i)
    {
        fin >> id1 >> id2;
        if ( id2 >= vidS2T_.size() )
        {
            PRINT_ERROR("Id2 is out of range in geometry file\n");
            SHOULD_NEVER_HAPPEN(3);
        }
        vidS2T_[id2] = id1;
    }
    if ( fin.fail() )
    {
        PRINT_ERROR("Error occurred while reading file: %s\n", filename.c_str());
        SHOULD_NEVER_HAPPEN(2);
    }
    fin.close();
}

void AudioProducer::init()
{
 
}

void AudioProducer::play(const Tuple3ui& tri, const Vector3d& dir)
{

    memset( mForce_.data(), 0, sizeof(double)*mForce_.size() );
    modal_->accum_modal_impulse( vidS2T_[tri.x]-numFixed_, &dir, mForce_.data() );
    modal_->accum_modal_impulse( vidS2T_[tri.y]-numFixed_, &dir, mForce_.data() );
    modal_->accum_modal_impulse( vidS2T_[tri.z]-numFixed_, &dir, mForce_.data() );

    const vector<double>& omegaD = modal_->damped_omega();
    const vector<double>& c      = modal_->damping_vector();
    PRINT_MSG("print frequency and damping ridio\n");
    std::ofstream out("out.txt");
    for(int i = 0;i < modal_->num_modes();++ i)
    {
	PRINT_MSG("omegaD:%lf c:%lf\n",omegaD[i],c[i]);
	out << omegaD[i] << " " << c[i] << endl;
	/*
        const double SS = mForce_[i] / omegaD[i];
        for(int ti = 0;ti < totTicks;++ ti)
        {
            const double ts = static_cast<double>(ti) / static_cast<double>(SR);    // time
            const double amp = exp(- c[i]*0.5*ts );    // exp(-xi * omega * t)
            if ( amp < 1E-5 ) break;
            cout << ts << " " << amp << endl;
            //soundBuffer_[ti] += amp * SS * sin( omegaD[i]*ts );  // sin(omega_d * t)
        }*/
    } // end for
    out.close();


}
