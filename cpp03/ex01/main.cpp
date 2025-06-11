#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Test ClapTrap constructors
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap clap1("CT-1");
    
    // Test ScavTrap constructors
    std::cout << "\n=== Creating ScavTraps ===" << std::endl;
    ScavTrap scav1("ST-1");
    ScavTrap scav2(scav1); // Copy constructor
    
    std::cout << "\n=== Testing ClapTrap Functionality ===" << std::endl;
    
    // Test ClapTrap attack
    clap1.attack("Enemy");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    
    std::cout << "\n=== Testing ScavTrap Functionality ===" << std::endl;
    
    // Test ScavTrap attack and special function
    scav1.attack("Big Enemy");
    scav1.takeDamage(30);
    scav1.beRepaired(15);
    scav1.guardGate();
    
    // Test damage and energy limits
    std::cout << "\n=== Testing ScavTrap Limits ===" << std::endl;
    scav2.takeDamage(200); // Should destroy the ScavTrap
    scav2.attack("Target"); // Should fail because no hit points
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    // Destructors will be called here
    return 0;
} 