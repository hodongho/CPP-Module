#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie is born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "The " << name << " is dead" << std::endl;
}

std::string	Zombie::getName()
{
	return (name);
}

void	Zombie::SetName( std::string _name)
{
	name = _name;
}

void	Zombie::announce( void )
{
	std::cout << getName() << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
