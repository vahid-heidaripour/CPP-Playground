//
// Created by Vahid Heidaripour on 2019-03-15.
//

#ifndef SDL_SWARM_H
#define SDL_SWARM_H

#include "Particle.h"

namespace cpp_playground
{
    class Swarm {
    public:
        const static int NPARTICLES = 5000;

    private:
        Particle * _pParticles;
        int _lastTime;

    public:
        Swarm();
        virtual ~Swarm();
        void update(int elapsed);

        const Particle * const getParticles() { return _pParticles; };
    };
}

#endif //SDL_SWARM_H
