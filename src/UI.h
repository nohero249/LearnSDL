#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include <memory>
#include "Rectangle.h"

class UI
{
public:
    void Render(SDL_Surface* Surface) const
    {
        A.Render(Surface);
        B.Render(Surface);
    }

    void HandleEvent(SDL_Event& E)
    {
        A.HandleEvent(E);
        B.HandleEvent(E);
    }

private:
    Rectangle A{SDL_Rect{50, 50, 50, 50}};
    Rectangle B{SDL_Rect{150, 50, 50, 50}};
};