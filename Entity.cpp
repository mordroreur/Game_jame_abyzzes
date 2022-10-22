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



void Entity::updateSpeed(int newSpeed)
{
    speed = newSpeed;
}

void Entity::updateDirection(geometrie::Vecteur2<int> newDirection)
{
    direction = newDirection;
}


void Entity::update(int delta)
{
    move();
}