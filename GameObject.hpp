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
    std::shared_ptr<Image>  image;
    int w;
    int h;
       
public:
    GameObject(/* args */);
    void update(int delta);

    std::shared_ptr<Image> getImage();
    SDL_Rect getRect();
};



#endif