#pragma once 
#include <SDL3/SDL.h>

class Rectangle
{
public:
    Rectangle(const SDL_Rect& Rect) : mRect{Rect} { }
    
    virtual ~Rectangle() = default;

    virtual void Render(SDL_Surface* Surface) const
    {
        auto [r, g, b, a]{isPointerHovering ? HoverColor : mColor};
        const auto* Fmt = SDL_GetPixelFormatDetails(Surface->format);

        SDL_FillSurfaceRect(Surface, &mRect, SDL_MapRGB(Fmt, nullptr, r, g, b));
    }

    virtual void OnMouseEnter() { }
    virtual void OnMouseExit() { }
    virtual void OnLeftClick() { }

    void HandleEvent(SDL_Event& E)
    {
        if (E.type == SDL_EVENT_MOUSE_MOTION)
        {
            bool wasPointerHovering{isPointerHovering};
            isPointerHovering = isWithinRect((int)E.motion.x, (int)E.motion.y);

            if (!wasPointerHovering && isPointerHovering) OnMouseEnter();
            else if (wasPointerHovering && !isPointerHovering) OnMouseExit();
        }
        else if (E.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) 
        {
            isPointerHovering = false;
            if (isPointerHovering) OnMouseExit();
            isPointerHovering = false;
        }
        else if (E.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (isPointerHovering && E.button.button == SDL_BUTTON_LEFT) OnLeftClick();
        }
    }

    void SetColor(const SDL_Color& Color) { mColor = Color; }

    SDL_Color GetColor() const { return mColor; }

    void SetHoverColor(const SDL_Color& NewColor)
    {
        HoverColor = NewColor;
    }

    SDL_Color GetHoverColor() const { return HoverColor; }

private:
    SDL_Rect mRect;
    SDL_Color mColor{255, 0, 0, 255};
    SDL_Color HoverColor{0, 0, 255, 255};

    bool isWithinRect(int x, int y)
    {
        if (x < mRect.x) return false;
        if (x > mRect.x + mRect.w) return false;
        if (y < mRect.y) return false;
        if (y > mRect.y + mRect.h) return false;

        return true;
    }

protected:
    bool isPointerHovering{false};
};