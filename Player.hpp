#include "GameObject.hpp"
#include "Entity.hpp"
#include "HealthGainable.hpp"
#include "Input.hpp"
#include "geometrie/geometrie.hxx"

class Player : public Entity, public HealthGainable
{
private:
    Input input;

public:

    Player(geometrie::Vecteur2<float> p, std::shared_ptr<Image> im, int w, int h) 
    : Entity(p, im, w, h), input{}
    {
      speed = 1;
    }

    void gainHealth(short int amountLost) override;
    void setInput(Input newInput);
    void update(int delta);
};
