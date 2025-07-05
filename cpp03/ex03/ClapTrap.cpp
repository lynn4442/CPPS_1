#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : 
    _name(other._name), 
    _hitPoints(other._hitPoints), 
    _energyPoints(other._energyPoints), 
    _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other)
	{
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
	{
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
                  << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
	else if (_energyPoints == 0)
        std::cout << "ClapTrap " << _name << " has no energy points left to attack!" << std::endl;
    else
        std::cout << "ClapTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
	{
        if (amount >= _hitPoints)
		{
            _hitPoints = 0;
            std::cout << "ClapTrap " << _name << " takes " << amount 
                      << " damage and is destroyed!" << std::endl;
        } 
		else 
		{
            _hitPoints -= amount;
            std::cout << "ClapTrap " << _name << " takes " << amount 
                      << " damage! Hit points remaining: " << _hitPoints << std::endl;
        }
    }
	else
        std::cout << "ClapTrap " << _name << " is already destroyed and cannot take more damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
	{
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
                  << " hit points! Current hit points: " << _hitPoints << std::endl;
        _energyPoints--;
    }
	else if (_energyPoints == 0)
        std::cout << "ClapTrap " << _name << " has no energy points left to repair itself!" << std::endl;
	else
        std::cout << "ClapTrap " << _name << " is out of hit points and cannot repair itself!" << std::endl;
}

const std::string& ClapTrap::getName() const { return _name;}