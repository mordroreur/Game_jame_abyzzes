#include "Entity.hpp"
#include "geometrie/string.hxx"
#include <iostream>
#include "logger.h"
	
Entity::Entity(geometrie::Vecteur2<float> position_, std::shared_ptr<Image> image_, int width_, int height_, short int speed_, short int health_)
	:	GameObject{position_, image_, width_, height_}, speed{speed_}, health{health_} {
	  
}


void Entity::loseHealth(short int amountLost)
{
    short int newHealth = health - amountLost;
    health = (newHealth) > 0 ? newHealth : 0;
}

void Entity::move()
{
 	if(direction != geometrie::Vecteur2<float>{0, 0}){
    	position = position + speed * geometrie::normalized(direction);
		log(geometrie::normalized(direction));
		log(std::to_string(speed));
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
