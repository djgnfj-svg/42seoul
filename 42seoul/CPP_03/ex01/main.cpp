#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap enem("black_hole");
	ScavTrap ysong("ysong");
	ScavTrap me;

	me = ysong;
	std::cout << "================move=================="<<std::endl;
	ysong.attack(enem.getName());
	enem.attack(ysong.getName());

	ysong.setAttackDamage(20);
	enem.setAttackDamage(20);

	ysong.takeDamage(enem.getAttackDamage());
	enem.takeDamage(me.getAttackDamage());
	ysong.beRepaired(60);
	enem.beRepaired(60);
	ysong.guardGate();
	me.guardGate();
	std::cout << "================end=================="<<std::endl;
	return (0);
}