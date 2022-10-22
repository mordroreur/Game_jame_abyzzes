#include "Player.hpp"
#include <iostream>
#include "geometrie/string.hxx"


void Player::gainHealth(short int amountLost) 
{
    health += amountLost;
}


void Player::setInput(Input newInput)
{
  //input = newInput;
    direction = newInput.direction;
}



void Player::update(int delta)
{
    move();
}


