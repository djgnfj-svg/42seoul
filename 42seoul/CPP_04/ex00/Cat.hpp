#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
	virtual ~Cat();
	virtual void makeSound() const;
};

#endif