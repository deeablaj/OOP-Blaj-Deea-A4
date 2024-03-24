// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
    int v[5] = { 1, 2, 3, 4, 5 };

    cout << "cerinta 1: ";
    Sort c1(10,15,100); 
    c1.Print();
    c1.BubbleSort(true);
    c1.Print();
    cout << '\n';

    cout << "cerinta 2: ";
    Sort c2(10, 'A'); ///am adaugat un char pentru a evita ambiguitatea
    c2.Print();
    c2.QuickSort(false);
    c2.Print();
    cout << '\n';

    cout << "cerinta 3: ";
    Sort c3(v, 5);
    c3.Print();
    c3.InsertSort(false);
    c3.Print();
    cout << '\n';

    cout << "cerinta 4: ";
    Sort c4(8, 2, 3, 4, 8, 9, 6, 10, 12); 
    c4.Print();
    cout << c4.GetElementsCount()<<'\n';
    cout << '\n';

    cout <<"cerinta 5: ";
    char* s = new char[101] {"99,8,100,25,75"};
    Sort c5(s); 
    c5.Print();
    cout << c5.GetElementFromIndex(0);
}