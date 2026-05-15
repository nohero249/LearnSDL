#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
#include "Window.h"
#include "Text.h"

int main(int, char **)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    Window GameWindow;
    Text TextExample{"Hello World", 100.0f};

    bool IsRunning = true;
    SDL_Event Event;
    while (IsRunning)
    {
        // Events       
        while (SDL_PollEvent(&Event))
        { 
            if (Event.type == SDL_EVENT_QUIT) IsRunning = false;
        }
        // Renders
        GameWindow.Render();

        TextExample.Render(GameWindow.GetSurface());

        GameWindow.Update(); 
    }

    TTF_Quit();
    SDL_Quit();
    return 0;
}