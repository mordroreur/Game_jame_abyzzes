#include "Entity.hpp"



void Entity::loseHealth(short int amountLost)
{
    short int newHealth = health - amountLost;
    health = (newHealth) > 0 ? newHealth : 0;
}

void Entity::move()
{
    position = position + speed * geometrie::normalized(direction); 
}



virtual void updateSpeed(int newSpeed)
{
    speed = newSpeed;
}

virtual void updateDirection(geometrie::Vecteur2<int> newDirection)
{
    direction = newDirection;
}

