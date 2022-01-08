#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap  enem("black_hole");
	FragTrap  ysong("ysong");
	FragTrap  me;

	me = ysong;
	std::cout << "================move=================="<<std::endl;
	ysong.attack(enem.getName());
	ysong.setAttackDamage(20);
	enem.takeDamage(me.getAttackDamage());
	enem.beRepaired(60);
	me.highFivesGuys();
	std::cout << "================end=================="<<std::endl;
	return (0);
}