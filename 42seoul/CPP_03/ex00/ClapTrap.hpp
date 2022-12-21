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
	private:
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