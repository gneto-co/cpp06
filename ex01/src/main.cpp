#include "../includes/Serializer.hpp"

int main()
{
	// creating data

	Data data;
	data.nb = 42;
	data.str = "bla bla bla";

	PRINT << CYAN "original values" << RESEND;
	PRINT << CYAN "data.nb = " << data.nb << RESEND;
	PRINT << CYAN "data.str = " << data.str << RESEND;
	PRINT << CYAN "data = " << &data << RESEND;

	SPACER(1)

	// encrypting data

	uintptr_t encrypted_data = Serializer::serialize(&data);

	PRINT << ORANGE "encrypted_data = " << encrypted_data << RESEND;

	SPACER(1)

	// decrypting data

	Data *new_data = Serializer::deserialize(encrypted_data);

	PRINT << GREEN "reinterpreted values" << RESEND;
	PRINT << GREEN "new_data.nb = " << new_data->nb << RESEND;
	PRINT << GREEN "new_data.str = " << new_data->str << RESEND;
	PRINT << GREEN "new_data = " << new_data << RESEND;

	SPACER(1)

	return 0;
}
