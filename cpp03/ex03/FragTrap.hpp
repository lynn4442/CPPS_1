#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    // Constructors and destructor
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    virtual ~FragTrap();
    
    // Assignment operator
    FragTrap& operator=(const FragTrap& other);
    
    // Special FragTrap function
    void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP 