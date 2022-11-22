#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& _Fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = _Fixed;
}

Fixed& Fixed::operator=(const Fixed& _Fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &_Fixed)
		fixedPoint = _Fixed.fixedPoint;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedPoint = raw;
}
