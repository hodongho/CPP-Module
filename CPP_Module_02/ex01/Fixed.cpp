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
		:fixedPoint(_fixedPoint << fractionalBit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float _fixedPoint)
		:fixedPoint(roundf(_fixedPoint * (1 << fractionalBit)))
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
	fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPoint) / (1 << fractionalBit));
}

int	Fixed::toInt(void) const
{
	return (fixedPoint >> fractionalBit);
}

std::ostream& operator<<(std::ostream &out, const Fixed& _Fixed)
{
	out << _Fixed.toFloat();
	return (out);
}
