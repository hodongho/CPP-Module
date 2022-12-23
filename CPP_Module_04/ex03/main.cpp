#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

		std::cout << std::endl;
		system("leaks -quiet a.out");
	}
	std::cout << "-----------------------------------------" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource;
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());

		ICharacter* me = new Character("me");
		AMateria* floor[3];

		floor[0] = src->createMateria("ice");
		me->equip(floor[0]);
		floor[1] = src->createMateria("cure");
		me->equip(floor[1]);
		floor[2] = src->createMateria("cure");
		me->equip(floor[2]);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		me->unequip(0);
		me->unequip(1);
		me->unequip(2);

		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);

		delete bob;
		delete me;
		delete src;
		for (int i = 0; i < 3; i++)
			delete floor[i];

		std::cout << std::endl;
		system("leaks -quiet a.out");
	}
	return 0;
}
