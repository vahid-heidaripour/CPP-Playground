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

    private:
        double _speed;
        double _direction;

    private:
        void init();

    public:
        Particle();
        virtual ~Particle();
        void update(int interval);
    };
}


#endif //SDL_PARTICLE_H
