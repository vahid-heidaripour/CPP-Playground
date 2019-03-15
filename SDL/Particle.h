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
        void update();
        double getX() { return _x;};
        double getY() { return _y;};
        double getXSpeed() { return _xspeed;};
        double getYSpeed() { return _yspeed;};

    private:
        double _x;
        double _y;
        double _xspeed;
        double _yspeed;
    };
}


#endif //SDL_PARTICLE_H
