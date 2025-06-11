#include "Zombie.hpp"
#include "newZombie.hpp"
#include "randomChump.hpp"

int main(void) 
{
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    randomChump("StackZombie");

    return 0;
} 