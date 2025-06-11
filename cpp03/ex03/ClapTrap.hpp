#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    // Constructors and destructor
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    virtual ~ClapTrap(); // Make destructor virtual to ensure proper destruction
    
    // Assignment operator
    ClapTrap& operator=(const ClapTrap& other);
    
    // Member functions
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Getter for name
    const std::string& getName() const;
};

#endif // CLAPTRAP_HPP 