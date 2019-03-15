//
// Created by Vahid Heidaripour on 2019-03-15.
//

#ifndef SDL_SWARM_H
#define SDL_SWARM_H

#include "Particle.h"

namespace cpp_playground
{
    class Swarm
    {
    public:
        const static int NPARTICLES = 1000;

    private:
        Particle *_pParticle;

    public:
        Swarm();
        virtual ~Swarm();

        const Particle *const getParticles() { return _pParticle;};
    };
}

#endif //SDL_SWARM_H
