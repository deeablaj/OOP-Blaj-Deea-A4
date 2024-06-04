#include "Contact.h"
#include "ContactType.h"
#pragma once

class Colleague: public Contact
{
	const char* phone_number;
	const char* address;
	const char* company;
public:
	Colleague(const char* name, const char* phone_number, const char* company, const char* address);
	~Colleague();
	ContactType getType();
	const char* GetName();
	const char* Get_Phone_Number();
	const char* Get_Address();
	const char* Get_Company();
};

