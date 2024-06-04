#pragma once
#include "Contact.h"
#include "ContactType.h"
#include <cstring>

class Friend: public Contact
{
	const char* date_of_birth;
	const char* phone_number;
	const char* address;
public:
	Friend(const char* nume, const char* phone_number, const char* address, const char* date_of_birth);
	~Friend();
	const char* GetName();
	ContactType getType();
	const char* Get_Phone_Number();
	const char* Get_Address();
	const char* Get_date_of_birth();
};

