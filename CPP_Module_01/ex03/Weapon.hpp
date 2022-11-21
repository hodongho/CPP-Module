#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string _type);
		const std::string	&getType();
		void			 	setType(std::string _type);
};

#endif
