#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), Hitpoints(10), Energypoints(10), Attackdameage(0) 
{
	std::cout << "Default ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name), Hitpoints(10), Energypoints(10), Attackdameage(0)
{
	std::cout << "ClapTrap <" << this->name << "> created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "ClapTrap equal operator" << std::endl;
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
	if (this->Hitpoints <= 0)
	{
		std::cout << "ClapTrap <" << this->name << "> is died." << std::endl;
		return;
	}
	std::cout << "ClapTrap <" << this->name << "> attacks <" << target
				<< ">, causing " << this->Attackdameage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hitpoints <= 0)
	{
		std::cout << "But ClapTrap <" << this->name << "> is died." << std::endl;
		return;
	}
	this->Hitpoints -= amount;
	std::cout << "ClapTrap <" << this->name << "> takes " << amount << " points of damage. The remaining HP is ";
	if (this->Hitpoints <= 0)
		std::cout << "Less than 0. ClapTrap <" << this->name << "> is died." << std:: endl;
	else
		std::cout << this->Hitpoints << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hitpoints <= 0)
	{
		std::cout << "But ClapTrap <" << this->name << "> is died. " << std::endl;
		return ;
	}
	else
		std::cout << "ClapTrap <" << this->name << "> is repaired. ";
	this->Hitpoints += amount;
	std::cout << "It recovers " << amount << " points, the remaining HP is " << this->Hitpoints << "." << std::endl;
}

void ClapTrap::setName(std::string name) {this->name = name;}

void ClapTrap::setHitPoints(unsigned int amount) {this->Hitpoints = amount;}

void ClapTrap::setEnergyPoints(unsigned int amount) {this->Energypoints = amount;}

void ClapTrap::setAttackDamage(unsigned int amount) {this->Attackdameage = amount;}

std::string ClapTrap::getName() const {return (this->name);}

unsigned int ClapTrap::getHitPoints() const {return (this->Hitpoints);}

unsigned int ClapTrap::getEnergyPoints() const {return (this->Energypoints);}

unsigned int ClapTrap::getAttackDamage() const {return (this->Attackdameage);}