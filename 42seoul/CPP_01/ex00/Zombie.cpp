#include "Zombie.hpp"

Zombie::Zombie(std::string name) {this->name=name;}

void Zombie::announce(void) 
{
    std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie::~Zombie()
{
    std::cout << "Zombie '" << this->name << "' disappeared." << std::endl; 
}