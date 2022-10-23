#include "algue.hpp"

Algue::Algue(geometrie::Vecteur2<float> position_, std::shared_ptr<Image> image_, geometrie::Vecteur2<float> direction_)
	: Entity{position_, image_, 100,100, 20, 1} {
	direction = direction_;
	speed = 2*log2(geometrie::longueur<float>(direction)+1.0);
}

void Algue::reactCollision(std::shared_ptr<GameObject> other) {
	auto shared = aSuivre.lock();
	if (!shared && other->isPorteur()) {
		aSuivre = other;
	}
}

void Algue::update(int delta) {
	auto shared = aSuivre.lock();
	if (shared != nullptr) {
		position = shared->getPosition();
		return;
	}

	speed-=6.0*delta/1000000.0;

	if (speed <0) {
		speed = 0;
	}
	move();
}
