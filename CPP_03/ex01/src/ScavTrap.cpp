#include "ScavTrap.hpp"

// todo 문자들 전부 그럴듯하게 바꾸기
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string _name)
{
	std::cout << "ScavTrap Constructor - name" << std::endl;
	this->name = _name;
	this->Hitpoints = 100;
	this->Energypoints = 50;
	this->Attackdameage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	std::cout << "ScavTrap Copy Constructor" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "ScavTrap Assignation Operator" << std::endl;
	this->ClapTrap::operator=(copy);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor" << std::endl;
}
