#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& copy);
        Animal& operator=(const Animal& copy);
        virtual ~Animal();
        std::string const & getType() const;
        virtual void makeSound() const;
};

#endif