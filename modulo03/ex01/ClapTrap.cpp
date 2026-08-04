#include "ClapTrap.hpp"

//"ClapTrap <name> attacks <target>, causing <damage> points of damage!"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	: _name(other._name), _hitPoints(other._hitPoints), 
	  _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " no pueo :(, no tengo " 
			<< (_hitPoints == 0 ? "hit points" : "energy points") << "!" << std::endl;
	else
		{
			this->_energyPoints--;
			std::cout << "ClapTrap " << _name << " chupate esa " << target 
				<< "! causando " << _attackDamage << " puntos de dolor!" << std::endl;
		}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < this->_hitPoints)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " AH! ESO DUELE. Me has quitado " << amount 
		<< " puntos de dolor! Le quedan " << _hitPoints << " HP!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		std::cout << "ClapTrap " << _name 
			 << " estoy mueltito, no me puedo curar :(" << std::endl;
	else
		{
			this->_hitPoints += amount;
			this->_energyPoints --;
			std::cout << "Toma! Toma! ClapTrap " << _name << " se ha curado " 
				<< amount << " puntos! HP actual: " << _hitPoints << "!" << std::endl;
		} 
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

