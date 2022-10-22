#include "GameObject.hpp"
#include "Entity.hpp"
#include "HealthGainable.hpp"
#include "Input.hpp"

class Player : public GameObject , public Entity, public HealthGainable
{
private:
    Input input;

public:
    void gainHealth(short int amountLost) override;
    void setInput(Input newInput);
    void update(int delta);
};