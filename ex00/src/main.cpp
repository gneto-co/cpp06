#include "../includes/Conversion.hpp"

#include <termios.h>
#include <unistd.h>
void press_any_key()
{
	PRINT << LOW_BRIGHT << "Press any key ( )" << CURSOR_LEFT(2);

	struct termios old_terminal, newt;
	tcgetattr(STDIN_FILENO, &old_terminal);
	newt = old_terminal;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	char c = getchar();
	PRINT << c << CURSOR_RIGHT(1) << RESEND;

	tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
}

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
	// press_any_key();
	return 0;
}
