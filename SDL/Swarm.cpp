//
// Created by Vahid Heidaripour on 2019-03-15.
//

#include "Swarm.h"

namespace cpp_playground {
    Swarm::Swarm() {
        _pParticles = new Particle[NPARTICLES];
    }

    Swarm::~Swarm() {
        delete[] _pParticles;
    }

    void Swarm::update() {
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            _pParticles[i].update();
        }
    }
}