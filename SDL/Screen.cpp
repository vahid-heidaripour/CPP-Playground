//
// Created by Vahid Heidaripour on 2019-03-15.
//

#include "Screen.h"

namespace cpp_playground
{
    Screen::Screen() :
            _window(NULL), _renderer(NULL), _texture(NULL), _buffer1(NULL), _buffer2(NULL) {

    }

    bool Screen::init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }

        _window = SDL_CreateWindow("Particle Window",
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                    SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (_window == NULL) {
            SDL_Quit();
            return false;
        }

        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
        _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888,
                                      SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (_renderer == NULL) {
            SDL_DestroyWindow(_window);
            SDL_Quit();
            return false;
        }

        if (_texture == NULL) {
            SDL_DestroyRenderer(_renderer);
            SDL_DestroyWindow(_window);
            SDL_Quit();
            return false;
        }

        _buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        _buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        return true;
    }

    void Screen::clear() {
        memset(_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

        if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return;
        }

        Uint32 color = 0;

        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        _buffer1[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::update() {
        SDL_UpdateTexture(_texture, NULL, _buffer1, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(_renderer);
        SDL_RenderCopy(_renderer, _texture, NULL, NULL);
        SDL_RenderPresent(_renderer);
    }

    bool Screen::processEvents() {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
        }
        return true;
    }

    void Screen::close() {
        delete[] _buffer1;
        delete[] _buffer2;
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyTexture(_texture);
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    void Screen::boxBlur()
    {
        Uint32 *temp = _buffer1;
        _buffer1 = _buffer2;
        _buffer2 = temp;

        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            for (int x = 0; x < SCREEN_WIDTH; x++) {
                int redTotal = 0;
                int greenTotal = 0;
                int blueTotal = 0;

                for (int row = -1; row <= 1; row++) {
                    for (int col = -1; col <= 1; col++) {
                        int currentX = x + col;
                        int currentY = y + row;

                        if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
                            Uint32 color = _buffer2[currentY * SCREEN_WIDTH + currentX];

                            Uint8 red = color >> 24;
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;

                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;
                        }
                    }
                }

                Uint8 red = redTotal / 9;
                Uint8 green = greenTotal / 9;
                Uint8 blue = blueTotal / 9;

                setPixel(x, y, red, green, blue);
            }
        }
    }
}
