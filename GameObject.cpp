#include "GameObject.hpp"
#include "geometrie/string.hxx"



GameObject::GameObject(geometrie::Vecteur2<float> p, std::shared_ptr<Image> im, int w, int h)
	:position {p}, image{im}, width{w}, height{h}
{
}

std::shared_ptr<Image> GameObject::getImage()
{
    return image;
}

SDL_Rect GameObject::getRect()
{
    return SDL_Rect{static_cast<int>(position.x-width/2.0), static_cast<int>(position.y-height/2.0), width, height};
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


geometrie::Vecteur2<float> GameObject::getPosition() { return position; };

void GameObject::setPosition(geometrie::Vecteur2<float> newVec) {
  position = newVec;
};


