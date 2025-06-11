#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Override attack function
void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " 
                  << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " has no energy points left to attack!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
    }
}

// Special ScavTrap function
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
} 