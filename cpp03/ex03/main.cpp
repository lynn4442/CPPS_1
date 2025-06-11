#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    // Test base classes constructors
    std::cout << "=== Creating Base Traps ===" << std::endl;
    ClapTrap clap("CT-1");
    ScavTrap scav("ST-1");
    FragTrap frag("FT-1");
    
    // Test DiamondTrap
    std::cout << "\n=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap diamond("DT-1");
    DiamondTrap diamond2(diamond); // Copy constructor
    
    std::cout << "\n=== Testing DiamondTrap Functionality ===" << std::endl;
    
    // Test inherited functions
    diamond.attack("Big Boss"); // Should use ScavTrap's attack
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    
    // Test special functions from both parents
    diamond.guardGate(); // From ScavTrap
    diamond.highFivesGuys(); // From FragTrap
    
    // Test DiamondTrap's own function
    diamond.whoAmI();
    
    // Test inheritance of attributes
    std::cout << "\n=== Testing Multiple Attacks for Energy ===" << std::endl;
    // Should have ScavTrap's energy (50) and FragTrap's attack damage (30)
    for (int i = 0; i < 5; i++) {
        std::cout << "Attack " << i+1 << ": ";
        diamond.attack("Target");
    }
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    // Destructors will be called here in reverse order
    return 0;
} 