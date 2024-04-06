#ifndef BLOSSOM_H
#define BLOSSOM_H
#include "PowerPuffGirl.h"

class Blossom : public PowerPuffGirl 
{
public:
    Blossom();
    void SetName(const char* name);
    const char* GetName();
    int GetHealth();
    int GetDamage();
};

#endif