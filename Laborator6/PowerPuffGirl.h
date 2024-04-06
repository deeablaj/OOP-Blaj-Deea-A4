#ifndef POWERPUFFGIRL_H
#define POWERPUFFGIRL_H

class PowerPuffGirl 
{
public:
    int damage, health;
    const char* name;
    virtual void SetName(const char* name) = 0;
    virtual const char* GetName() = 0;
    virtual int GetHealth() = 0;
    virtual int GetDamage() = 0;
};

#endif