#include "Environment.hpp"
#include "geometrie/string.hxx"
#include <iostream>

void Environment::update(int delat) { move(); }

void Environment::reactCollision(std::shared_ptr<GameObject> other){
  std::cout << geometrie::toString(other->getPosition()) << std::endl;
}

