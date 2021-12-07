#include "karen.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	Karen	karen;
	std::cout << "Karen complains...!!!\n" << std::endl;
	std::cout << "DEBUG\t: ";
	karen.complain("DEBUG");
	std::cout << "INFO\t: ";
	karen.complain("INFO");
	std::cout << "WARNING\t: ";
	karen.complain("WARNING");
	std::cout << "ERROR\t: ";
	karen.complain("ERROR");
	return (0);
}