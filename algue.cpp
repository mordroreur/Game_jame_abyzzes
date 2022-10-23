#include "algue.hpp"

Algue::Algue(geometrie::Vecteur2<float> position_, std::shared_ptr<Image> image_, geometrie::Vecteur2<float> direction_)
	: Entity{position_, image_, 100,100, 10, 1} {
	direction = direction_;
	speed = log2(geometrie::longueur<float>(direction)+1.0);
}

void Algue::reactCollision(std::shared_ptr<GameObject> other) {
	if (aSuivre == nullptr) {
		aSuivre = other;
	}
}

void Algue::update(int delta) {
	if (aSuivre != nullptr) {
		position = aSuivre->getPosition();
		return;
	}

	speed-=delta/1000000.0;
	if (speed <0) {
		speed = 0;
	}
	move();
}
