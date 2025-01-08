#include "../includes/Serializer.hpp"

/* SECTION - constructors destructors */

Serializer::Serializer()
{
	FT_MSG("Serializer() Constructor")
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

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

/* !SECTION */

/* SECTION - getters */

/* !SECTION */

/* SECTION - setters */

/* !SECTION */

/* SECTION - exceptions */

/* !SECTION */

/* SECTION - overload signals */

/* !SECTION */
