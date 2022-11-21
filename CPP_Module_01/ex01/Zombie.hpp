#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		const std::string	&getName();
		void				setName( std::string _name);
		void				announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif
