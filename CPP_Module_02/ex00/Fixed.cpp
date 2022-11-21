#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	FixedPointVal = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed&)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& _Fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (FixedPointVal);
}

void	Fixed::setRawBits(int const raw)
{
	FixedPointVal = raw;
}
