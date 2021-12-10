#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int Hitpoints;
		int Energypoints;
		int Attackdameage;
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap& copy);
		~ClapTrap();
		
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif