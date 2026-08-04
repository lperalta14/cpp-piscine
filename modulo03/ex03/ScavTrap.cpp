#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Scavtrap " << _name << " Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;

	return(*this);
}

void 	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " no pueo :(, no tengo " 
			<< (_hitPoints == 0 ? "hit points" : "energy points") << "!" << std::endl;
	else
		{
			this->_energyPoints--;
			std::cout << "ScavTrap " << _name << " chupate esa " << target 
				<< "! causando " << _attackDamage << " puntos de dolor!" << std::endl;
		}
}

void ScavTrap::guardGate()
{
	std::cout << _name << " ScavTrap ha entrado en modo guardian y se ha hecho una bolita" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}
