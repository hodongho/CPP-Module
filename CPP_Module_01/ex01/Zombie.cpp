#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie is born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "The " << getName() << " is dead" << std::endl;
}

const std::string &Zombie::getName()
{
	return (name);
}

void	Zombie::setName( std::string _name)
{
	name = _name;
}

void	Zombie::announce( void )
{
	std::cout << getName() << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
