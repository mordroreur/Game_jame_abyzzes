#include "windowManager.h"
#include "tickManager.h"
#include <cstdlib>

void gestionCollision(std::shared_ptr<Ecran> ec, int deltaTime) {  
	for (auto oA: ec->gameObjects)
	{
		for (auto oB: ec->gameObjects)
		{
			if (oA != oB) {
				if (oA->collideWith(oB)) {
					oA->reactCollision(oB);
				}
			}
		}
	}
}
int lastSpawn = 0;
void ticks(std::shared_ptr<Ecran> ec, int deltaTime){
  for (auto go : ec->gameObjects) {
	if (go) {
    	go->update(deltaTime);
	}
  }
  if(lastSpawn == 0){
    lastSpawn = (rand()*1.0)/RAND_MAX * 1200 + 60;
    
  }else{
    lastSpawn--;
  }
	gestionCollision(ec, deltaTime);
	ec->supprimerObjets();
}

