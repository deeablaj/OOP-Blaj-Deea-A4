#include "ButterCup.h"

ButterCup::ButterCup() 
{
    name = "ButterCup";
    damage = 129;
    health = 2789;
}

void ButterCup::SetName(const char* name) 
{
    this->name = name;
}

const char* ButterCup::GetName() 
{
    return this->name;
}

int ButterCup::GetHealth() 
{
    return this->health;
}

int ButterCup::GetDamage()
{
    return this->damage;
}