#include "Brain.hpp"

Brain::Brain()
	:ideas()
{
	std::cout << "Brain is born!" << std::endl;
}

Brain::Brain(Brain& copy)
{
	*this = copy;
	std::cout << "Brain is cloned!" << std::endl;
}

Brain& Brain::operator=(Brain& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 99; i++)
			setIdea(copy.getIdea(i), i);
	}
	return(*this);
}

Brain::~Brain()
{
	std::cout << "Brain is dead" << std::endl;
}

std::string	const& Brain::getIdea(int i) const
{
	if (i < 0 || i > 99)
	{
		std::cerr << "Wrong index!" << std::endl;
		exit(1);
	}
	return(ideas[i]);
}

void	Brain::setIdea(std::string idea, int i)
{
	ideas[i] = idea;
}
