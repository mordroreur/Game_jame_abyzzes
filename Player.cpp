#include "Player.hpp"
#include <iostream>
#include "geometrie/string.hxx"
#include "algue.hpp"
#include <algorithm>


void Player::gainHealth(short int amountLost) 
{
    health += amountLost;
}


void Player::setInput(Input newInput)
{
  //input = newInput;
    direction = newInput.direction;
	if (newInput.shoot != geometrie::Vecteur2<float>{0, 0}) {
		auto algue = std::make_shared<Algue>(position+ geometrie::normalized(newInput.shoot) * 200.0, imageAlgue, newInput.shoot);
		algues.push_back(algue);
		addObject(algue);
	}
}

void Player::reactCollision(std::shared_ptr<GameObject> other) {
	auto sizeBefore = algues.size();
	
	auto last = std::remove(algues.begin(), algues.end(), other);
	algues.erase(last, std::end(algues));
	if (algues.size() < sizeBefore) {
		removeObject(other);
	}
}

void Player::update(int delta)
{
    move();
}


