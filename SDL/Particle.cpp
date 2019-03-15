//
// Created by Vahid Heidaripour on 2019-03-15.
//

#include "Particle.h"
#include <stdlib.h>

namespace cpp_playground
{
    Particle::Particle()
    {
        _x = ((2.0 * rand()) / RAND_MAX) - 1;
        _y = ((2.0 * rand()) / RAND_MAX) - 1;

        _xspeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
        _yspeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
    }

    Particle::~Particle()
    {

    }

    void Particle::update()
    {
        _x += _xspeed;
        _y += _yspeed;

        if (_x <= -1.0 || _x >= 1.0)
            _xspeed = -_xspeed;

        if (_y <= -1.0 || _y >= 1.0)
            _yspeed = -_yspeed;
    }
}
