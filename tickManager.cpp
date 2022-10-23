#include "windowManager.h"
#include "tickManager.h"

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

void ticks(std::shared_ptr<Ecran> ec, int deltaTime){
  for (auto go : ec->gameObjects) {
	if (go) {
    	go->update(deltaTime);
	}
  }

	gestionCollision(ec, deltaTime);
	ec->supprimerObjets();
}

