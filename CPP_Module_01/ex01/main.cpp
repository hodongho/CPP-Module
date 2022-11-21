#include "Zombie.hpp"

#define N 3

int	main()
{
	Zombie	*Horde;

	Horde = zombieHorde(N, "Foo");
	for(int i = 0; i < N; i++)
		Horde[i].announce();
	delete [] Horde;
	return (0);
}
