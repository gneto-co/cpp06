#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include "Strings.h"

#define VALID true
#define INVALID false

#define T_CHAR 0
#define T_INT 1
#define T_FLOAT 2
#define T_DOUBLE 3
#define T_FLOAT_NAN_INF 4
#define T_DOUBLE_NAN_INF 5

class Conversion
{
private:
	/* constructors */
	Conversion();

	/* attributes */
	STRING const _original_value;
	int _original_type;

	char _char_value;
	int _int_value;
	float _float_value;
	double _double_value;
	
	char _char_status;
	int _int_status;
	float _float_status;
	double _double_status;

	/* methods */
	void from_char();
	void from_int();
	void from_float();
	void from_double();
	void from_float_nan_inf();
	void from_double_nan_inf();

	void print_values();
	void find_value();

	/* getters */

public:
	/* constructors destructors */
	Conversion(STRING value);
	Conversion(const Conversion &copy);
	~Conversion();

	/* overload operators */
	Conversion &operator=(const Conversion &src);

	/* exceptions */
	class InvalidArgumentsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif