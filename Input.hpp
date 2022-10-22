#ifndef INPUT_H
#define INPUT_H

#include "geometrie/geometrie.hxx"


struct Input{
  geometrie::Vecteur2<float> direction = geometrie::Vecteur2<float>{0,0};
  geometrie::Vecteur2<float> shoot = geometrie::Vecteur2<float>{0,0};
  bool power = false;
};

#endif
