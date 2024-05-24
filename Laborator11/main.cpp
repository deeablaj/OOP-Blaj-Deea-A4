#include <iostream>

using namespace std;

template <typename K>

class Nr
{
private:
    K* vect;
    int n = 0;
public:
    Nr()
    {
        n = 0;
    }
    ~Nr()
    {
        delete[] vect;
    }
    void Add(K x)
    {
        K* temp = new K[n + 1];
        for (int i = 0; i < this->n; ++i)
            temp[i] = vect[i];
        temp[n++] = x; ///trebuie n++ pentru a putea adauga elem si a le creste numarul
        delete[] vect;
        vect = temp;
    }
    int Count()
    {
        return this->n;
    }
    void Sortare()
    {
        bool ok = 0;
        while (!ok)
        {
            ok = 1; ///aici ok=1 nu ok=0
            for (int i = 0; i < n - 1; ++i) ///nu trebuia mai mic egal decat n-1 -> trebuie mai mic strict
                if (vect[i] > vect[i + 1])
                {
                    ok = 0; ///aici nu trebuia ok=1 -> trebuie ok=0
                    K aux = vect[i]; ///aux trebuie sa aiba acelasi tip de date ca vectorul, nu tipul int mereu
                    vect[i] = vect[i + 1];
                    vect[i + 1] = aux;
                }
        }
    }
    void Afisare()
    {
        for (int i = 0; i < this->n; ++i) cout << vect[i] << " ";
        cout << "\n";
    }
};


int main()
{
    Nr<int> a;
    a.Add(10);
    a.Add(5);
    a.Add(2);
    a.Add(6);
    a.Add(15);
    a.Afisare();
    a.Sortare();
    a.Afisare();
    a.Add(4);
    a.Add(9);
    a.Afisare();
    a.Sortare();
    a.Afisare();
    return 0;
}
