#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.hpp"
#include "Movable.hpp"
#include "HealthLosable.hpp"
#include "geometrie/geometrie.hxx"

class Entity : public GameObject , public Movable , public HealthLosable
{
    geometrie::Vecteur2<int> direction;
    short int speed;
    short int health;
};


#endif