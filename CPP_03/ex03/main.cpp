#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap  ysong("ysong");
	DiamondTrap  me;

	me = ysong;
	std::cout << "================move=================="<<std::endl;
	ysong.attack("black_hole");
	ysong.setAttackDamage(20);
	me.guardGate();
	me.highFivesGuys();
	me.whoAmI();
	std::cout << "================end=================="<<std::endl;
	return (0);
}