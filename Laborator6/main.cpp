/*
* Profesorul X a decis sa faca mai multe fetite PowerPuff, si evident are nevoie de sugar/spice and everything nice
* pentru ca ii este lene, da o comanda cu Glovo, si ii spune curierului sa-i aduca
* tot zaharul/condimentele/fainutzul din magazin
*
* Implementati clasele:
* clasa abstracta PowerPuffGirl,
* si clasele care mostenesc interfata PowerPuffGirl : Bubbles, Blossom, ButterCup
*
* fiecare dintre fetite, are
*   damage
*   health
*
*
* clasa Profesor
*   care primeste o lista de ingrediente pe care a reusit curierul sa le cumpere,
*   ex : sugar, spice, spice, everything_nice, sugar
*
*   ca sa creeze o fetita powerpuff are nevoie de
*   1x sugar
*   1x spice
*   1x everything_nice
*
*   o sa creeze cat de multe fetite poate,
*   cu o sansa de 33% sa fie ori un ButterCup ori un Blossom ori un Bubbles
*
*
* clasa MojoJojo
*   care are
*       damage
*       health
*
* Si apoi implementati o metoda care simuleaza lupta intre MojoJojo si fetitele powerpuff ale profesorului
*
* daunele se efectueaza in ture
* la incepeutul turei, fetitetele dau damage lui MojoJojo
* la finalul turei MojoJojo alege o fetita aleatoare pe care sa o loveasca
*
* scrieti
* o metoda care afiseaza castigatorul bataliei, si statistici despre batalie :
* 	cate ture a durat lupta/cate fetite au murit/etc..
* si o metoda care sa afiseze cate fetite au supravietuit si cu cata viata
*/

#include <iostream>
#include <cstdlib> 
#include <cstring>
#include "PowerPuffGirl.h"
#include "Profesor.h"
#include "MojoJojo.h"
using namespace std;

void Battle(Profesor & profesor,MojoJojo mojo)
{
    ///1. lovesc fetele
    ///2. loveste MojoJojo
    int nr_fete_init = profesor.GetNumber();
    int nr_ture = 0;
    profesor.AddGirls();
    while (mojo.GetMojoJojoHealth() > 0 && profesor.GetNumber() > 0) ///verificam daca inca poate exista lupta
    {
        nr_ture++;
        int power_fete = profesor.Damage_total_fete();///damage-ul fetelor se aduna
        mojo.Atac(power_fete);
        int nr = rand() % profesor.GetNumber(); ///MojoJojo ataca o fetita random
        int fata = profesor.GetGirlHealth(nr) - mojo.GetMojoJojoDamage();
        if (fata < 0) fata = 0;
        profesor.Modification_health(nr, fata);///modif health pt fetita atacata
        if (fata == 0) ///eliminam feta daca nu mai are health
        {
            profesor.Modification_vector(nr);
        }
    }
    cout << "Castigatorul luptei este ";
    if (mojo.GetMojoJojoHealth() == 0) cout << "Profesorul" << '\n';
    else cout << "MojoJojo" <<'\n';
    cout << "Lupta a durat un numar de " << nr_ture << " ture" << '\n';
    cout << "Au murit un numar de " << nr_fete_init - profesor.GetNumber() << " fetite" << '\n';
}

void Statistici_Lupta(Profesor profesor)
{
    cout << "Au supravietuit " << profesor.GetNumber() << " fetite:" << '\n';
    
    if (profesor.GetNumber() != 0)
    {
        for (int i = 0; i < profesor.GetNumber(); ++i)
            if (profesor.GetGirlHealth(i) != 0)
            {
                cout << "Fetita " << i << " cu health " << profesor.GetGirlHealth(i) <<", ";
                if (i % 3 == 0)  cout << " Bubbles";
                else if (i % 3 == 1) cout<<" Blossom";
                else  cout<<" ButterCup";
                cout << '\n';
            }

    }
}

int main() 
{
    char ingrediente[50][50] = { "sugar", "spice", "everything_nice", "sugar", "sugar", "sugar", "sugar","everything_nice" };
    Profesor profesor(8, ingrediente);
    MojoJojo mojo;
    Battle(profesor, mojo);
    Statistici_Lupta(profesor);
   
    return 0;
}