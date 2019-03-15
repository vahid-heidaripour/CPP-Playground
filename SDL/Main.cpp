#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Screen.h"

using namespace std;
using namespace cpp_playground;

int main()
{
    Screen screen;

    if (!screen.init())
    {
        cout << "Error initialising SDL." << endl;
    }

    while (true)
    {
        int elapsed = SDL_GetTicks();

        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
            {
                screen.setPixel(x, y, red, green, blue);
            }
        }

        screen.update();


        if (!screen.processEvents())
            break;
    }

    screen.close();

    return 0;
}