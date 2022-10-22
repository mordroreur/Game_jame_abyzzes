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



void updateSpeed(int newSpeed)
{
    speed = newSpeed;
}

void updateDirection(geometrie::Vecteur2<int> newDirection)
{
    direction = newDirection;
}

