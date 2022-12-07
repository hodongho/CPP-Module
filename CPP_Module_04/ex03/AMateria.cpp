#include "AMateria.hpp"

AMateria::AMateria()
	:type("")
{
}

AMateria::AMateria(AMateria& copy)
	:type(copy.getType())
{
}

AMateria::AMateria(std::string const& type)
	:type(type)
{
}

AMateria& AMateria::operator=(AMateria& copy)
{
	if (this != &copy)
		type = copy.getType();
	return (*this);
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	if (type == "ice")
	{
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	}
	else if (type == "cure")
	{
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	}
}
