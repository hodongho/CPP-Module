#include "AAnimal.hpp"

AAnimal::AAnimal()
	:type("AAnimal")
{
	std::cout << getType() << " is born!" << std::endl;
}

AAnimal::AAnimal(AAnimal& copy)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal& copy)
{
	if (this != &copy)
	{
		type = copy.getType();
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << getType() << " is dead!" << std::endl;
}

std::string	const& AAnimal::getType() const
{
	return (type);
}
