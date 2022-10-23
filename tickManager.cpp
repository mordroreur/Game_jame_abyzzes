#include "windowManager.h"
#include "tickManager.h"
#include <cstdlib>
#include "GameObject.hpp"
#include "Environment.hpp"


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
    int size = (rand()*1.0)/RAND_MAX * 200 + 10;
    int ou = (rand()*1.0)/RAND_MAX * ec->sizex;
    
    auto cailloux = std::make_shared<Environment>(geometrie::Vecteur2<float>{ec->player->direction.x - ec->sizex/2 + ou,ec->player->direction.y - ec->sizey/2}, ec->getImage(NomImage::Caillasse), size,size, 10.0, 20, 
	[ec](GameObject* a){
		auto it = std::find_if(ec->gameObjects.begin(), ec->gameObjects.end(), [a](auto o){
			return o.get() == a;
		});
		if (it != ec->gameObjects.end()) {
			ec->objetsASupprimer.push_back(*it);
		}
		});
    
	ec->gameObjects.push_back(cailloux);
	}else{
		lastSpawn--;
	}

	gestionCollision(ec, deltaTime);
	ec->supprimerObjets();
}

