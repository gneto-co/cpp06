#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Strings.h"

typedef struct Data
{
	int nb;
	STRING str;
} Data;

class Serializer
{
private:
	/* constructors */
	Serializer();

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
	Serializer(STRING value);
	Serializer(const Serializer &copy);
	~Serializer();

	/* overload operators */
	Serializer &operator=(const Serializer &src);

	/* exceptions */
	class InvalidArgumentsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif