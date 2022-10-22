#ifndef ITEM_H
#define ITEM_H

#include "GameObject.hpp"


class Item : public GameObject
{

private:
    int type;



public:
    
    Item(geometrie::Vecteur2<int> p, std::shared_ptr<Image> im, int w, int h, int t)
    : GameObject(p, im, w,h)
    {
        type = t;
    }
    int getType();


};


#endif