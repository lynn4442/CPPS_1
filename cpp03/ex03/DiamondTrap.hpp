#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name; // Same variable name as in ClapTrap

public:
    // Constructors and destructor
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();
    
    // Assignment operator
    DiamondTrap& operator=(const DiamondTrap& other);
    
    // Override attack to use ScavTrap's version
    void attack(const std::string& target);
    
    // Special DiamondTrap function
    void whoAmI();
};

#endif // DIAMONDTRAP_HPP 