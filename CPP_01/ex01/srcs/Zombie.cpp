#include "../include/Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Check Default Zombie" << std::endl;
}

Zombie::Zombie(std::string name) {this->name=name;}

void Zombie::announce() 
{
    std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::~Zombie()
{
    std::cout << "Zombie '" << this->name << "' disappeared." << std::endl; 
}

void Zombie::set_name(std::string) {this->name = name;}