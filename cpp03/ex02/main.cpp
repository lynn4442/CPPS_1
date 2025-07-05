#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap clap1("CT-1");
	
	std::cout << "\n=== Creating ScavTraps ===" << std::endl;
	ScavTrap scav1("ST-1");
	
	std::cout << "\n=== Creating FragTraps ===" << std::endl;
	FragTrap frag1("FT-1");
	FragTrap frag2(frag1); // copy constructor
	
	std::cout << "\n=== Testing ClapTrap Functionality ===" << std::endl;
	clap1.attack("Enemy");
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	
	std::cout << "\n=== Testing ScavTrap Functionality ===" << std::endl;
	scav1.attack("Big Enemy");
	scav1.takeDamage(30);
	scav1.beRepaired(15);
	scav1.guardGate();
	
	std::cout << "\n=== Testing FragTrap Functionality ===" << std::endl;
	frag1.attack("Huge Enemy");
	frag1.takeDamage(50);
	frag1.beRepaired(30);
	frag1.highFivesGuys();
	
	std::cout << "\n=== Testing FragTrap Limits ===" << std::endl;
	frag2.takeDamage(200);
	frag2.attack("Target"); // no hit points here
	
	std::cout << "\n=== End of Tests ===" << std::endl;
	
	return 0;
} 