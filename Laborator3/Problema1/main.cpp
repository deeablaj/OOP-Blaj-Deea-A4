#include <iostream>
#include "Math.h"

using namespace std;

int main() {

	cout << Math::Add(3,7) << endl;
	cout << Math::Add(5, 7, 9) << endl;
	cout << Math::Add(2.1, 4.8) << endl;
	cout << Math::Add(2.8, 5.1, 6.7) << endl;
	cout << Math::Mul(3, 7) << endl;
	cout << Math::Mul(5, 7, 9) << endl;
	cout << Math::Mul(2.1, 4.8) << endl;
	cout << Math::Mul(2.8, 5.1, 6.7) << endl;
	cout << Math::Add("6", "15") << endl;
	return 0;
}