#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include "image.hpp"
#include <memory>
#include <SDL2/SDL_image.h>
#include "geometrie/geometrie.hxx"


class GameObject
{
private:

protected:

    geometrie::Vecteur2<int> position;
    std::shared_ptr<Image>  canvas;
    SDL_Rect rect;
       
public:
    GameObject(/* args */);
    virtual void render() = 0;
    virtual void update(int delta) = 0;
};

#endif