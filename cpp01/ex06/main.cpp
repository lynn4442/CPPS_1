#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return 1;
	}
	Harl harl;
	std::string level = argv[1];
	harl.complain(level);
	return 0;
} 