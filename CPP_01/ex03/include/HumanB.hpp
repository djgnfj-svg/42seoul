#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    public:
    HumanB(std::string name);
    void attack();
    void setWeapon(Weapon weapon);
    ~HumanB();

    private:
    Weapon weapon;
    std::string name;
};

#endif