#ifndef MOJOJOJO_H
#define MOJOJOJO_H

class MojoJojo 
{
    int damage, health;
    const char* name;
public:
    MojoJojo();
    const char* GetName();
    int GetMojoJojoHealth();
    int GetMojoJojoDamage();
    void Atac(int x);
    void Modif_Damage(int x);
};

#endif

