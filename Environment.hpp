#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Entity.hpp"
#include "geometrie/vecteur2.hxx"
#include <cstdlib>
#include <functional>

class Environment : public Entity
{
	std::function<void(GameObject*)> removeObject;
  public:
  Environment(geometrie::Vecteur2<float> p, std::shared_ptr<Image> im, int w, int h, float speed_, short int health_, 
				std::function<void(GameObject*)> removeObject_)
    :Entity(p, im, w, h, speed_, health_), removeObject{removeObject_}
  {
    speed = (1.0*rand())/RAND_MAX * 5.0;
    direction = geometrie::Vecteur2<float>{0.0, 1.0};
    lifeTime = 20000000;
  }
  void update(int delta) override;
  void reactCollision(std::shared_ptr<GameObject> other) override;
  long long lifeTime;
private:

};



#endif
