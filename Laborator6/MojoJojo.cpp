#include "MojoJojo.h"

MojoJojo::MojoJojo() 
{
    name = "MojoJojo";
    damage = 300;
    health = 1500;
}

const char* MojoJojo::GetName() 
{
    return this->name;
}

int MojoJojo::GetMojoJojoHealth() 
{
    return this->health;
}

int MojoJojo::GetMojoJojoDamage() 
{
    return this->damage;
}

void MojoJojo::Atac(int x)
{
    if (this->health >= x) this->health -= x;
    else this->health = 0;
}

void MojoJojo::Modif_Damage(int x)
{
    this->damage = x;
}
