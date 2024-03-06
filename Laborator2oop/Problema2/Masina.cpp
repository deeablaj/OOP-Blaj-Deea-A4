#include "Masina.h"
#include <iostream>
#include <cstring>
using namespace std;

void Masina::set_firma(char fir[])
{
    strcpy_s(this->firma, fir);
}

char* Masina::get_firma()
{
    return this->firma;
}

bool Masina::set_nrLitriCombust(float nr)
{
    if (nr >= 0) ///nu poate fi un numar negativ
    {
        this->nrLitriCombust = nr;
        return true;
    }
    return false;
}

float Masina::get_nrLitriCombust()
{
    return this->nrLitriCombust;
}

bool Masina::set_consum(float cons)
{
    if (cons < 0) return 0; ///consumul nu poate fi un numar negativ si nici nul
    this->consum = cons;
    return true;
}

float Masina::get_consum()
{
    return this->consum;
}

bool Masina::set_kilometraj(float km)
{
    if (km >= 0) ///nu poate fi un numar negativ
    {
        this->kilometraj = km;
        return true;
    }
    return false;
}

float Masina::get_kilometraj()
{
    return this->kilometraj;
}

void Masina::Bisnitar()
{
    if (this->kilometraj <= 1000) this->kilometraj = 0;
    else this->kilometraj = this->kilometraj - 1000;
    ///cout << kilometraj << "dhs" << endl;
}

void Masina::Cursa(float distanta)
{
    float k;
    this->kilometraj = this->kilometraj + distanta;
    ///cout <<"Noul kilometraj:"<< kilometraj << endl; ///noul kilometraj
    k = distanta * this->consum / 100;
    this->nrLitriCombust = this->nrLitriCombust - k;
    ///cout << "Noul nr de litri combust:"<< nrLitriCombust << endl; ///noul numar de litri
}