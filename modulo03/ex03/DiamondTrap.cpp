#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(), FragTrap()
{
	this->_name = other._name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	ClapTrap::operator=(other);

	this->_name = other._name;
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}void attack(const std::string& target);