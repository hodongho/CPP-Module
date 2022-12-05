#include "ScavTrap.hpp"

void	status(ScavTrap& ScavTrap1, ClapTrap& ClapTrap1)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << ClapTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << ClapTrap1.getHitPoint()
		<< " Energy Point: " << ClapTrap1.getEnergyPoint()
		<< " Attack Damage: " << ClapTrap1.getAttackDamage() << std::endl;
	std::cout << "[ " << ScavTrap1.getName() << " ]";
	std::cout
		<< " Hit Point: " << ScavTrap1.getHitPoint()
		<< " Energy Point: " << ScavTrap1.getEnergyPoint()
		<< " Attack Damage: " << ScavTrap1.getAttackDamage() << std::endl;
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

void	status(ScavTrap& ScavTrap)
{
	std::cout << std::endl << "<      Status      >" << std::endl;
	std::cout << "[ " << ScavTrap.getName() << " ]";
	std::cout
		<< " Hit Point: " << ScavTrap.getHitPoint()
		<< " Energy Point: " << ScavTrap.getEnergyPoint()
		<< " Attack Damage: " << ScavTrap.getAttackDamage() << std::endl << std::endl;
}

int main()
{
	ScavTrap S1("S1");
	ClapTrap C1("C1");

	std::cout << std::endl;

	S1.guardGate();

	status(S1, C1);

	S1.attack("C1");
	status(S1, C1);
	C1.takeDamage(S1.getAttackDamage());
	status(S1, C1);
	C1.beRepaired(1);
	status(S1, C1);

	std::cout << "----------------------------------------------" << std::endl;

	for (int i = 0; i < 49; i++)
		S1.beRepaired(1);
	status(S1);
	S1.attack("C1");
	S1.beRepaired(1);
	status(S1);

	std::cout << "----------------------------------------------" << std::endl;

	ScavTrap S2("S2");

	S2.takeDamage(200);
	status(S2);
	S2.attack("S1");
	S2.beRepaired(1);
	status(S2);

	std::cout << "----------------------------------------------" << std::endl;

	ScavTrap S3(S2);
	status(S2, S3);

	std::cout << std::endl;
	return (0);
}
