#include "Zombie.hpp"

int	main()
{
	Zombie	*Zombie;

	Zombie = newZombie("Foo");
	Zombie->announce();
	randomChump("Bar");

	delete Zombie;
	return (0);
}
