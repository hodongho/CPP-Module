#include "DiamondTrap.hpp"

void	status(DiamondTrap& DiamondTrap1, ClapTrap& ClapTrap1)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << ClapTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << ClapTrap1.getHitPoint()
		<< " Energy Point: " << ClapTrap1.getEnergyPoint()
		<< " Attack Damage: " << ClapTrap1.getAttackDamage() << std::endl;
	std::cout << "[ " << DiamondTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << DiamondTrap1.getHitPoint()
		<< " Energy Point: " << DiamondTrap1.getEnergyPoint()
		<< " Attack Damage: " << DiamondTrap1.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

void	status(DiamondTrap& DiamondTrap1, DiamondTrap& DiamondTrap2)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << DiamondTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << DiamondTrap1.getHitPoint()
		<< " Energy Point: " << DiamondTrap1.getEnergyPoint()
		<< " Attack Damage: " << DiamondTrap1.getAttackDamage() << std::endl;
	std::cout << "[ " << DiamondTrap2.getName() << " ]";
	std::cout
		<< " Hit Point: " << DiamondTrap2.getHitPoint()
		<< " Energy Point: " << DiamondTrap2.getEnergyPoint()
		<< " Attack Damage: " << DiamondTrap2.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

void	status(DiamondTrap& DiamondTrap)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << DiamondTrap.getName() << " ]";
	std::cout
		<< " Hit Point: " << DiamondTrap.getHitPoint()
		<< " Energy Point: " << DiamondTrap.getEnergyPoint()
		<< " Attack Damage: " << DiamondTrap.getAttackDamage() << std::endl << std::endl;
}

int main()
{
	{

	}
	DiamondTrap D1("D1");
	ClapTrap C1("C1");

	std::cout << std::endl;

	D1.whoAmI();

	status(D1, C1);

	D1.attack("C1");
	status(D1, C1);
	C1.takeDamage(D1.getAttackDamage());
	status(D1, C1);
	C1.beRepaired(1);
	status(D1, C1);

	std::cout << "----------------------------------------------" << std::endl;

	for (int i = 0; i < 49; i++)
		D1.beRepaired(1);
	status(D1, C1);
	D1.attack("C1");
	D1.beRepaired(1);
	status(D1, C1);

	std::cout << "----------------------------------------------" << std::endl;

	DiamondTrap D2("D2");

	status(D2);
	D2.takeDamage(100);
	status(D2);
	D2.attack("C1");
	D2.beRepaired(1);
	status(D2);

	std::cout << "----------------------------------------------" << std::endl;

	DiamondTrap D3(D2);
	status(D2, D3);

	std::cout << std::endl;
	return (0);
}
