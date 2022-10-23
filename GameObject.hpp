#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include "image/image.hpp"
#include <memory>
#include <SDL2/SDL_image.h>
#include "geometrie/geometrie.hxx"


class GameObject
{
protected:

    geometrie::Vecteur2<float> position;
    std::shared_ptr<Image>  image;
    int width;
    int height;
    
public:
    GameObject(geometrie::Vecteur2<float> p, std::shared_ptr<Image> im, int w, int h);
    virtual void update(int delta) = 0;

    SDL_bool collideWith(std::shared_ptr<GameObject> other);

    std::shared_ptr<Image> getImage();
    SDL_Rect getRect();
  geometrie::Vecteur2<float> getPosition(); 
	
};



#endif
