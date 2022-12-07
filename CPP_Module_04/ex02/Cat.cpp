#include "Cat.hpp"

Cat::Cat()
	:catBrain(0)
{
	type  = "Cat";
	std::cout << getType() << " is born!" << std::endl;
	catBrain = new Brain();
}

Cat::Cat(Cat& copy)
	:catBrain(0)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

Cat& Cat::operator=(Cat& copy)
{
	if (this != &copy)
	{
		type  = copy.getType();
		if (catBrain != 0)
			delete catBrain;
		catBrain = new Brain(*copy.catBrain);
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

void	Cat::showIdea() const
{
	catBrain->showIdea();
}

std::string const&	Cat::getIdea(int i) const
{
	return(catBrain->getIdea(i));
}

void	Cat::setIdea(std::string idea)
{
	catBrain->setIdea(idea);
}
