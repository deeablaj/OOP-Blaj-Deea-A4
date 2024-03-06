class Masina
{
    char firma[20];
    float nrLitriCombust, consum, kilometraj;
public:
    void set_firma(char fir[]);
    char* get_firma();
    bool set_nrLitriCombust(float nr);
    float get_nrLitriCombust();
    bool set_consum(float cons);
    float get_consum();
    bool set_kilometraj(float km);
    float get_kilometraj();
    void Bisnitar();
    void Cursa(float distanta);
};
