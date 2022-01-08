#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& copy);
		~ScavTrap();

	virtual void attack(std::string const& target);
	void guardGate();
};
#endif