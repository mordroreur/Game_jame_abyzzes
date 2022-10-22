#ifndef GAMEOBJECT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define GAMEOBJECT_H

class GameObject
{
private:
    
public:
    GameObject(/* args */);
    ~GameObject();
    virtual void render() = 0;
    virtual void update(int delta) = 0;
};

#endif