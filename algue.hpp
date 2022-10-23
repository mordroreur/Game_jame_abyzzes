#ifndef ALGUE_H_INCLUDED
#define ALGUE_H_INCLUDED

#include "Entity.hpp"


class Algue : public Entity {
	public:
    Algue(geometrie::Vecteur2<float> position_, std::shared_ptr<Image> image_, geometrie::Vecteur2<float> direction_);

    void update(int delta) override;
	void reactCollision(std::shared_ptr<GameObject> other) override;

	private:
	std::weak_ptr<GameObject> aSuivre;
};

#endif //ALGUE_H_INCLUDED