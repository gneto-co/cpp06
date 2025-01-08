#include "../includes/Serializer.hpp"

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

int main()
{
	Data data;
	data.nb = 42;
	data.str = "bla bla bla";

	PRINT << CYAN "original values" << RESEND;
	PRINT << CYAN "data.nb = " << data.nb << RESEND;
	PRINT << CYAN "data.str = " << data.str << RESEND;
	PRINT << CYAN "data = " << &data << RESEND;


	SPACER(1)

	Serializer serializer;

	Data *new_data = serializer.deserialize(serializer.serialize(&data));

	PRINT << GREEN "reinterpreted values" << RESEND;
	PRINT << GREEN "new_data.nb = " << new_data->nb << RESEND;
	PRINT << GREEN "new_data.str = " << new_data->str << RESEND;
	PRINT << GREEN "new_data = " << new_data << RESEND;

	SPACER(1)

	// press_any_key();
	return 0;
}
