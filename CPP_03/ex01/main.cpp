#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap enem("black_hole");
	ScavTrap ysong("ysong");
	ScavTrap me;

	me = ysong;
	std::cout << "================move=================="<<std::endl;
	ysong.attack(enem.getName());
	ysong.setAttackDamage(20);
	enem.takeDamage(me.getAttackDamage());
	enem.beRepaired(60);
	me.guardGate();
	std::cout << "================end=================="<<std::endl;
	return (0);
}