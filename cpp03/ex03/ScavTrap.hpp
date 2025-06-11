#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    // Constructors and destructor
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    virtual ~ScavTrap();
    
    // Assignment operator
    ScavTrap& operator=(const ScavTrap& other);
    
    // Override attack function
    void attack(const std::string& target);
    
    // Special ScavTrap function
    void guardGate();
};

#endif // SCAVTRAP_HPP 