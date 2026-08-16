#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructed" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{}

Ice& Ice::operator=(const Ice& other)
{
    AMateria::operator=(other);
    return(*this);
}

AMateria* Ice::clone() const
{
    Ice *clone = new Ice(*this);
    return (clone);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructed" << std::endl;
}