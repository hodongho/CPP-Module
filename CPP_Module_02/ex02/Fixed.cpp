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

//Comparison//

bool Fixed::operator>(const Fixed& _Fixed) const
{
	return (this->getRawBits() > _Fixed.getRawBits());
}

bool Fixed::operator<(const Fixed& _Fixed) const
{
	return (this->getRawBits() < _Fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& _Fixed) const
{
	return (this->getRawBits() >= _Fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& _Fixed) const
{
	return (this->getRawBits() <= _Fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& _Fixed) const
{
	return (this->getRawBits() == _Fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed& _Fixed) const
{
	return (this->getRawBits() != _Fixed.getRawBits());
}

//Arithmetic//

Fixed	Fixed::operator+(const Fixed& _Fixed) const
{
	return (Fixed(this->toFloat() + _Fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& _Fixed) const
{
	return (Fixed(this->toFloat() - _Fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& _Fixed) const
{
	return (Fixed(this->toFloat() * _Fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& _Fixed) const
{
	return (Fixed(this->toFloat() / _Fixed.toFloat()));
}

//Increase and Decrease//
Fixed&	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);
	++*this;
	return (ret);
}

Fixed&	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);
	--*this;
	return (ret);
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

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	std::cout << "This is original min" << std::endl;
	return (f1 < f2 ? f1 : f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	std::cout << "This is const min" << std::endl;
	return (f1 < f2 ? f1 : f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	std::cout << "This is original max" << std::endl;
	return (f1 > f2 ? f1 : f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	std::cout << "This is const max" << std::endl;
	return (f1 > f2 ? f1 : f2);
}


std::ostream& operator<<(std::ostream &out, const Fixed& _Fixed)
{
	out << _Fixed.toFloat();
	return (out);
}
