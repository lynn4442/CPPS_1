#include "Zombie.hpp"
#include <iostream>

int main()
{
    int N = 5;
    std::string zombieName = "Horde Zombie";
    
    // Create a horde of zombies
    Zombie* horde = zombieHorde(N, zombieName);
    
    // Make each zombie announce itself
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
    
    // Delete the horde to free memory
    delete[] horde;
    
    return 0;
} 