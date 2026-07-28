#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << _name << " Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator called" << std::endl;

	return(*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << _name << " ¿Me la chocáis los 5? ^.^" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}
