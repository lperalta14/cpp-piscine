#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}
Zombie::Zombie() {}

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
	std::cout << _name <<": me remorí boludo" << std::endl;
}