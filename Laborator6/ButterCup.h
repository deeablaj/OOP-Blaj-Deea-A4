
#ifndef BUTTERCUP_H
#define BUTTERCUP_H
#include "PowerPuffGirl.h"

class ButterCup : public PowerPuffGirl
{
public:
     ButterCup();
     void SetName(const char* name);
     const char* GetName();
     int GetHealth();
     int GetDamage();
};

#endif

