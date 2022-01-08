#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

# define CYAN "\e[36m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define RED "\e[31m"
# define RESET "\e[0m"

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
		
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void setName(std::string name);
		void setHitPoints(unsigned int amount);
		void setEnergyPoints(unsigned int amount);
		void setAttackDamage(unsigned int amount);
		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
};

#endif