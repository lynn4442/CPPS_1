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

void Harl::complain(std::string level)
{
	void (Harl::*functions[4])(void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
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
		{
			(this->*functions[i])();
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << "[ Probably whining about something ridiculous again... ]" << std::endl;
} 