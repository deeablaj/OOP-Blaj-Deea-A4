#include <iostream>
#include "NumberList.h"
using namespace std;

void NumberList::Init()
{
    this->count = 0;
}

void NumberList::Add(int x)
{
    int dim = 10;
    if (this->count >= dim)
    {
        dim = dim * 2;
        int* aux = (int*)realloc(numbers, dim * sizeof(int));
        numbers = aux;
        numbers[this->count] = x;
        this->count++;
    }
    else
    {
        this->numbers[this->count] = x;
        this->count++;
    }
}

void NumberList::Sort()
{
    bool sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        for (int i = 0; i < this->count - 1; i++)
            if (this->numbers[i] > this->numbers[i + 1])
            {
                int aux = this->numbers[i];
                this->numbers[i] = this->numbers[i + 1];
                this->numbers[i + 1] = aux;
                sorted = 0;
            }
    }
}

void NumberList::Print()
{
    for (int i = 0; i < this->count; i++)
    {
        cout << this->numbers[i] << " ";
        /// printf("%d", this->numbers[i]);
    }
    ///printf("\n");
}