#include "Animal.hpp"

Animal::Animal(): _type("Developer") 
{
    std::cout << "sakdblSDCBLCBNLSA animal constructed aklbdckjavb" << std::endl;
}

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

std::string Animal::getType() const
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