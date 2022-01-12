#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << type << " is born" << std::endl;
	this->type = "Wrong Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	this->type = copy.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << type << " is dead" << std::endl;
}

std::string const & WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong_Animal Wrong_Animal!!!" << std::endl;
}