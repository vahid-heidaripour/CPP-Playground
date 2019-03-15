#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace cpp_playground;

int main()
{
    srand(time(NULL));

    Screen screen;

    if (!screen.init())
    {
        cout << "Error initialising SDL." << endl;
    }

    Swarm swarm;

    while (true)
    {
        int elapsed = SDL_GetTicks();

        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

        const Particle *const pParticle = swarm.getParticles();

        for (int i = 0; i < Swarm::NPARTICLES; i++)
        {
            Particle particle = pParticle[i];

            int x = (particle.getX() + 1) * Screen::SCREEN_WIDTH / 2;
            int y = (particle.getY() + 1) * Screen::SCREEN_HEIGHT / 2;

            screen.setPixel(x, y, red, green, blue);
        }

        screen.update();


        if (!screen.processEvents())
            break;
    }

    screen.close();

    return 0;
}