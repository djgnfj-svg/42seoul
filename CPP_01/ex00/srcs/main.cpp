#include "Zombie.hpp"

int	main(void)
{
	Zombie zombieStack = Zombie("stack");
	Zombie *zombieHeap = new Zombie("heap");
	Zombie *zombieNew = newZombie("newZombie");

	zombieStack.announce();
	zombieHeap->announce();
	zombieNew->announce();
	randomChump("randomChump");
	delete zombieHeap;
}