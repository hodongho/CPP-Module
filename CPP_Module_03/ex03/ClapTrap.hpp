#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hitPoint;
		unsigned int	_energyPoint;
		unsigned int	_attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& copy);

		ClapTrap& operator=(const ClapTrap& copy);

		~ClapTrap();

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		getName() const;
		unsigned int	getHitPoint() const;
		unsigned int	getEnergyPoint() const;
		unsigned int	getAttackDamage() const;

	protected:
		void			setName(const std::string name);
		void			setHitPoint(const unsigned int hitPoint);
		void			setEnergyPoint(const unsigned int energyPoint);
		void			setAttackDamage(const unsigned int attackDamage);
};

#endif
