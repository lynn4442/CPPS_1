#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->_name = "Default";
    this->_hitPoints = FragTrap::_hitPoints; // 100
    this->_energyPoints = ScavTrap::_energyPoints; // 50
    this->_attackDamage = FragTrap::_attackDamage; // 30
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints; // 100
    this->_energyPoints = ScavTrap::_energyPoints; // 50
    this->_attackDamage = FragTrap::_attackDamage; // 30
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    return *this;
}

// Override attack to use ScavTrap's version
void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

// Special DiamondTrap function
void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name << ", and my ClapTrap name is " 
              << ClapTrap::_name << std::endl;
} 