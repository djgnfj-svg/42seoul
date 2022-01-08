#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Default Animal created" << std::endl;
}

Animal::Animal(const Animal& copy) {*this = copy;}

Animal& Animal::operator=(const Animal& copy)
{
	this->type = copy.getType();
	return *this;
}

std::string const & Animal::getType() const {return this->type;}

void Animal::makeSound() const 
{
    std::cout << "Animal Animal!!!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed." << std::endl;
}