#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string	name;
		Weapon		*WeaponB;
	public:
		HumanB(std::string _name);
		std::string const	&getName();
		void				setWeapon(Weapon &_WeaponB);
		void				attack();
};
