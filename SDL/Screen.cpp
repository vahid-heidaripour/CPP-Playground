//
// Created by Vahid Heidaripour on 2019-03-15.
//

#include "Screen.h"

namespace cpp_playground
{
    Screen::Screen() : _window(NULL), _renderer(NULL), _texture(NULL), _buffer(NULL)
    {

    }

    bool Screen::init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            return false;
        }

        _window = SDL_CreateWindow("test",
                                   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (_window == NULL)
        {
            SDL_Quit();
            return false;
        }

        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);

        if (_renderer == NULL)
        {
            SDL_DestroyWindow(_window);
            SDL_Quit();
            return false;
        }

        _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888,
                                     SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (_texture == NULL)
        {
            SDL_DestroyRenderer(_renderer);
            SDL_DestroyWindow(_window);
            SDL_Quit();
            return false;
        }

        _buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(_buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        return true;
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
    {
        Uint32 color = 0;

        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        _buffer[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::update()
    {
        SDL_UpdateTexture(_texture, NULL, _buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(_renderer);
        SDL_RenderCopy(_renderer, _texture, NULL, NULL);
        SDL_RenderPresent(_renderer);
    }

    bool Screen::processEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                return false;
        }

        return true;
    }

    void Screen::close()
    {
        delete [] _buffer;
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyTexture(_texture);
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    void Screen::clear()
    {
        memset(_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    }
}
