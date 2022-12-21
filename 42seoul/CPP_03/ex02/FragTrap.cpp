#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << LB;
	std::cout << "Default FragTrap created" << std::endl;
	std::cout << RESET;
}

FragTrap::FragTrap(std::string _name)
{
	this->name = _name;
	this->Hitpoints = 100;
	this->Energypoints = 100;
	this->Attackdameage = 30;
	std::cout << LB;
	std::cout << "FragTrap <" << this->name << "> created" << std::endl;
	std::cout << RESET;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << LB;
	std::cout << "FragTrap copy" << std::endl;
	std::cout << RESET;
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	std::cout << LB;
	std::cout << "FragTrap equal operator" << std::endl;
	std::cout << RESET;
	this->ClapTrap::operator=(copy);
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << LB;
	std::cout << "FragTrap <" << this->name << "> request a positive high fives.✋✋" << std::endl;
	std::cout << RESET;
}

FragTrap::~FragTrap()
{
	std::cout << LB;
	std::cout << "FragTrap <" << this->name << "> destroyed" << std::endl;
	std::cout << RESET;
}