#ifndef INPUT_H
#define INPUT_H

#include "geometrie/geometrie.hxx"


struct Input{
  geometrie::Vecteur2<int> direction = geometrie::Vecteur2<int>{0,0};
  geometrie::Vecteur2<int> shoot = geometrie::Vecteur2<int>{0,0};
  bool power = false;
};

#endif
