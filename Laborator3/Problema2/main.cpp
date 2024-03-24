#include <iostream>
#include "Canvas.h"

using namespace std;

int main() {

	Canvas canvas(26, 26);

	canvas.DrawLine(15, 15, 20, 20, '*');
	canvas.Print();
	canvas.Clear();

	canvas.DrawCircle(10, 10, 5, '$');
	canvas.Print();
	canvas.Clear();

	canvas.FillCircle(10, 10, 5, '#');
	canvas.Print();
	canvas.Clear();

	canvas.DrawRect(10, 10, 25, 25, '@');
	canvas.Print();
	canvas.Clear();

	canvas.FillRect(10, 10, 25, 25, '%');
	canvas.Print();

	return 0;
}