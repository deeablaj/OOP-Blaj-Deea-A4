#include "Bubbles.h"

Bubbles::Bubbles()
{
    name = "Bubbles";
    damage = 350;
    health = 1800;
}

void Bubbles::SetName(const char* name)
{
    this->name = name;
}

const char* Bubbles::GetName()
{
    return this->name;
}

int Bubbles::GetHealth()
{
    return this->health;
}

int Bubbles::GetDamage()
{
    return this->damage;
}