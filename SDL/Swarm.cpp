//
// Created by Vahid Heidaripour on 2019-03-15.
//

#include "Swarm.h"

namespace cpp_playground {
    Swarm::Swarm() : _lastTime(0) {
        _pParticles = new Particle[NPARTICLES];
    }

    Swarm::~Swarm() {
        delete[] _pParticles;
    }

    void Swarm::update(int elapsed) {
        int interval = elapsed - _lastTime;

        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            _pParticles[i].update(interval);
        }

        _lastTime = elapsed;
    }
}