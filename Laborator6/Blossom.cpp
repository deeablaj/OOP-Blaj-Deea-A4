#include "Blossom.h"

Blossom::Blossom() 
{
    name = "Blossom";
    damage = 65;
    health = 1760;
}

void Blossom::SetName(const char* name) 
{
    this->name = name;
}

const char* Blossom::GetName() 
{
    return this->name;
}

int Blossom::GetHealth() 
{
    return this->health;
}

int Blossom::GetDamage()
{
    return this->damage;
}