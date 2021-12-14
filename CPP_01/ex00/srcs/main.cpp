#include "Zombie.hpp"

int	main(void)
{
	Zombie zombieStack = Zombie("stack");
	zombieStack.announce();
	Zombie *zombieheap = newZombie("Newzombie");
	zombieheap->announce();
	randomChump("randomChump");
	delete zombieheap;
}