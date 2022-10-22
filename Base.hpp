#include "GameObject.hpp"
#include "HealthGainable.hpp"
#include "HealthLosable.hpp"


class Base : public GameObject, HealthGainable, HealthLosable
{

private:
    short int health;

public:
    
    void gainHealth(short int amountGained) override;

    void loseHealth(short int amountLost) override;

    void update(int delta);
};