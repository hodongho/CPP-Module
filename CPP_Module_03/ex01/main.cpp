#include "ScavTrap.hpp"

void	status(ClapTrap& ClapTrap1, ScavTrap& ScavTrap2)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << ClapTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << ClapTrap1.getHitPoint()
		<< " Energy Point: " << ClapTrap1.getEnergyPoint()
		<< " Attack Damage: " << ClapTrap1.getAttackDamage() << std::endl;
	std::cout << "[ " << ScavTrap2.getName() << " ]";
	std::cout
		<< " Hit Point: " << ScavTrap2.getHitPoint()
		<< " Energy Point: " << ScavTrap2.getEnergyPoint()
		<< " Attack Damage: " << ScavTrap2.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

void	status(ScavTrap& ScavTrap1, ScavTrap& ScavTrap2)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << ScavTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << ScavTrap1.getHitPoint()
		<< " Energy Point: " << ScavTrap1.getEnergyPoint()
		<< " Attack Damage: " << ScavTrap1.getAttackDamage() << std::endl;
	std::cout << "[ " << ScavTrap2.getName() << " ]";
	std::cout
		<< " Hit Point: " << ScavTrap2.getHitPoint()
		<< " Energy Point: " << ScavTrap2.getEnergyPoint()
		<< " Attack Damage: " << ScavTrap2.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

int main()
{
	ClapTrap C1("C1");
	ScavTrap S1("S1");

	status(C1, S1);

	std::cout << "<  C1 attack S1  >" << std::endl << std::endl;
	C1.attack("S1");
	status(C1, S1);
	std::cout << "<  S1 take Damage 0  >" << std::endl;
	S1.takeDamage(C1.getAttackDamage());
	status(C1, S1);
	std::cout << "<  S1 repaired 1  >" << std::endl;
	S1.beRepaired(1);
	status(C1, S1);

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << std::endl << "<  S1 repaired 9  >" << std::endl;
	for (int i = 0; i < 9; i++)
		S1.beRepaired(1);
	status(C1, S1);
	std::cout << "<  S1 try attack  >" << std::endl << std::endl;
	S1.attack("C1");
	std::cout << std::endl << "<  S1 try repair  >" << std::endl << std::endl;
	S1.beRepaired(1);
	status(C1, S1);

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << std::endl << "<  S1 take Damage 20  >" << std::endl;
	S1.takeDamage(120);
	S1.takeDamage(120);
	status(C1, S1);
	std::cout << "<  S1 try attack  >" << std::endl << std::endl;
	S1.attack("C1");
	std::cout << std::endl << "<  S1 try repair  >" << std::endl << std::endl;
	S1.beRepaired(1);
	status(C1, S1);

	std::cout << "----------------------------------------------" << std::endl;

	ScavTrap S2(S1);
	status(S1, S2);

	S2.guardGate();
	std::cout << std::endl;
	return (0);
}
