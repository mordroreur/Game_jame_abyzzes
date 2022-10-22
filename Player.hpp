#include "GameObject.hpp"
#include "Entity.hpp"
#include "HealthLosable.hpp"


class Player : public GameObject , public Entity, public HealthLosable
{

};