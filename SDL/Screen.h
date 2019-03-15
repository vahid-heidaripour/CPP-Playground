//
// Created by Vahid Heidaripour on 2019-03-15.
//

#ifndef SDL_SCREEN_H
#define SDL_SCREEN_H

#include <SDL2/SDL.h>

namespace cpp_playground
{
    class Screen {
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Texture *_texture;
        Uint32 *_buffer1;
        Uint32 *_buffer2;

    public:
        Screen();
        bool init();
        void update();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        bool processEvents();
        void close();
        void clear();
        void boxBlur();
    };
}

#endif //SDL_SCREEN_H
