#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << type << " is born" << std::endl;
}

Dog::Dog(const Dog& copy)
{
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	this->Animal::operator=(copy);
	return *this;
}

Dog::~Dog()
{
	std::cout << type << " is dead" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "wang wang." << std::endl;
}