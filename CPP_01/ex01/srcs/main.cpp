#include "../include/Zombie.hpp"


int	main()
{
	Zombie zombieStack = Zombie("stack");
	Zombie *zombieHeap = new Zombie("heap");

	zombieStack.announce();
	zombieHeap->announce();
	delete zombieHeap;
}