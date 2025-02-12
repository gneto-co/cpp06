#include "../includes/Conversion.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw Conversion::InvalidArgumentsException();
		else
		{
			MAIN_MSG("Conversion")
			Conversion conversion(av[1]);
		}
	}
	CATCH
	SPACER(1)
	return 0;
}
