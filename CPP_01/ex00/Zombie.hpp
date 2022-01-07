#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        void announce(void);
        ~Zombie();
    private:
        std::string name;
};

Zombie  *newZombie(std::string);
void    randomChump(std::string);

#endif