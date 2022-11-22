#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
		:fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int _fixedPoint)
		:fixedPoint(_fixedPoint)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float _fixedPoint)
		:fixedPoint(_fixedPoint)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		fixedPoint = copy.fixedPoint;
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
	fixedPoint = raw << fractionalBit;
}

float	Fixed::toFloat(void) const
{
	return (0);
}

int	Fixed::toInt(void) const
{
	return (0);
}
