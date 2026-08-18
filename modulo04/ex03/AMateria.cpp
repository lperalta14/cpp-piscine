#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type){}


AMateria::AMateria(const AMateria& other) : _type(other._type)
{}

AMateria& AMateria::operator=(const AMateria& other)
{
    (void)other;
    return(*this);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}

std::string const & AMateria::getType() const
{
    return(this->_type);
}

AMateria::~AMateria(){}