#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    std::cout << "Prrr Cat contructed prrr" << std::endl;
}

Cat::Cat(const Cat& other)
{
    this->_type = other._type;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        this->_type = other._type;
    return(*this);
}

void Cat::makeSound() const
{
    std::cout << "Miaaauuu " << std::endl;
}

Cat::~Cat()
{
    std::cout << "Prrrr Cat destructed Prrr" << std::endl;
}