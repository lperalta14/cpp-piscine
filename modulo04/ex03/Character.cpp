#include "Character.hpp"

Character::Character(const std::string& name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = 0;
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i] != 0)
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i] != 0)
                delete this->_inventory[i];
            if (other._inventory[i] != 0)
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = 0;
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] != 0)
            delete this->_inventory[i];
    }
}

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == 0)
        {
            this->_inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    if (this->_inventory[idx] == 0)
        return;
    this->_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (this->_inventory[idx] == 0)
        return;
    this->_inventory[idx]->use(target);
}