#include "Entity.hpp"
#include "geometrie/string.hxx"
#include <iostream>


void Entity::loseHealth(short int amountLost)
{
    short int newHealth = health - amountLost;
    health = (newHealth) > 0 ? newHealth : 0;
}

void Entity::move()
{
  if(direction != geometrie::Vecteur2<float>{0, 0}){
    position = position + speed * geometrie::normalized(direction);
   }
  
  
}



void Entity::updateSpeed(int newSpeed)
{
    speed = newSpeed;
}

void Entity::updateDirection(geometrie::Vecteur2<float> newDirection)
{
    direction = newDirection;
}


void Entity::update(int delta)
{
    move();
}
