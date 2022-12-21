#include "karen.hpp"

int	main(void)
{
	Karen	karen;

	std::cout << "Karen complains...!!!" << std::endl;
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