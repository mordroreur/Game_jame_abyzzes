#include "Enemy.hpp"
#include "GameObject.hpp"
#include "geometrie/string.hxx"
#include "logger.h"
#include <iostream>
#include <algorithm>

Enemy::Enemy(geometrie::Vecteur2<float> position_, std::shared_ptr<Image> image_, int width_, int height_)
	: Entity{position_, image_, width_, height_, 5, 5}
{
}

void Enemy::set_player(std::shared_ptr<GameObject> player_) {
	player = player_;
}

void Enemy::add_cible(std::weak_ptr<GameObject> cible) {
	cibles.push_back(cible);
}

void Enemy::reactCollision(std::shared_ptr<GameObject> other) {
	auto last = std::remove_if(cibles.begin(), cibles.end(), [other](auto c) {
		auto l=c.lock();
		return l==nullptr || l == other;
	});

	cibles.erase(last, cibles.end());
}

void Enemy::update(int delta)
{
	using namespace geometrie;

	auto last = std::remove_if(cibles.begin(), cibles.end(), [](auto c){return c.expired();});
	cibles.erase(last, cibles.end());

	if (cibles.empty()) {
		if (!player) return;
		direction = player->getPosition() - position;
	}
	else {
		auto cibleShared = cibles.back().lock();
		if (cibleShared) {
			direction = cibleShared->getPosition() - position;
		}
	}
	
	move();
}
