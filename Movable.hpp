#ifndef MOVABLE_H
#define MOVABLE_H

#include "geometrie/geometrie.hxx"

class Movable
{
public:
    virtual void move() = 0;
    virtual void updateSpeed(int newSpeed) = 0;
    virtual void updateDirection(geometrie::Vecteur2< int> direction);
};






#endif