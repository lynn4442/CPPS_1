#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap defaultTrap;
	ClapTrap trap1("CT-1");
	ClapTrap trap2("CT-2");
	ClapTrap trap3(trap1); // this is the copy constructor
	
	std::cout << "\n=== Testing Functionality ===" << std::endl;

	trap1.attack("Enemy Robot");
	
	trap1.takeDamage(5);
	trap1.takeDamage(6); // this should destroy trap1
	trap1.takeDamage(1); // trying to damage an already destroyed trap
	
	trap2.beRepaired(3);
	
	std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
	int i = 0;
	while (i < 10)
	{
		std::cout << "Attack " << i+1 << ": ";
		trap2.attack("Target");
		i++;
	}
	
	// Can't attack or repair when out of energy
	trap2.attack("Target");
	trap2.beRepaired(5);
	
	std::cout << "\n=== End of game :/ ===" << std::endl;

	return 0;
} 