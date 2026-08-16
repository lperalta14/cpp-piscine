#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Prrr Cat contructed prrr" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    //this->_type = other._type;
    //this->_brain = new Brain(other._brain);
    //for(int i=0; i<100; i++)
    //    this->_brain[i] = other._brain[i]; opcion A;
    this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->_type = other._type;
       *this->_brain = *other._brain;
    }
    return(*this);
}

void Cat::makeSound() const
{
    std::cout << "Miaaauuu " << std::endl;
}

Cat::~Cat()
{
    std::cout << "Prrrr Cat destructed Prrr" << std::endl;
    delete this->_brain;
}