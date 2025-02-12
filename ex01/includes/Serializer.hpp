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
	/* constructors destructors */
	Serializer();
	Serializer(const Serializer &copy);
	~Serializer();

	/* overload operators */
	Serializer &operator=(const Serializer &src);

public:
	/* attributes */

	/* getters */

	/* methods */
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

	/* exceptions */
};

#endif