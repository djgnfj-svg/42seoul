#include "ClapTrap.hpp"

int main()
{
	ClapTrap enem;
	ClapTrap ysong("ysong");
	ClapTrap me = ysong;;

	ysong.attack("black_hole");
	ysong.takeDamage(20);
	ysong.beRepaired(10);
	std::cout << "====================================" << std::endl;
	me.attack("black_hole");
	me.takeDamage(5);
	me.beRepaired(20);
	return (0);
}