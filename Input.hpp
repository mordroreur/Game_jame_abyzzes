#ifndef INPUT_H
#define INPUT_H

#include "geometrie/geometrie.hxx"


struct Input{
  geometrie::Vecteur2<int> direction;
  geometrie::Vecteur2<int> shoot;
  bool power;
};

#endif
