#ifndef BUBBLES_H
#define BUBBLES_H
#include "PowerPuffGirl.h"

class Bubbles : public PowerPuffGirl 
{
public:
    Bubbles();
    void SetName(const char* name);
    const char* GetName();
    int GetHealth();
    int GetDamage();
};

#endif
