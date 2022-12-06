#include "Cat.hpp"

Cat::Cat()
{
	type  = "Cat";
	catBrain = new Brain();
	std::cout << getType() << " is born!" << std::endl;
}

Cat::Cat(Cat& copy)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

Cat& Cat::operator=(Cat& copy)
{
	if (this != &copy)
	{
		type  = copy.getType();
		for (int i = 0; i < 99; i++)
			catBrain->setIdea(copy.catBrain->getIdea(i), i);
	}
	return (*this);
}

Cat::~Cat()
{
	delete	catBrain;
	std::cout << getType() << " is dead!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string const&	Cat::getIdea(int i) const
{
	return(catBrain->getIdea(i));
}

void	Cat::setIdea(std::string idea, int i)
{
	catBrain->setIdea(idea, i);
}
