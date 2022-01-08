#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap  ysong("ysong");
	FragTrap  me;

	me = ysong;
	std::cout << "================move=================="<<std::endl;
	ysong.attack("django");
	ysong.attack("black_hole");
	me.highFivesGuys();
	std::cout << "================end=================="<<std::endl;
	return (0);
}