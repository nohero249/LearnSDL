#pragma once
#include <SDL3/SDL.h>
#include <string>

#include "Rectangle.h"
#include "UserEvents.h"

class Button : public Rectangle
{
public:
    Button(const SDL_Rect& Rect) : Rectangle{Rect}
    { 
        SetColor({255,165, 0, 255});
    }

    void HandleEvent(SDL_Event& E)
    {
        Rectangle::HandleEvent(E);
        if (E.type == UserEvents::CLOSE_SETTINGS) isSettingsOpen = false;
        else if (E.type == UserEvents::OPEN_SETTINGS) isSettingsOpen = true;
    }

    void OnLeftClick() override
    {
        SDL_Event Event{ .type = isSettingsOpen ?  UserEvents::CLOSE_SETTINGS : UserEvents::OPEN_SETTINGS };

        if (Event.type == UserEvents::OPEN_SETTINGS) Event.user.data1 = this;

        SDL_PushEvent(&Event);
    }

    UserEvents::SettingsConfig GetConfig() { return Config; }

    std::string GetLocation() { return "The main menu"; }

private:
    UserEvents::SettingsConfig Config
    {
        UserEvents::SettingsPage::GAMEPLAY, 50, 100
    };

    bool isSettingsOpen{false};
};