#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	setType("WrongCat");
	std::cout << getType() << " is born!" << std::endl;
}

WrongCat::WrongCat(WrongCat& copy)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& copy)
{
	if (this != &copy)
		setType(copy.getType());
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << getType() << " is dead!" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

