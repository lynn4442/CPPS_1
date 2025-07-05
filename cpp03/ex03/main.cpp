#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "=== Creating Base Traps ===" << std::endl;
	ClapTrap clap("CT-1");
	ScavTrap scav("ST-1");
	FragTrap frag("FT-1");
	
	std::cout << "\n=== Creating DiamondTrap ===" << std::endl;
	DiamondTrap diamond("DT-1");
	DiamondTrap diamond2(diamond); // copy constructor
	
	std::cout << "\n=== Testing DiamondTrap Functionality ===" << std::endl;
	
	diamond.attack("Big Boss"); // from scavtrap
	diamond.takeDamage(30);
	diamond.beRepaired(20);
	
	diamond.guardGate();
	diamond.highFivesGuys();
	
	diamond.whoAmI();
	
	std::cout << "\n=== Testing Multiple Attacks for Energy ===" << std::endl;
	int i = 0;
	while (i < 5)
	{
		std::cout << "Attack" << i+1 << ": "; //energy from scav 50 -- attack damage from frag 30
		diamond.attack("Target");
		i++;
	}
	std::cout << "\n=== End of Tests ===" << std::endl;
	return 0;
} 