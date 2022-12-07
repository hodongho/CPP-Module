#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
}

Cure::Cure(Cure& copy)
{
	*this = copy;
}

Cure&	Cure::operator=(Cure& copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

Cure::~Cure()
{
}

AMateria*	Cure::clone() const
{
	AMateria* cloneCure = new Cure;
	return (cloneCure);
}
