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
	(void)copy;
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

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
