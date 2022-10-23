#include "GameObject.hpp"


GameObject::GameObject(geometrie::Vecteur2<int> p, std::shared_ptr<Image> im, int w, int h)
{
    position = p;
    image = im;
    width = w;
    height = h;
}

std::shared_ptr<Image> GameObject::getImage()
{
    return image;
}

SDL_Rect GameObject::getRect()
{
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = width;
    rect.h = height;

    return rect;
}

SDL_bool GameObject::collideWith(std::shared_ptr<GameObject> other)
{
    SDL_bool result = SDL_FALSE;

    if (other != NULL)
    {
        SDL_Rect objectRect = getRect();
        SDL_Rect otherRect = other->getRect();
        result = SDL_HasIntersection(&objectRect,&otherRect);
    }
    return result;
}

