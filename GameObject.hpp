#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include "image/image.hpp"
#include <memory>
#include <SDL2/SDL_image.h>
#include "geometrie/geometrie.hxx"


class GameObject
{
private:

protected:

    geometrie::Vecteur2<int> position;
    std::shared_ptr<Image>  image;
    int width;
    int height;
       
public:
    GameObject(geometrie::Vecteur2<int> p, std::shared_ptr<Image> im, int w, int h);
    virtual void update(int delta) = 0;

    std::shared_ptr<Image> getImage();
    SDL_Rect getRect();
};



#endif
