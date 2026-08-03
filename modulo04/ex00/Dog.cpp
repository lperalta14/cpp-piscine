#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    std::cout << "guuf Dog contructed guuuf" << std::endl;
}

Dog::Dog(const Dog& other)
{
    this->_type = other._type;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        this->_type = other._type;
    return(*this);
}

void Dog::makeSound() const
{
    std::cout << "GUAUUU " << std::endl;
}

Dog::~Dog()
{
    std::cout << "guuf Dog destructed guuuf" << std::endl;
}