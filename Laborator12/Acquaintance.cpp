#include "Acquaintance.h"
#include "ContactType.h"
#include "Contact.h"
Acquaintance::Acquaintance(const char* name, const char* phone_number)
{
	this->name = name;
	this->phone_number = phone_number;
}

Acquaintance::~Acquaintance()
{
	delete[] name;
	delete[] phone_number;
}

ContactType Acquaintance::getType()
{
	return ContactType::ACQUAINTANCE;
}

const char* Acquaintance::GetName()
{
	return this->name;
}

const char* Acquaintance::Get_phone_number()
{
	return this->phone_number;;
}
