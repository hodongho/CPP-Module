#include "FragTrap.hpp"

void	status(FragTrap& FragTrap1, ClapTrap& ClapTrap1)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << ClapTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << ClapTrap1.getHitPoint()
		<< " Energy Point: " << ClapTrap1.getEnergyPoint()
		<< " Attack Damage: " << ClapTrap1.getAttackDamage() << std::endl;
	std::cout << "[ " << FragTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << FragTrap1.getHitPoint()
		<< " Energy Point: " << FragTrap1.getEnergyPoint()
		<< " Attack Damage: " << FragTrap1.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

void	status(FragTrap& FragTrap1, FragTrap& FragTrap2)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << FragTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << FragTrap1.getHitPoint()
		<< " Energy Point: " << FragTrap1.getEnergyPoint()
		<< " Attack Damage: " << FragTrap1.getAttackDamage() << std::endl;
	std::cout << "[ " << FragTrap2.getName() << " ]";
	std::cout
		<< " Hit Point: " << FragTrap2.getHitPoint()
		<< " Energy Point: " << FragTrap2.getEnergyPoint()
		<< " Attack Damage: " << FragTrap2.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

void	status(FragTrap& FragTrap)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << FragTrap.getName() << " ]";
	std::cout
		<< " Hit Point: " << FragTrap.getHitPoint()
		<< " Energy Point: " << FragTrap.getEnergyPoint()
		<< " Attack Damage: " << FragTrap.getAttackDamage() << std::endl << std::endl;
}

int main()
{
	FragTrap F1("F1");
	ClapTrap C1("C1");

	std::cout << std::endl;

	F1.highFivesGuys();

	status(F1, C1);

	F1.attack("C1");
	status(F1, C1);
	C1.takeDamage(F1.getAttackDamage());
	status(F1, C1);
	C1.beRepaired(1);
	status(F1, C1);

	std::cout << "----------------------------------------------" << std::endl;

	for (int i = 0; i < 99; i++)
		F1.beRepaired(1);
	status(F1);
	F1.attack("C1");
	F1.beRepaired(1);
	status(F1);

	std::cout << "----------------------------------------------" << std::endl;

	FragTrap F2("F2");

	F2.takeDamage(200);
	status(F2);
	F2.attack("F1");
	F2.beRepaired(1);
	status(F2);

	std::cout << "----------------------------------------------" << std::endl;

	FragTrap F3(F2);
	status(F2, F3);

	std::cout << std::endl;
	return (0);
}
