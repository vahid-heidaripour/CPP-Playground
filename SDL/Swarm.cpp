//
// Created by Vahid Heidaripour on 2019-03-15.
//

#include "Swarm.h"

namespace cpp_playground
{
    Swarm::Swarm()
    {
        _pParticle = new Particle[NPARTICLES];
    }

    Swarm::~Swarm()
    {
        delete [] _pParticle;
    }
}