#include "Friend.h"
#include "Contact.h"
#include "ContactType.h"
Friend::Friend(const char* nume, const char* phone_number, const char* address, const char* date_of_birth)
{
	this->name = nume;
	this->date_of_birth = date_of_birth;
	this->address = address;
	this->phone_number = phone_number;
}

Friend::~Friend()
{
	delete [] name;
	delete [] date_of_birth;
	delete [] address;
	delete [] phone_number;
}

const char* Friend::GetName()
{
	return this->name;
}

ContactType Friend::getType()
{
	return ContactType::FRIEND;
}

const char* Friend::Get_Phone_Number()
{
	return this->phone_number;
}

const char* Friend::Get_Address()
{
	return this->address;
}

const char* Friend::Get_date_of_birth()
{
	return this->date_of_birth;
}
