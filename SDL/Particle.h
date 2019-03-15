//
// Created by Vahid Heidaripour on 2019-03-15.
//

#ifndef SDL_PARTICLE_H
#define SDL_PARTICLE_H

namespace cpp_playground
{
    struct Particle {
        double _x;
        double _y;

        double _speed;
        double _direction;

    public:
        Particle();
        virtual ~Particle();
        void update();
    };
}


#endif //SDL_PARTICLE_H
