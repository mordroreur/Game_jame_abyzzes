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

    Player(geometrie::Vecteur2<int> p, std::shared_ptr<Image> im, Input inp ,int w, int h) 
    : Entity(p, im, w, h)
    {
        input = inp;
    }

    void gainHealth(short int amountLost) override;
    void setInput(Input newInput);
    void update(int delta);
};