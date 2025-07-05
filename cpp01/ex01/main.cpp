#include "Zombie.hpp"
#include <iostream>

int main()
{
	int N = 5;
	int i = 0;
	std::string zombieName = "Horde Zombie";
	//horde of zombies
	Zombie* horde = zombieHorde(N, zombieName);
	//we are using the horde pointer to access the zombies and announce them
	while (i < N)
	{
		std::cout << "Zombie " << i + 1 << ": ";
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return 0;
} 