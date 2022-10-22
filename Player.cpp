#include "Player.hpp"


void Player::gainHealth(short int amountLost) 
{
    health += amountLost;
}


void Player::setInput(Input newInput)
{
    input = newInput;
}



void Player::update(int delta)
{
    move();
}


