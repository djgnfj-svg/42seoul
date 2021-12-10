#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), Hitpoints(10), Energypoints(10), Attackdameage(10) 
{
	std::cout << "Default ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name), Hitpoints(10), Energypoints(10), Attackdameage(10)\
{
	std::cout << "ClapTrap <" << this->name << "> created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& copy)
{
	this->name = copy.name;
	this->Hitpoints = copy.Hitpoints;
	this->Energypoints = copy.Energypoints;
	this->Attackdameage = copy.Attackdameage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap <" << this->name << "> destroyed" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	//출력 문자생각
}

void ClapTrap::takeDamage(unsigned int amount)
{
	//출력 문자생각
	this->Hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	//출력 문자생각
	this->Hitpoints += amount;
}