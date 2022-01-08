#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap created" << std::endl;
}

FragTrap::FragTrap(std::string _name)
{
	std::cout << "FragTrap <" << this->name << "> created" << std::endl;
	this->name = _name;
	this->Hitpoints = 100;
	this->Energypoints = 100;
	this->Attackdameage = 30;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << "FragTrap copy" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	std::cout << "FragTrap equal operator" << std::endl;
	this->ClapTrap::operator=(copy);
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap <" << this->name << "> request a positive high fives✋✋." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap <" << this->name << "> destroyed" << std::endl;
}