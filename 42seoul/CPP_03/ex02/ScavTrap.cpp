#include "ScavTrap.hpp"

// todo 문자들 전부 그럴듯하게 바꾸기
ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap created" << std::endl;
	this->Hitpoints = 100;
	this->Energypoints = 50;
	this->Attackdameage = 20;
}

ScavTrap::ScavTrap(std::string _name)
{
	std::cout << "ScavTrap <" << this->name << "> created" << std::endl;
	this->name = _name;
	this->Hitpoints = 100;
	this->Energypoints = 50;
	this->Attackdameage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	std::cout << "ScavTrap copy" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "ScavTrap equal operator" << std::endl;
	this->ClapTrap::operator=(copy);
	return (*this);
}
void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap <" << this->name << "> attacks <" << target
				<< ">, causing " << this->Attackdameage << " points of damage!" << std::endl;
	return;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap have entered in Gate keeper mode." << std::endl;
	return;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap <" << this->name << "> destroyed" << std::endl;
}
