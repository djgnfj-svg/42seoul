#include "karen.hpp"

Karen::Karen()
{
    complain_list[0].level = "Debug";
    complain_list[0].func_ptr = &Karen::debug;
    complain_list[1].level = "info";
    complain_list[1].func_ptr = &Karen::info;
    complain_list[2].level = "warning";
    complain_list[2].func_ptr = &Karen::warning;
    complain_list[3].level = "error";
    complain_list[3].func_ptr = &Karen::error;
}

void	Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (level == complain_list[i].level)
            break;
        i = -1;
    }
    switch (i)
    {
    case 0:
        return (this->*complain_list[i].func_ptr)();
    case 1:
        return (this->*complain_list[i].func_ptr)();
    case 2:
        return (this->*complain_list[i].func_ptr)();
    case 3:
        return (this->*complain_list[i].func_ptr)();
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}