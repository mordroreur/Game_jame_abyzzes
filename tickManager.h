#ifndef __GARDIEN_TICK_MANAGER_H__
#define __GARDIEN_TICK_MANAGER_H__

#include "windowManager.h"
#include "geometrie/geometrie.hxx"

struct{
  geometrie::Vecteur2<int> direction;
  geometrie::Vecteur2<int> shoot;
  bool power;
}input;

void ticks(std::shared_ptr<Ecran> ec, int deltaTime);

#endif /* __GARDIEN_TICK_MANAGER_H__ */
