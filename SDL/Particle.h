//
// Created by Vahid Heidaripour on 2019-03-15.
//

#ifndef SDL_PARTICLE_H
#define SDL_PARTICLE_H

namespace cpp_playground
{
    class Particle
    {
    public:
        Particle();
        virtual ~Particle();
        double getX() { return _x;};
        double getY() { return _y;};

    private:
        double _x;
        double _y;
    };
}


#endif //SDL_PARTICLE_H
