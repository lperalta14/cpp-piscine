#include "Zombie.h"

Zombie::Zombie(){}

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name <<": iuuuh je morte" << std::endl;
}
