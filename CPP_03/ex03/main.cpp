#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap  enem("black_hole");
	DiamondTrap  ysong("ysong");
	DiamondTrap  me;

	me = ysong;
	std::cout << "================move=================="<<std::endl;
	ysong.attack(enem.getName());
	ysong.setAttackDamage(20);
	enem.takeDamage(me.getAttackDamage());
	me.guardGate();
	me.highFivesGuys();
	me.whoAmI();
	std::cout << "================end=================="<<std::endl;
	return (0);
}