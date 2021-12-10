#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default Constructor" << std::endl;
}

FragTrap::FragTrap(std::string _name)
{
	std::cout << "FragTrap Constructor - name" << std::endl;
	this->name = _name;
	this->Hitpoints = 100;
	this->Energypoints = 100;
	this->Attackdameage = 30;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << "FragTrap Copy Constructor" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	std::cout << "FragTrap Assignation Operator" << std::endl;
	this->ClapTrap::operator=(copy);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "✋ FragTrap Let's high-five guys with " << this->name << "~!!" << std::endl;
}