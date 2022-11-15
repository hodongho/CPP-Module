#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		std::string const &getType();
		std::string setType(std::string _type);
};

#endif
