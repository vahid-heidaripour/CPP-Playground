//
// Created by Vahid Heidaripour on 2019-03-15.
//

#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace cpp_playground
{
    Particle::Particle(): _x(0), _y(0) {
        _direction = (2 * M_PI * rand())/RAND_MAX;
        _speed = (0.001 * rand())/RAND_MAX;
    }

    Particle::~Particle() {
    }

    void Particle::update() {
        double xspeed = _speed * cos(_direction);
        double yspeed = _speed * sin(_direction);

        _x += xspeed;
        _y += yspeed;
    }
}
