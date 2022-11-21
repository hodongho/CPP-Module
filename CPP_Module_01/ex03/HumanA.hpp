#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {
	private:
		std::string	name;
		Weapon		&WeaponA;
	public:
		HumanA(std::string _name, Weapon &_WeaponA);
		const std::string	&getName();
		void				setWeapon(Weapon _WeaponA);
		void				attack();
};

#endif
