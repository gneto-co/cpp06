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

public:

	/* constructors destructors */
	Serializer();
	Serializer(const Serializer &copy);
	~Serializer();

	/* attributes */

	/* getters */

	/* methods */
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);

	/* overload operators */
	Serializer &operator=(const Serializer &src);

	/* exceptions */
};

#endif