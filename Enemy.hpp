#ifndef ENEMY_H

#define ENEMY_H


#include "Entity.hpp"

class Enemy: public Entity
{


public:
    Enemy(geometrie::Vecteur2<float> position, std::shared_ptr<Image> image, int wight, int height);
    void update(int delta) override; 
	void add_cible(std::weak_ptr<GameObject> cible);
	void reactCollision(std::shared_ptr<GameObject> other) override;
	void set_player(std::shared_ptr<GameObject> player_);
	bool isPorteur() override {return true;}

private:
	std::vector<std::weak_ptr<GameObject>> cibles;
	std::shared_ptr<GameObject> player;
};


#endif 

