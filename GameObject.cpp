#include "GameObject.hpp"

std::shared_ptr<Image> GameObject::getImage()
{
    return image;
}

SDL_Rect GameObject::getRect()
{
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = w;
    rect.h = h;

    return rect;
}

void update(int delta)
{
    
}