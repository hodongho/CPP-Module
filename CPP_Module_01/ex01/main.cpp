#include "Zombie.hpp"

int	main()
{
	Zombie	*Horde;

	Horde = zombieHorde(4, "Foo");
	for(int i = 0; i < 4; i++)
		Horde[i].announce();
	delete [] Horde;
	return (0);
}
