#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include "Window.h"

void HandleEvent(SDL_MouseMotionEvent& Event, Window& GameWindow)
{
    float DistanceFromLeft{Event.x};
    float DistanceFromTop{Event.y};

    std::cout   << "Mouse Motion Detected - " 
                << "x: " << DistanceFromLeft
                << ",\ty: " << DistanceFromTop << '\n' ;
}

void HandleEvent(SDL_MouseButtonEvent& Event)
{
    if (Event.button == SDL_BUTTON_LEFT && Event.down && Event.clicks >=2) std::cout << "Mouse Left Button Double-Clicked\n";
    else if (Event.button == SDL_BUTTON_LEFT && Event.down && Event.clicks <2) std::cout << "Mouse Left Button Clicked\n";
    else if (Event.type == SDL_EVENT_MOUSE_BUTTON_UP && Event.button == SDL_BUTTON_LEFT) std::cout << "Mouse Left Button Released\n";

    if (Event.button == SDL_BUTTON_RIGHT && Event.down && Event.clicks >=2) std::cout << "Mouse Right Button Double-Clicked\n";
    else if (Event.button == SDL_BUTTON_RIGHT && Event.down && Event.clicks <2) std::cout << "Mouse Right Button Clicked\n";
    else if (Event.type == SDL_EVENT_MOUSE_BUTTON_UP && Event.button == SDL_BUTTON_RIGHT) std::cout << "Mouse Right Button Released\n";
}

int main(int, char **)
{
    SDL_Init(SDL_INIT_VIDEO);
    Window GameWindow;

    bool IsRunning = true;
    SDL_Event Event;
    while (IsRunning)
    {
        // Events       
        while (SDL_PollEvent(&Event))
        { 
            if (Event.type == SDL_EVENT_MOUSE_MOTION) HandleEvent(Event.motion, GameWindow); 
            if (Event.type == SDL_EVENT_MOUSE_BUTTON_UP || SDL_EVENT_MOUSE_BUTTON_DOWN) HandleEvent(Event.button);
            
            if (Event.type == SDL_EVENT_QUIT) IsRunning = false;
        }

        // Renders
        GameWindow.Render();
        GameWindow.Update();
    }

    SDL_Quit();
    return 0;
}