#include "Colleague.h"
#include "ContactType.h"

Colleague::Colleague(const char* name, const char* phone_number, const char* company, const char* address)
{
	this->name = name;
	this->phone_number = phone_number;
	this->company = company;
	this->address = address;
}

Colleague::~Colleague()
{
	delete[] name;
	delete[] phone_number;
	delete[] company;
	delete[] address;
}

ContactType Colleague::getType()
{
	return ContactType::COLLEAGUE;
}

const char* Colleague::GetName()
{
	return this->name;
}

const char* Colleague::Get_Phone_Number()
{
	return this->phone_number;;
}

const char* Colleague::Get_Address()
{
	return this->address;
}

const char* Colleague::Get_Company()
{
	return this->company;
}
