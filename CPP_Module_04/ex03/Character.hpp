#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string	name;
		AMateria*	Materia[4];
	public:
		Character();
		Character(std::string name);
		Character(Character& copy);

		Character& operator=(Character& copy);

		virtual	~Character();

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
