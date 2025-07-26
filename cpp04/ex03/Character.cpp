#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
	int i = 0;
	while (i < 4)
	{
		inventory[i] = 0;
		i++;
	}
}

Character::Character(const Character& other) : name(other.name)
{
	int i = 0;
	while (i < 4)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = 0;
		i++;
	}
}

Character::~Character()
{
	int i = 0;
	while (i < 4)
	{
		if (inventory[i])
			delete inventory[i];
		i++;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;

		// Delete existing materias
		int i = 0;
		while (i < 4)
		{
			if (inventory[i])
			{
				delete inventory[i];
				inventory[i] = 0;
			}
			i++;
		}

		// Deep copy new materias
		i = 0;
		while (i < 4)
		{
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = 0;
			i++;
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;

	int i = 0;
	while (i < 4)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
		i++;
	}
	// Inventory is full, nothing happens
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		delete inventory[idx];
		inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		inventory[idx]->use(target);
	}
}
