#include "Base.hpp"



void Base::gainHealth(short int amountGained) 
{
    health += amountGained;
}


void Base::loseHealth(short int amountLost) 
{
    health -= amountLost;
}

void Base::update(int delta)
{
    
}
