#include "../includes/Conversion.hpp"

/* SECTION - constructors destructors */

Conversion::Conversion()
{
	FT_MSG("Conversion() Constructor")
	return;
}

Conversion::Conversion(STRING value) : _original_value(value)
{
	FT_MSG("Conversion(string) Constructor")
	this->find_value();
	this->print_values();
	return;
}

Conversion::Conversion(const Conversion &copy)
{
	FT_MSG("Conversion(Conversion copy) Constructor")

	*this = copy;
	return;
}

Conversion::~Conversion()
{
	FT_MSG("~Conversion Destructor")
	return;
}

/* !SECTION */

/* SECTION - overload operators */

Conversion &Conversion::operator=(const Conversion &src)
{
	if (this != &src)
		return *this;

	return *this;
}

/* !SECTION */

/* SECTION - methods */

void Conversion::find_value()
{
	char leftover;
	
	float float_v;
	int int_v;
	double double_v;
	char char_v;

	// is float
	if ((_original_value.substr(_original_value.length() - 1) == "f") &&
		(std::sscanf(_original_value.substr(0, _original_value.length() - 1).c_str(), "%f%c", &float_v, &leftover) == 1))
	{
		this->_original_type = T_FLOAT;
		this->_float_value = float_v;
		PRINT << BOLT << "is float" << RESEND;
	}

	// is integer
	else if (std::sscanf(_original_value.c_str(), "%d%c", &int_v, &leftover) == 1)
	{
		this->_original_type = T_INT;
		this->_int_value = int_v;
		PRINT << BOLT << "is int" << RESEND;
	}

	// is double
	else if (std::sscanf(_original_value.c_str(), "%lf%c", &double_v, &leftover) == 1)
	{
		this->_original_type = T_DOUBLE;
		this->_double_value = double_v;
		PRINT << BOLT << "is double" << RESEND;
	}

	// is char
	else if (std::sscanf(_original_value.c_str(), "%c%c", &char_v, &leftover) == 1)
	{
		this->_original_type = T_CHAR;
		this->_char_value = char_v;
		PRINT << BOLT << "is char" << RESEND;
	}

	// is bullshit
	else
		throw Conversion::InvalidArgumentsException();
}

void Conversion::print_values()
{
	/* CHAR */
	PRINT << BLUE << "char: ";
	// if (this->_char_status != VALID)
	// 	PRINT << "Non displayable" << RESEND;
	// else
		PRINT << this->_char_value << RESEND;
}

/* !SECTION */

/* SECTION - getters */

/* !SECTION */

/* SECTION - setters */

/* !SECTION */

/* SECTION - exceptions */

const char *Conversion::InvalidArgumentsException::what(void) const throw()
{
	return (RED CROSSED_OUT "Invalid arguments" RESET);
}

/* !SECTION */

/* SECTION - overload signals */

/* !SECTION */
