#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::string dog = "My type is Dog";
	std::string cat = "My type is Cat";

	delete j;
	delete i;

	std::cout << std::endl << "---------------------------------------------" << std::endl << std::endl;
	return (0);
}
