#pragma once
#include "Contact.h"
#include "ContactType.h"

class Acquaintance:public Contact
{
	const char* phone_number;
public:
	Acquaintance(const char* name, const char* phone_number);
	~Acquaintance();
	ContactType getType();
	const char* GetName();
	const char* Get_phone_number();
};

