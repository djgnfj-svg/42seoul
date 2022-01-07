#ifndef __WEAPOM_HPP__
# define __WEAPOM_HPP__
# include <iostream>

class Weapon
{
    public:
    Weapon(std::string type);
    std::string gettype() const;
    void setType(std::string type);
    ~Weapon();

    private:
    std::string type;
};

#endif