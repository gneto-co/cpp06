#include "../includes/Serializer.hpp"

/* SECTION - constructors destructors */

Serializer::Serializer()
{
	FT_MSG("Serializer() Constructor")
	return;
}

Serializer::Serializer(STRING value) : _original_value(value)
{
	FT_MSG("Serializer(string) Constructor")
	_char_status = VALID;
	_int_status = VALID;
	_float_status = VALID;
	_double_status = VALID;
	_double_value = atof(_original_value.c_str());
	this->find_value();
	this->print_values();
	return;
}

Serializer::Serializer(const Serializer &copy)
{
	FT_MSG("Serializer(Serializer copy) Constructor")

	*this = copy;
	return;
}

Serializer::~Serializer()
{
	FT_MSG("~Serializer Destructor")
	return;
}

/* !SECTION */

/* SECTION - overload operators */

Serializer &Serializer::operator=(const Serializer &src)
{
	if (this != &src)
		return *this;

	return *this;
}

/* !SECTION */

/* SECTION - methods */

void Serializer::find_value()
{
	// is -inff, +inff, nanf
	if (_original_value.compare("nanf") == 0 ||
		_original_value.compare("+inff") == 0 ||
		_original_value.compare("-inff") == 0)
	{
		_original_type = T_FLOAT_NAN_INF;
	}

	// is -inf, +inf, nan
	else if (_original_value.compare("nan") == 0 ||
			 _original_value.compare("+inf") == 0 ||
			 _original_value.compare("-inf") == 0)
	{
		_original_type = T_DOUBLE_NAN_INF;
	}

	// is single signal (char)
	else if (_original_value.length() == 1 &&
			 (_original_value[0] == '+' || _original_value[0] == '-' ||
			  _original_value[0] == 'f' || _original_value[0] == '.'))
		_original_type = T_CHAR;

	// as multiple signals
	else if (_original_value.find_first_of("+-") != _original_value.find_last_of("+-"))
		throw Serializer::InvalidArgumentsException();

	// is int
	else if (_original_value.find_first_not_of("+-0123456789") == std::string::npos)
		_original_type = T_INT;

	// is double
	else if (_original_value.find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (
			_original_value.find_first_of(".") != _original_value.find_last_of(".") ||	 // multiple '.'
			isdigit(_original_value[_original_value.find_first_of(".") + 1]) == false || // catches `0.`
			_original_value.find_first_of(".") == 0										 // catches `.0`
		)
			throw Serializer::InvalidArgumentsException();
		else
			_original_type = T_DOUBLE;
	}

	// is float
	else if (_original_value.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (
			_original_value.find_first_of("f") != _original_value.find_last_of("f") ||		// multiple 'f'
			_original_value.find_first_of(".") != _original_value.find_last_of(".") ||		// multiple '.'
			_original_value.find_first_of("f") - _original_value.find_first_of(".") == 1 || // catches `0.f`
			_original_value.find_first_of(".") == 0 ||										// catches `.0f`
			_original_value[_original_value.find_first_of("f") + 1] != '\0'					// catches `0.0f0`
		)

			throw Serializer::InvalidArgumentsException();
		else
			_original_type = T_FLOAT;
	}

	// is char
	else if ((_original_value.length() == 1 && std::isprint(_original_value[0])) ||
			 (_original_value.length() == 1 && std::isalpha(_original_value[0])))
	{
		_original_type = T_CHAR;
	}

	// is bullshit
	else
		throw Serializer::InvalidArgumentsException();
}

void Serializer::from_char()
{
	_char_value = static_cast<unsigned char>(_original_value[0]);
	_int_value = static_cast<int>(_char_value);
	_float_value = static_cast<float>(_char_value);
	_double_value = static_cast<double>(_char_value);
}

void Serializer::from_int()
{
	_int_value = static_cast<int>(_double_value);
	_char_value = static_cast<unsigned char>(_int_value);
	_float_value = static_cast<float>(_int_value);
}
void Serializer::from_float()
{
	_float_value = static_cast<float>(_double_value);
	_int_value = static_cast<int>(_float_value);
	_char_value = static_cast<unsigned char>(_float_value);
}
void Serializer::from_double()
{
	_float_value = static_cast<float>(_double_value);
	_int_value = static_cast<int>(_double_value);
	_char_value = static_cast<unsigned char>(_double_value);
}

void Serializer::from_float_nan_inf()
{
	_float_value = static_cast<float>(_double_value);
	_int_status = INVALID;
	_char_status = INVALID;
}

void Serializer::from_double_nan_inf()
{
	_float_value = static_cast<float>(_double_value);
	_int_status = INVALID;
	_char_status = INVALID;
}

void Serializer::print_values()
{
	// STRING types[] = {"T_CHAR", "T_INT", "T_FLOAT", "T_DOUBLE", "FLOAT_NAN_INF", "DOUBLE_NAN_INF"};
	// PRINT << types[_original_type] << RESEND;

	void (Serializer::*functions[])(void) = {&Serializer::from_char, &Serializer::from_int, &Serializer::from_float, &Serializer::from_double, &Serializer::from_float_nan_inf, &Serializer::from_double_nan_inf};
	(this->*functions[_original_type])();

	// char
	PRINT << "char: ";
	if (_char_status == VALID && std::isprint(_char_value))
		PRINT << "\'" << _char_value << "\'" << RESEND;
	else
		PRINT << BRIGHT_RED "Non displayable" << RESEND;

	// int
	PRINT << "int: ";
	if (_int_status == VALID && _double_value <= INT_MAX && _double_value >= INT_MIN)
		PRINT << _int_value << RESEND;
	else
		PRINT << BRIGHT_RED "invalid" << RESEND;

	// float
	PRINT << "float: ";
	if (_float_status == VALID)
		if (_original_type == T_FLOAT_NAN_INF)
			PRINT << _original_value << RESEND;
		else if (_original_type == T_DOUBLE_NAN_INF)
			PRINT << _original_value << "f" << RESEND;
		else if (_float_value - _int_value == 0)
			PRINT << _float_value << ".0f" << RESEND;
		else
			PRINT << _float_value << "f" << RESEND;
	else
		PRINT << BRIGHT_RED "invalid" << RESEND;

	// double
	PRINT << "double: ";
	if (_double_status == VALID)
		if (_original_type == T_DOUBLE_NAN_INF)
			PRINT << _original_value << RESEND;
		else if (_original_type == T_FLOAT_NAN_INF)
			PRINT << _original_value.substr(0, _original_value.length() - 1) << RESEND;
		else if (_float_value - _int_value == 0)
			PRINT << _float_value << ".0" << RESEND;
		else
			PRINT << _float_value << RESEND;
	else
		PRINT << BRIGHT_RED "invalid" << RESEND;
}

/* !SECTION */

/* SECTION - getters */

/* !SECTION */

/* SECTION - setters */

/* !SECTION */

/* SECTION - exceptions */

const char *Serializer::InvalidArgumentsException::what(void) const throw()
{
	return (RED CROSSED_OUT "Invalid arguments" RESET);
}

/* !SECTION */

/* SECTION - overload signals */

/* !SECTION */
