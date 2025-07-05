#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap clap1("CT-1");
	
	std::cout << "\n=== Creating ScavTraps ===" << std::endl;
	ScavTrap scav1("ST-1");
	ScavTrap scav2(scav1); // copy constructor
	
	std::cout << "\n=== Testing ClapTrap Functionality ===" << std::endl;
	
	clap1.attack("Enemy");
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	
	std::cout << "\n=== Testing ScavTrap Functionality ===" << std::endl;
	
	scav1.attack("Big Enemy");
	scav1.takeDamage(30);
	scav1.beRepaired(15);
	scav1.guardGate();
	
	std::cout << "\n=== Testing ScavTrap Limits ===" << std::endl;
	scav2.takeDamage(200);
	scav2.attack("Target");
	
	std::cout << "\n=== End of Tests ===" << std::endl;
	return 0;
} 