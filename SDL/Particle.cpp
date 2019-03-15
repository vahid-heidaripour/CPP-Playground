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
    }

    Particle::~Particle()
    {

    }
}
