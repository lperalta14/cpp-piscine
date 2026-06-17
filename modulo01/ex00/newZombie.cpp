#include "Zombie.h"

Zombie* newZombie( std::string name )
{
	Zombie*	zombie = new Zombie();
	zombie->setName( name );
	return zombie;
}