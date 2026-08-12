#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "guuf Dog contructed guuuf" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->_type = other._type;
        *this->_brain = *other._brain;
    }
    return(*this);
}

void Dog::makeSound() const
{
    std::cout << "GUAUUU " << std::endl;
}

Dog::~Dog()
{
    std::cout << "guuf Dog destructed guuuf" << std::endl;
    delete this->_brain;
}