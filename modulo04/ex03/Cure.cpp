#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("Cure")
{
    std::cout << "Cure constructed" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{}

Cure& Cure::operator=(const Cure& other)
{
    AMateria::operator=(other);
    return(*this);
}

AMateria* Cure::clone() const
{
    Cure *clone = new Cure(*this);
    return (clone);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructed" << std::endl;
}