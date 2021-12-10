#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap Default Constructor" << std::endl;
	this->Hitpoints = FragTrap::Hitpoints;
	this->Energypoints = ScavTrap::Energypoints;
	this->Attackdameage = FragTrap::Attackdameage;
}
DiamondTrap::DiamondTrap(std::string _name): ClapTrap::ClapTrap(_name), ScavTrap::ScavTrap(_name), FragTrap::FragTrap(_name)
{
	std::cout << "DiamondTrap Constructor - name" << std::endl;
	this->name = _name;
	ClapTrap::name = _name + "_clap_name";
	this->Hitpoints = FragTrap::Hitpoints;
	this->Energypoints = ScavTrap::Energypoints;
	this->Attackdameage = FragTrap::Attackdameage;
};	

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	std::cout << "DiamondTrap Copy Constructor" << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	std::cout << "DiamondTrap Assignation Operator" << std::endl;
	this->ClapTrap::operator=(copy);
	this->name = copy.name;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor" << std::endl;
}