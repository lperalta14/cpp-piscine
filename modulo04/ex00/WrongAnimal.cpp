#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("demogorgon") {}

WrongAnimal::WrongAnimal(const WrongAnimal& other) 
{
    this->_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other)
        this->_type = other._type;
    return(*this);
}

std::string WrongAnimal::getType()
{
    return(this->_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "gruaaaagh " << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl; 
}