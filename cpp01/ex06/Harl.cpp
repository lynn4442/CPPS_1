#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "To debug in C use printf" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "To get more info use the flags" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Try to warn the user" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Yay error call 911" << std::endl;
}

int Harl::getLevelIndex(std::string level)
{
	std::string levels[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int i = 0;
	while (i < 4) 
	{
		if (level == levels[i])
			return i;
		i++;
	}
	return -1;
}

void Harl::complain(std::string level) 
{
	int levelIndex = getLevelIndex(level);
	switch (levelIndex) 
	{
		case 0:
			debug();
			// fall through
		case 1: 
			info();
			// fall through
		case 2:
			warning();
			// fall through
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
} 