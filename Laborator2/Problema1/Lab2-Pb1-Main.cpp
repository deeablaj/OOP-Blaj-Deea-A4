#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
    NumberList listaMea;
    int x;
    cin >> x;
    listaMea.Init();
    while (x!=0)
    {
        listaMea.Add(x);
        cin >> x;
    }
    listaMea.Sort();
    listaMea.Print();
    return 0;
}