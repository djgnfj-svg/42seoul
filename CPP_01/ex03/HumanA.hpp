#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    public:
    HumanA(std::string _name, Weapon &_weapon);
    void attack();
    void setWeapon(Weapon weapon);
    ~HumanA();

    private:
        std::string name;
        Weapon &weapon;
};
#endif