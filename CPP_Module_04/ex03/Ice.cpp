#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
}

Ice::Ice(Ice& copy)
{
	*this = copy;
}

Ice&	Ice::operator=(Ice& copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

Ice::~Ice()
{
}

AMateria*	Ice::clone() const
{
	AMateria* cloneIce = new Ice;
	return (cloneIce);
}
