#pragma once
#include <SDL3/SDL.h>
#include "Rectangle.h"
#include "Button.h"
#include "SettingsMenu.h"

class UI
{
public:
    void Render(SDL_Surface* Surface) const
    {
        SettingsButton.Render(Surface);
        Settings.Render(Surface);
    }

    void HandleEvent(SDL_Event& E)
    {
         SettingsButton.HandleEvent(E);
         Settings.HandleEvent(E);
    }

private:
    Button SettingsButton{{50, 50, 150, 50}};
    SettingsMenu Settings;
};