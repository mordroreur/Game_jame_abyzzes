#ifndef ENEMY_H

#define ENEMY_H


#include "Entity.hpp"

class Enemy: public Entity
{


public:
    Enemy(std::vector<std::shared_ptr<GameObject>> cibles, geometrie::Vecteur2<float> position, std::shared_ptr<Image> image, int wight, int height);
    void update(int delta) override; 
	void add_cible(std::shared_ptr<GameObject> cible);

private:
	std::vector<std::shared_ptr<GameObject>> cibles;

};


#endif 

