//
// Created by Vahid Heidaripour on 2019-03-15.
//

#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace cpp_playground
{
    Particle::Particle() {
        init();
    }

    Particle::~Particle() {
    }

    void Particle::init() {
        _x = 0;
        _y = 0;

        _direction = (2 * M_PI * rand())/RAND_MAX;
        _speed = (0.05 * rand())/RAND_MAX;

        _speed *= _speed;
    }

    void Particle::update(int interval) {
        _direction += interval * 0.0002;

        double xspeed = _speed * cos(_direction);
        double yspeed = _speed * sin(_direction);

        _x += xspeed * interval;
        _y += yspeed * interval;

        if (_x < -1 || _x > 1 || _y < -1 || _y > 1) {
            init();
        }

        if (rand() < RAND_MAX / 100)
            init();
    }
}
