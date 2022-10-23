#include "algue.hpp"

Algue::Algue(geometrie::Vecteur2<float> position_, std::shared_ptr<Image> image_, geometrie::Vecteur2<float> direction_)
	: Entity{position_, image_, 100,100, 10, 1} {
	direction = direction_;
	speed = log2(geometrie::longueur<float>(direction)+1.0);
}

void Algue::update(int delta) {

	speed-=delta/1000000.0;
	if (speed <0) {
		speed = 0;
	}
	move();
}
