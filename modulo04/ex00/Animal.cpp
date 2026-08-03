#include "Animal.hpp"

Animal::Animal(): _type("Developer") {}

Animal::Animal(const Animal& other) 
{
    this->_type = other._type;
}

Animal& Animal::operator=(const Animal& other)
{
    if(this != &other)
        this->_type = other._type;
    return(*this);
}

std::string Animal::getType()
{
    return(this->_type);
}

void Animal::makeSound() const
{
    std::cout << "grrr " << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl; 
}