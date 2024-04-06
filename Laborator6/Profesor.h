#ifndef PROFESOR_H
#define PROFESOR_H
#include "PowerPuffGirl.h"

class Profesor
{
    int numar_ture;
    int numar_fete;
    PowerPuffGirl** girls;
public:
    Profesor(int nr_ingrediente, char ingrediente[50][50]);
    const int GetNumber();
    void AddGirls();
    int GetGirlDamage(int poz);
    int GetGirlHealth(int poz);
    void Modification_damage(int poz, int x);
    void Modification_health(int poz, int x);
    void Modification_vector(int poz);
    int Damage_total_fete();
};

#endif