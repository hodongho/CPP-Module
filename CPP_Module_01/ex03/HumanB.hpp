#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {
	private:
		std::string	name;
		Weapon		*WeaponB;
	public:
		HumanB(std::string _name);
		const std::string 	&getName();
		void				setWeapon(Weapon &_WeaponB);
		void				attack();
};

#endif
