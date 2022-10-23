#include "Player.hpp"
#include <iostream>
#include "geometrie/string.hxx"
#include "algue.hpp"


void Player::gainHealth(short int amountLost) 
{
    health += amountLost;
}


void Player::setInput(Input newInput)
{
  //input = newInput;
    direction = newInput.direction;
	if (newInput.shoot != geometrie::Vecteur2<float>{0, 0}) {
		addObject(std::make_shared<Algue>(position, imageAlgue, newInput.shoot));
	}
}



void Player::update(int delta)
{
    move();
}


