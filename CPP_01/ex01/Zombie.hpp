#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <sstream>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name); 
        ~Zombie();

        void announce();
        void set_name(std::string name);
    private:
        std::string name;
};

Zombie *zombieHorde(int N, std::string name);
#endif