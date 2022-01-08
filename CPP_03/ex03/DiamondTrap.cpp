#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default DiamondTrap created" << std::endl;
	this->Hitpoints = FragTrap::Hitpoints;
	this->Energypoints = ScavTrap::Energypoints;
	this->Attackdameage = FragTrap::Attackdameage;
}

DiamondTrap::DiamondTrap(std::string _name): ClapTrap::ClapTrap(_name), ScavTrap::ScavTrap(_name), FragTrap::FragTrap(_name)
{
	std::cout << "DiamondTrap <" << this->name << "> created" << std::endl;
	this->name = _name;
	ClapTrap::name = _name + "_clap_name";
	this->Hitpoints = FragTrap::Hitpoints;
	this->Energypoints = ScavTrap::Energypoints;
	this->Attackdameage = FragTrap::Attackdameage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	std::cout << "DiamondTrap copy" << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	std::cout << "DiamondTrap equal operator" << std::endl;
	this->ClapTrap::operator=(copy);
	this->name = copy.name;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << this->name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap <" << this->name << "> destroyed" << std::endl;
}