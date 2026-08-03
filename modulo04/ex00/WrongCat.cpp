#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "Cat";
    std::cout << "Prrr Cat contructed prrr" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    this->_type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        this->_type = other._type;
    return(*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Miaaauuu " << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Prrrr Cat destructed Prrr" << std::endl;
}