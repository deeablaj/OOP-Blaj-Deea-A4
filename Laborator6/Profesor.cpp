#include <iostream>
#include "PowerPuffGirl.h"
#include "Profesor.h"
#include "Blossom.h"
#include "Bubbles.h"
#include "ButterCup.h"

using namespace std;

Profesor::Profesor(int nr_ingrediente, char ingrediente[50][50])
{
    int sugar = 0,spice = 0,everything_nice = 0,M=-1;
    
    for (int i = 0; i < nr_ingrediente; i++)
        if (ingrediente[i][1] == 'u') sugar++;
        else if (ingrediente[i][1] == 'p') spice++;
        else everything_nice++;
    if (sugar < spice) M = sugar;
    else M= spice;
    if (everything_nice < M) M = everything_nice;
    numar_fete = M;
    girls = new PowerPuffGirl * [numar_fete];

    for (int i = 0; i < numar_fete; i++)
        girls[i] = nullptr;
}

const int Profesor::GetNumber()
{
    return this->numar_fete;
}

void Profesor::AddGirls()
{
    for (int i = 0; i < numar_fete; i++)
    {
        if (i % 3 == 0)  girls[i] = new Bubbles();
        else if (i % 3 == 1) girls[i] = new Blossom();
        else  girls[i] = new ButterCup();
    }
}

int Profesor::GetGirlDamage(int poz)
{
    return girls[poz]->GetDamage();
}

int Profesor::GetGirlHealth(int poz)
{
    return girls[poz]->GetHealth();
}

void Profesor::Modification_damage(int poz, int x)
{
    girls[poz]->damage = x;
}

void Profesor::Modification_health(int poz, int x)
{
    girls[poz]->health = x;
}

void Profesor::Modification_vector(int poz)
{
    swap(girls[poz], girls[this->numar_fete - 1]);
    this->numar_fete--;
}


int Profesor::Damage_total_fete()
{
    int sum = 0;
    int x = this->GetNumber();
    for (int i = 0; i < x; ++i)
    {
        sum += this->GetGirlDamage(i);
    }
    return sum;
}