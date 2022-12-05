#include "ClapTrap.hpp"

void	status(ClapTrap& ClapTrap1, ClapTrap& ClapTrap2)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << ClapTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << ClapTrap1.getHitPoint()
		<< " Energy Point: " << ClapTrap1.getEnergyPoint()
		<< " Attack Damage: " << ClapTrap1.getAttackDamage() << std::endl;
	std::cout << "[ " << ClapTrap2.getName() << " ]";
	std::cout
		<< " Hit Point: " << ClapTrap2.getHitPoint()
		<< " Energy Point: " << ClapTrap2.getEnergyPoint()
		<< " Attack Damage: " << ClapTrap2.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

int main()
{
	ClapTrap C1("C1");
	ClapTrap C2("C2");

	status(C1, C2);

	std::cout << "<  C1 attack C2  >" << std::endl << std::endl;
	C1.attack("C2");
	status(C1, C2);
	std::cout << "<  C2 take Damage 0  >" << std::endl;
	C2.takeDamage(C1.getAttackDamage());
	status(C1, C2);
	std::cout << "<  C2 repaired 1  >" << std::endl;
	C2.beRepaired(1);
	status(C1, C2);

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << std::endl << "<  C2 repaired 9  >" << std::endl;
	for (int i = 0; i < 9; i++)
		C2.beRepaired(1);
	status(C1, C2);
	std::cout << "<  C2 try attack  >" << std::endl << std::endl;
	C2.attack("C1");
	std::cout << std::endl << "<  C2 try repair  >" << std::endl << std::endl;
	C2.beRepaired(1);
	status(C1, C2);

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << std::endl << "<  C2 take Damage 20  >" << std::endl;
	C2.takeDamage(20);
	C2.takeDamage(20);
	status(C1, C2);
	std::cout << "<  C2 try attack  >" << std::endl << std::endl;
	C2.attack("C1");
	std::cout << std::endl << "<  C2 try repair  >" << std::endl << std::endl;
	C2.beRepaired(1);
	status(C1, C2);

	std::cout << "----------------------------------------------" << std::endl;

	ClapTrap C3(C1);
	status(C1, C3);
	return (0);
}
