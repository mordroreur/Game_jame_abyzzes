#include "windowManager.h"
#include "tickManager.h"

void ticks(std::shared_ptr<Ecran> ec, int deltaTime){
  for (auto go : ec->gameObjects) {
    go->update(deltaTime);
  }
  

}
