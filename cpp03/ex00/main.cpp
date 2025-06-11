#include "ClapTrap.hpp"

int main() {
    // Test constructors
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap defaultTrap;
    ClapTrap trap1("CT-1");
    ClapTrap trap2("CT-2");
    ClapTrap trap3(trap1); // Copy constructor
    
    std::cout << "\n=== Testing Functionality ===" << std::endl;
    
    // Test attack
    trap1.attack("Enemy Robot");
    
    // Test taking damage
    trap1.takeDamage(5);
    trap1.takeDamage(6); // This should destroy trap1
    trap1.takeDamage(1); // Trying to damage an already destroyed trap
    
    // Test repairs
    trap2.beRepaired(3);
    
    // Test energy depletion
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Attack " << i+1 << ": ";
        trap2.attack("Target");
    }
    
    // Can't attack or repair when out of energy
    trap2.attack("Target");
    trap2.beRepaired(5);
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
} 