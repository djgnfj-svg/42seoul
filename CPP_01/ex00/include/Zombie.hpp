#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        void announce();
        ~Zombie();
    private:
        std::string name;
};

Zombie  *newZombie(std::string);
void    randomChump(std::string);
#endif