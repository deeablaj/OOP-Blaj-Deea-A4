#include "Math.h"
#include <cstdarg>
#include <cstdlib>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return (int)(a + b);
}

int Math::Add(double a, double b, double c)
{
	return (int)(a + b + c);
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return (int)(a + b);
}

int Math::Mul(double a, double b, double c)
{
	return (int)(a * b * c);
}

int Math::Add(int count, ...)
{
	va_list varargs; ///variable arguments list
	va_start(varargs, count); ///start using the arguments list

	int s = 0;
	for (int i = 0; i < count; i++)
		s = s + va_arg(varargs, int); ///adding the current argument from the argument list to the sum

	va_end(varargs); ///finish using the arguments list
	return s;
}

char * Math::Add(const char * s1, const char * s2)
{
	if (s1 == nullptr || s2 == nullptr) ///if one of the strings is nullptr, this function will return nullptr
		return nullptr;

	int nr1 = atoi(s1); ///convert the first string to int
	int nr2 = atoi(s2); ///convert the second string to int
	int nr, ct=0, x;
	char* rez = new char[ct + 1]; ///the result

	nr = nr1 + nr2;
	x = nr;

	while (x!=0) ///counting the number of digits of the number
	{
		ct++;
		x = x / 10;
	}

	for (int i = ct - 1; i >= 0; i--)
	{
		rez[i] = char ((nr % 10) + '0');
		nr = nr / 10;
	}
	rez[ct] = 0;

	return rez;
}