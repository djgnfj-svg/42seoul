#include "karen.hpp"

Karen::Karen()
{
    complain_list[0].level = "DEBUG";
    complain_list[0].func_ptr = &Karen::debug;
    complain_list[1].level = "INFO";
    complain_list[1].func_ptr = &Karen::info;
    complain_list[2].level = "WARNING";
    complain_list[2].func_ptr = &Karen::warning;
    complain_list[3].level = "ERROR";
    complain_list[3].func_ptr = &Karen::error;
}


void	Karen::debug(void)
{
    std::cout << "[ DEBUG ]"<< std::endl
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< std::endl << "I just love it!" << std::endl << std::endl;
}

void	Karen::info(void)
{
    std::cout << "[ INFO ]"<< std::endl
		<< "I cannot believe adding extra bacon cost more money." << std::endl
		<< "You don’t put enough! If you did I would not have to ask for it!"
		<< std::endl << std::endl;
}

void	Karen::warning(void)
{
        std::cout << "[ WARNING ]"<< std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming here for years and you just started working here last month."
		<< std::endl << std::endl;
}

void	Karen::error(void)
{
    std::cout << "[ ERROR ]"<< std::endl
		<< "This is unacceptable, I want to speak to the manager now."
		<< std::endl << std::endl;
}

void Karen::complain(std::string level)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (level == complain_list[i].level)
            break;
        else if (i > 3)
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