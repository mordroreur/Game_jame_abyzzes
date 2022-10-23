#include "Environment.hpp"
#include "geometrie/string.hxx"
#include <iostream>

void Environment::update(int delat) { move(); }

void Environment::reactCollision(std::shared_ptr<GameObject> other){
  //std::cout << geometrie::toString(other->getPosition()) << std::endl;
  geometrie::Vecteur2<float> vec = other->getPosition();
  if(position.x-height/4 < vec.x){
    vec.x = vec.x+10;
  }else if(position.x+height/4 > vec.x){
    vec.x = vec.x-10;
  }

  if(position.y-width/4 < vec.y){
    vec.y = vec.y+10;
  }else if(position.y+width/4 > vec.y){
    vec.y = vec.y-10;
  }
  other->setPosition(vec);
}

