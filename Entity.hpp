#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.hpp"
#include "Movable.hpp"
#include "HealthLosable.hpp"
#include "geometrie/geometrie.hxx"

class Entity : public GameObject , public Movable , public HealthLosable
{
public:


    using  GameObject::GameObject;
    geometrie::Vecteur2<int> direction;
    short int speed;
    short int health;


    virtual void move() override;
    virtual void updateSpeed(int newSpeed) override;
    virtual void updateDirection(geometrie::Vecteur2< int> direction) override;
    void loseHealth(short int amountLost) override;
    void update(int delta);
    


};


#endif