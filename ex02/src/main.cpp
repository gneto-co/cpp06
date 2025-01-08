#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

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

// ---------- //

Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		PRINT << CYAN "Class A" << RESEND;
	else if (dynamic_cast<B *>(p))
		PRINT << CYAN "Class B" << RESEND;
	else if (dynamic_cast<C *>(p))
		PRINT << CYAN "Class C" << RESEND;
	else
		PRINT << RED "error1" << RESEND;
}

void identify(Base &p)
{
	try
	{
		Base random_class = dynamic_cast<A &>(p);
		PRINT << GREEN "Class A" << RESEND;
		return;
	}
	catch(const std::exception &e){};

	try
	{
		Base random_class = dynamic_cast<B &>(p);
		PRINT << GREEN "Class B" << RESEND;
		return;
	}
	catch(const std::exception &e){};

	try
	{
		Base random_class = dynamic_cast<C &>(p);
		PRINT << GREEN "Class C" << RESEND;
		return;
	}
	catch(const std::exception &e){};
}

int main()
{
	srand(time(NULL));

	Base *random_class = generate();

	if (random_class != NULL)
	{
		identify(random_class);
		identify(*random_class);
		delete (random_class);

		SPACER(1)
	}

	// press_any_key();
	return 0;
}
