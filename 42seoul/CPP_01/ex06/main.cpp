#include "karen.hpp"

int	print_error(std::string error)
{
	std::cout << error << std::endl;
	return 1;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return print_error("The input is not correct." );

	Karen	karen;
	std::string filter(av[1]);
	if (!(filter == "DEBUG" || filter == "INFO" || filter == "WARNING" || filter == "ERROR"))
		return print_error("[ Probably complaining about insignificant problems ]" );

	karen.complain(filter);
	return (0);
}