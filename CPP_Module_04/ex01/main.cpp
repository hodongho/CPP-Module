#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "---------------------------------------------" << std::endl << std::endl;

	const WrongAnimal* metaa = new WrongAnimal();
	const WrongAnimal* ii = new WrongCat();

	std::cout << ii->getType() << " " << std::endl;
	ii->makeSound();
	metaa->makeSound();
	return (0);
}
