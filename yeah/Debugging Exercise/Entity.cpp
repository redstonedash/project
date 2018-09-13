#include "Entity.h"



Entity::Entity()
{
	int health = 1;
}


Entity::~Entity()
{
}

bool Entity::isAlive()
{
	return health == 0;
}
