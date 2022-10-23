#include "Enemy.hpp"
#include "GameObject.hpp"
#include "geometrie/string.hxx"
#include "logger.h"
#include <iostream>

Enemy::Enemy(std::vector<std::shared_ptr<GameObject>> cibles_, geometrie::Vecteur2<float> position_, std::shared_ptr<Image> image_, int width_, int height_)
	: Entity{position_, image_, width_, height_, 15, 5}, cibles {cibles_}
{
}

void Enemy::update(int delta)
{
	using namespace geometrie;
	auto cible = cibles.front();/*std::min(cibles.begin(), cibles.end(), [this](auto& a, auto& b) { 
		return longueurCarree<float>((*a)->getPosition() - position) < longueurCarree<float>((*b)->getPosition() - position);
		});
	if (cible == std::end(cibles)) {
		direction.x = 1;
		return;
		}*/
	direction = vecteur2From<float>((cible)->getPosition() - position);
	log("arr");
}
