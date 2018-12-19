#ifndef AUDIO_PRODUCER_INC
#   define AUDIO_PRODUCER_INC

#include "sc/Vector3.hpp"
#include "geometry/Point3.hpp"
#include "modal/ModalModel.h"
#include <cstring>

class AudioProducer
{
    public:
        AudioProducer(std::string filename,double density,double alpha,double beta);

        ~AudioProducer();

        void play(const Tuple3ui& tri, const Vector3d& dir);

    private:
        void init();
        void load_vertex_map(std::string filename);
        // synthesize sound just for single channel (no stereo sound)

    private:

        ModalModel*         modal_;
        int                 numFixed_;
        std::vector<double> mForce_;        // force in modal space
  /* ------------ geometry ----------
         * map the vertex from surface triangle mesh to tet mesh
         * m_surfid[i] is the id in tet mesh of the i-th vertex in 
         * surface triangle mesh
         */
        std::vector<int>    vidS2T_;        // vertex map for surface VID to tet VID
};

#endif
