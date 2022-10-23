#include "GameObject.hpp"
#include "Entity.hpp"
#include "HealthGainable.hpp"
#include "Input.hpp"
#include "geometrie/geometrie.hxx"
#include <functional>
#include <vector>

class Player : public Entity, public HealthGainable
{
private:
    Input input;
	std::function<void(std::shared_ptr<GameObject>)> addObject;
	std::function<void(std::shared_ptr<GameObject>)> removeObject;
	std::shared_ptr<Image> imageAlgue;
	std::vector<std::shared_ptr<GameObject>> algues;
public:

    Player(std::function<void(std::shared_ptr<GameObject>)> addObject_,
				std::function<void(std::shared_ptr<GameObject>)> removeObject_,
				std::shared_ptr<Image> imageAlgue_,
					 geometrie::Vecteur2<float> p, std::shared_ptr<Image> im, int w, int h) 
    : Entity(p, im, w, h, 12, 100), input{}, addObject{addObject_}, imageAlgue{imageAlgue_}, removeObject {removeObject_}
    {
    }

    void gainHealth(short int amountLost) override;
    void setInput(Input newInput);
    void update(int delta);
	
	void reactCollision(std::shared_ptr<GameObject> other) override;
};
