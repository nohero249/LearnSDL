#pragma once
#include <SDL3/SDL.h>
#include <string>

namespace Paths {
    std::string BASEPATH{SDL_GetBasePath()};

    std::string FONT_PATH{"/Users/nikolajkoladic/projects/CPP/LearnSDL/assets/fonts/Roboto/static/Roboto-Medium.ttf"};
}