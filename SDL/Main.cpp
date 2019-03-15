#include <iostream>
#include <SDL2/SDL.h>
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
        if (!screen.processEvents())
            break;
    }

    screen.close();

    return 0;
}