#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name), weapon(NULL) {}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon *weapon)
{
    this->weapon = weapon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with his " << weapon->gettype() << std::endl;
}