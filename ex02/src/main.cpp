#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

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

	return 0;
}
