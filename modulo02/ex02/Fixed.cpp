#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

/****************/
/* Constructors */
/****************/
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

/*******************/
/* setters getters */
/*******************/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

/*******************/
/*   conversions   */
/*******************/

float Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

/*******************/
/* OP  Comparisons */
/*******************/

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_fixedPointValue != other._fixedPointValue);
}

/*******************/
/* OP  Aritmetic   */
/*******************/

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;

	result.setRawBits(_fixedPointValue + other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed (result);

	result.setRawBits(_fixedPointValue - other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long	temp;

	temp = (long)_fixedPointValue * (long)other._fixedPointValue;
	result.setRawBits(temp/(1 << _fractionalBits));
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long	temp;

	temp = ((long)_fixedPointValue * (1 << _fractionalBits)) / (long)other._fixedPointValue;
	result.setRawBits(temp);
	return (result);
}

/*******************/
/* OP  Assignments */
/*******************/

Fixed& Fixed::operator++()
{
	_fixedPointValue ++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	old(*this);
	_fixedPointValue ++;
	return (old);
}

Fixed& Fixed::operator--()
{
	_fixedPointValue --;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	old(*this);
	_fixedPointValue --;
	return (old);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

/*******************/
/*   Destructor    */
/*******************/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}