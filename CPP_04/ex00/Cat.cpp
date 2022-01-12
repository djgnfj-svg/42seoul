#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << type << " is born" << std::endl;
}

Cat::Cat(const Cat& copy)
{
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	this->Animal::operator=(copy);
	return *this;
}

Cat::~Cat()
{
	std::cout << type << " is dead" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow~" << std::endl;
}