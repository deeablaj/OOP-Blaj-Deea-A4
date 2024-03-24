#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdarg>
#include "Sort.h"
#include <cstring>

using namespace std;

Sort::Sort(int nrElemente, int min, int max) ///bulinuta 1
{
    this->nrElemente=nrElemente;
    elemente = new int[nrElemente];
    for (int i = 0; i < nrElemente; i++)
       elemente[i] = min + rand() % (max - min + 1);
}

Sort::Sort(int nrElemente, char s) : elemente(new int[nrElemente] {68, 29, 39, 23, 71, 22, 26, 11, 79, 70}) ///bulinuta 2
{
    this->nrElemente = nrElemente;
}


Sort::Sort(int v[100], int nrElemente) ///bulinuta 3
{
    this->nrElemente = nrElemente;
    this->elemente = new int[nrElemente];
    for (int i = 0; i < nrElemente; i++)
        this->elemente[i] = v[i];
}

Sort :: Sort(int nrElemente, ...) ///bulinuta 4
{
    this->nrElemente = nrElemente;
    this->elemente = new int[nrElemente];
    va_list args;
    va_start(args, nrElemente);
    for (int i = 0; i < nrElemente; i++)
        this->elemente[i] = va_arg(args, int);
    va_end(args);
}

Sort::Sort(char s[]) ///bulinuta 5
{
    char sep[] = ",", * p, cuv[100];
    int ct = 0; 
    int a[100],nr;
    p = strtok(s, sep);
    while (p!=0)
    {
        strcpy_s(cuv, p);
        nr = 0;
        for (int i = 0; i < strlen(cuv); i++)
        {
            int c = cuv[i] - '0';
            nr = nr * 10 + c;
        }
        a[ct++] = nr;
        p = strtok(0, sep);
    }
    this->nrElemente = ct;
    this->elemente = new int[ct];
    for (int i = 0; i < ct; i++)
        this->elemente[i] = a[i];
}

Sort::~Sort()
{
    delete[] this->elemente;
}

void Sort::InsertSort(bool ascendent)
{
    int nr;
    if (ascendent == false) nr = 1;
    else nr = -1;
    for (int i = 0; i < this->nrElemente; i++)
    {
        int aux = this->elemente[i];
        int j = i - 1;
        while (j >= 0 && nr * this->elemente[j] < nr * aux)
        {
            this->elemente[j + 1] = this->elemente[j];
            j--;
        }
        elemente[j + 1] = aux;
    }
}

void QS(int *elemente,int nrElemente,bool ascendent)
{
    int aux, nr;
    if (ascendent == false) nr = 1;
    else nr = -1;

    if (nrElemente <= 1) return;
    // la pozitia n-1 se afla pivotul
    int p1 = 0;
    int p2 = nrElemente-1;

    while (p1 <= p2)
    {   // p1==p2 p1==p2+1
        while (nr*elemente[p1] < nr*elemente[nrElemente - 1] && p1 < nrElemente) p1++;
        while (nr*elemente[p2] >= nr*elemente[nrElemente - 1] && p2 >= 0) p2--;
        if (p1 < p2)
        {
            int aux = elemente[p1];
            elemente[p1] = elemente[p2];
            elemente[p2] = aux;
        }
    }
    aux = elemente[p1];
    elemente[p1] = elemente[nrElemente - 1];
    elemente[nrElemente - 1] = aux;
    QS(elemente, p1,ascendent);
    QS(elemente + p1 + 1, nrElemente - p1 - 1,ascendent);
}

void Sort::QuickSort(bool ascendent)
{
    QS(this->elemente, this->nrElemente,ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    int nr;
    if (ascendent == false) nr = 1;
    else nr = -1;
    bool ok = 0;
    int aux;
    while (ok == 0)
    {
        ok = 1;
        for (int i = 0; i < this->nrElemente - 1; i++)
            if (nr * elemente[i] < nr * elemente[i + 1])
            {
                ok = 0;
                aux = elemente[i];
                elemente[i] = elemente[i + 1];
                elemente[i + 1] = aux;
            }
    }
}

void Sort::Print()
{
    for (int i = 0; i < this->nrElemente; ++i)
        cout << elemente[i] << " ";
    cout << endl;
}

int Sort::GetElementsCount()
{
    return this->nrElemente;
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < this->nrElemente)
        return elemente[index];
    else return -1;
}
