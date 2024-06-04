#pragma once
#include "ContactType.h"
class Contact
{
public:
	const char* name;
	virtual const char * GetName() = 0;
	virtual ContactType getType() = 0;
};

