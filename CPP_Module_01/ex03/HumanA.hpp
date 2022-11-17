#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string	name;
		Weapon		&WeaponA;
	public:
		HumanA(std::string _name, Weapon &_WeaponA);
		std::string const	&getName();
		void				setWeapon(Weapon _WeaponA);
		void				attack();
};
