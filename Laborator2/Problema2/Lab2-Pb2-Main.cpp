#include <iostream>
#include "Masina.h"
using namespace std;

int main()
{
    Masina vehicul;

    char fir[20];
    cin >> fir;
    vehicul.set_firma(fir);
    ///cout << vehicul.get_firma();

    float nr;
    cin >> nr;
    vehicul.set_nrLitriCombust(nr);

    float cons;
    cin >> cons;
    vehicul.set_consum(cons);

    float km;
    cin >> km;
    vehicul.set_kilometraj(km);

    vehicul.Bisnitar();
    cout << vehicul.get_kilometraj()<<endl;
   

    float distanta;
    cin >> distanta;
    vehicul.Cursa(distanta);
    cout << vehicul.get_kilometraj()<<endl;
    cout << vehicul.get_nrLitriCombust()<<endl;
    return 0;
}