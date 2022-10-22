#ifndef ITEM_H
#define ITEM_H

#include "GameObject.hpp"


class Item : public GameObject
{

private:
    int type;



public:
    int getType();
};


#endif