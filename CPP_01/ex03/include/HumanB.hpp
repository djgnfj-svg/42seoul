#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    public:
    HumanB(std::string _name);
    void attack();
    void setWeapon(Weapon *weapon);
    ~HumanB();

    private:
        std::string name;
        Weapon *weapon;
};

#endif