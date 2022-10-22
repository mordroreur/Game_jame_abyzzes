#ifndef ENEMY_H

#define ENEMY_H


#include "Entity.hpp"

class Enemy: public Entity
{


public:

    using Entity::Entity;
    
    void update(int delta); 

};


#endif 

