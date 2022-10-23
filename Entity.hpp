#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.hpp"
#include "Movable.hpp"
#include "HealthLosable.hpp"
#include "geometrie/geometrie.hxx"

class Entity : public GameObject , public Movable , public HealthLosable
{
public:
	
    Entity(geometrie::Vecteur2<float> position, std::shared_ptr<Image> image,
			int width, int height, float speed, short int health);

    geometrie::Vecteur2<float> direction = geometrie::Vecteur2<float>{0.0,0.0};
    float speed;
    short int health;

	bool faceLeft() override {return direction.x<=0;};

    virtual void move() override;
    virtual void updateSpeed(int newSpeed) override;
    virtual void updateDirection(geometrie::Vecteur2<float> direction) override;
    void loseHealth(short int amountLost) override;
    void update(int delta) override;
};


#endif
