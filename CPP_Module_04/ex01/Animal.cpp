#include "Animal.hpp"

Animal::Animal()
	:type("Animal")
{
	std::cout << getType() << " is born!" << std::endl;
}

Animal::Animal(Animal& copy)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

Animal& Animal::operator=(Animal& copy)
{
	if (this != &copy)
	{
		type = copy.getType();
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << getType() << " is dead!" << std::endl;
}

std::string	const& Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "???" << std::endl;
}
