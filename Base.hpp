#ifndef BASE_H 
#define BASE_H


#include "GameObject.hpp"
#include "geometrie/geometrie.hxx"
#include "HealthGainable.hpp"
#include "HealthLosable.hpp"



class Base : public GameObject , public HealthGainable, public HealthLosable{

private:
    short int health;
};






#endif
