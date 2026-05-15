#pragma once
#include <SDL3/SDL.h>

class Window
{
public:
    Window()
    {
        SDLWindow = SDL_CreateWindow(
            "Learn SDL",
            GetWidth(),
            GetHeight(), 
            0);
    }

    SDL_Surface *GetSurface() const
    {
        return SDL_GetWindowSurface(SDLWindow);
    }

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    ~Window()
    {
        if (SDLWindow && SDL_WasInit(SDL_INIT_VIDEO))
        {
            SDL_DestroyWindow(SDLWindow);
        }
    }

    void Render()
    {
        const auto *Fmt = SDL_GetPixelFormatDetails(
            GetSurface()->format);

        SDL_FillSurfaceRect(
            GetSurface(),
            nullptr,
            SDL_MapRGB(Fmt, nullptr, 50, 50, 50));
    }

    void Update()
    {
        SDL_UpdateWindowSurface(SDLWindow);
    }

    int GetWidth() const { return WindowWidth; }
    int GetHeight() const { return WindowHeight; }

private: 
    const int WindowWidth {800};
    const int WindowHeight {300};
    SDL_Window *SDLWindow{nullptr};
};