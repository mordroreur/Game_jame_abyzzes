#include "Player.hpp"
#include <iostream>
#include "geometrie/string.hxx"
#include "algue.hpp"
#include "logger.h"

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
	
	std::vector<decltype(algues)::iterator> v;
	for (auto i = algues.begin(); i != algues.end(); ++i) {
		log(std::to_string(*i==other));
		if (*i==other){
			v.push_back(i);
		}
	}

	for (auto i : v) {
		algues.erase(i);
		removeObject(other);
	}
}

void Player::update(int delta)
{
    move();
}


