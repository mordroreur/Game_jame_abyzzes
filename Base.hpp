#include "GameObject.hpp"
#include "HealthGainable.hpp"
#include "HealthLosable.hpp"
#include "geometrie/geometrie.hxx"

class Base : public GameObject, HealthGainable, HealthLosable
{

private:
    short int health;

public:
    

    Base(geometrie::Vecteur2<int> p, std::shared_ptr<Image> im, int w, int h)
    : GameObject(p, im, w, h)
    {
        health = 100;
    };

    void gainHealth(short int amountGained) override;

    void loseHealth(short int amountLost) override;

    void update(int delta);
};