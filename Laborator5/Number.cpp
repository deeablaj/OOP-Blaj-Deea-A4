#include "Number.h"
#include <iostream>

using namespace std;

Number::Number(const char* value, int base) 
{
    int y;
    ///this->as_char = (char*)value;
    y = this->base = base;
    this->base10 = 0;
    int lg = 0;
    while (value[lg] != '\0') lg++;
    this->as_char = new char[lg + 1];
    memcpy(this->as_char, value, lg + 1);
    for (int i = 0; i < lg; i++)
        if ('0' <= as_char[i] && as_char[i] <= '9') this->base10 = this->base10 * base + value[i] - '0';
        else this->base10 = this->base10 * base + value[i] - 'A' + 10;
}

Number::Number(int nr) 
{
    this->base = 10;
    this->base10 = nr;
    int NR = nr;
    int lg = 0;
    ///calculam numarul de cifre
    while (NR != 0) 
    { 
        lg++; 
        NR = NR / 10; 
    } 
    this->as_char = new char[lg + 1];///alocam memorie
    for (int i = lg - 1; i >= 0; i--) ///punem cifrele numarului in sir
    {
        this->as_char[i] = (nr % 10) + '0'; ///transformam cifrele in char
        nr = nr / 10;
    }
    this->as_char[lg] = '\0'; 
}

Number::Number(const Number & d) ///constructor de copiere -> din d in this
{
    ///punem baza si nr 
    this->base = d.base;
    this->base10 = d.base10;
    int lg = 0;///calculam lg lui as_char din d pt a putea aloca memorie pt as_char din this
    while (d.as_char[lg] != '\0') lg++;
    this->as_char = new char[lg + 1];
    memcpy(this->as_char, d.as_char, lg + 1);///copiem in this vectorul as_char din d
}

Number::Number(Number && d) ///constructorul de mutare -> muta si sterge d
{
    ///copiem baza si numarul 
    this->base = d.base;
    this->base10 = d.base10;
    ///facem stergerea bazei si a numarului
    d.base = 0;
    d.base10 = 0;
    int lg = 0;///calculam lg lui as_char din d pt a putea aloca memorie pt as_char din this
    while (d.as_char[lg] != '\0') lg++;
    this->as_char = new char[lg + 1];
    memcpy(this->as_char, d.as_char, lg + 1);///copiem in this vectorul as_char din d 
    d.as_char = nullptr;///stergem 
}

Number::~Number() ///destructorul
{
    delete[] this->as_char;
}

Number & Number::operator=(const Number & d) ///constructor de copiere
{
    if (this != & d)
    {
        delete[] this->as_char;///stergem ce era inainte in this
        ///copiem baza si numarul
        this->base = d.base;
        this->base10 = d.base10;
        int lg = 0;
        while (d.as_char[lg] != '\0') lg++;///calculam lungimea
        this->as_char = new char[lg + 1];
        memcpy(this->as_char, d.as_char, lg + 1);///copiem din d in this vectorul de char
    }
    return *this;
}

Number & Number::operator=(Number && d) ///constructor de mutare
{
    if (this != & d) 
    {
        delete[] this->as_char;///eliberam this
        ///punem baza si numarul in d
        this->base = d.base;
        this->base10 = d.base10;
        int lg = 0;
        while (d.as_char[lg] != '\0') lg++;///calculam lungimea sirului
        this->as_char = new char[lg + 1];
        memcpy(this->as_char, d.as_char, lg + 1);///copiem vectorul de tip char in this din d
        ///stergem numarul, baza si sirul din d
        d.base = 0;
        d.base10 = 0;
        d.as_char = nullptr;
    }
    return *this;
}

Number & Number::operator=(const char* value) 
{
    //transformam sirul din b10 in baza lui
    char* rez = Number::TransformareBaza(value, 10, this->base);///convertim sirul care e un nr in b10 intr-unul care e un nr in base
    int lg = 0;
    while (rez[lg] != '\0') lg++;
    delete[] this->as_char;
    this->as_char = new char[lg + 1];///alocam memorie
    memcpy(this->as_char, rez, lg + 1);
    this->base10 = 0;
    for (int i = 0; value[i] != 0; i++)///il transformam in baza 10
        this->base10 = this->base10 * base + value[i] - '0';
    return *this;
}

void Number::SwitchBase(int newBase)
{
    if (this->base == newBase) return;///daca baza coincide o lasam asa
    char* nou = Number::TransformareBaza(this->as_char, this->base, newBase);///convertim in noua baza
    this->base = newBase;///actualizam baza
    delete[] this->as_char;///stergem ce era inainte in this
    int lg = 0;
    while (nou[lg] != '\0') lg++;
    this->as_char = new char[lg + 1];
    memcpy(this->as_char, nou, lg + 1);
    delete[] nou;
}

void Number::Print()
{
    cout << "Numarul: " << this->as_char << "\n" << "Baza numarului: " << this->base << "\n" << "Reprezentarea numarului in baza 10: " << this->base10 << "\n";
    cout << '\n';
}

int Number::GetDigitsCount()
{
    int ct = 0;
    while (this->as_char[ct] != '\0') ct++;
    return ct;
}

int Number::GetBase()
{
    return this->base;
}

Number operator+(const Number & n1, const Number & n2) 
{
    ///trebuie sa folosim baza mai mare
    ///cautam baza mai mare
    int b = n1.base;
    if (n2.base > b) b = n2.base;
    int sum = n1.base10 + n2.base10;
    char * nou = Number::TransformareIntToChar(sum);///transformam suma intr-un sir de caractere
    nou = Number::TransformareBaza(nou, 10, b);/// baza 10 -> trecem in baza base
    Number n (nou, b);///rezultatul adunarii il punem intr-un obiect nou creat
    delete[] nou;
    return n;///returnam rezultatul adunarii
}

Number operator+=(Number & n1, Number & n2)
{
    n1.base10 = n1.base10 + n2.base10;
    char* nou = Number::TransformareIntToChar(n1.base10);
    nou = Number::TransformareBaza(nou, 10, n1.base);/// baza 10 -> trecem in baza lui n1
    int lg = 0;
    while (nou[lg] != '\0') lg++;
    delete[] n1.as_char;///stergem ce era in el anterior
    n1.as_char = new char[lg + 1];
    memcpy(n1.as_char, nou, lg + 1);
    return n1;///returnam rezultatul sumei
}

Number operator-(const Number & n1, const Number & n2) 
{
    ///cautam baza mai mare
    int b = n1.base;
    if (n2.base > b) b = n2.base;
    int sum = n1.base10 - n2.base10;///efectual scaderea
    char* nou = Number::TransformareIntToChar(sum);///transformam rezultatul intr-un sir de caractere
    nou = Number::TransformareBaza(nou, 10, b);/// baza 10 -> trecem in baza base
    Number n(nou, b);///cream un nou obiect
    delete[] nou;
    return n;///returnam rezultatul scaderii
}

char & Number::operator[](int index) 
{
    return this->as_char[index];
}

bool Number::operator<(const Number & d)
{
    if (this->base10 < d.base10) 
    {
        return 1;
    }
    return 0; 
}

bool Number::operator<=(const Number & d)
{
    if (this->base10 <= d.base10)
    {
        return 1;
    }
    return 0;
}

bool Number::operator>(const Number & d)
{
    if (this->base10 > d.base10) 
    {
        return 1;
    }
    return 0; 
}

bool Number::operator>=(const Number & d)
{
    if (this->base10 >= d.base10)  
    {
        return 1;
    }
    return 0; 
}

bool Number::operator==(const Number & d)
{
    if (this->base10 == d.base10)  
    {
        return 1;
    }
    return 0; 
}

bool Number::operator!=(const Number & d)
{
    if (this->base10 != d.base10)  
    {
        return 1;
    }
    return 0; 
}

Number & Number::operator--() ///operator de decrementare prefixat (eliminam bitul din stanga)
{
    int lg = 0;
    while (this->as_char[lg] != '\0') lg++;
    if (lg == 0) return *this;
    ///permutam cu o pozitie la stanga
    for (int i = 0; i < lg; ++i)
        this->as_char[i] = this->as_char[i + 1];
    this->base10 = 0;
    for (int i = 0; i < lg - 1; i++)
        if ('0' <= as_char[i] && as_char[i] <= '9') 
            this->base10 = this->base10 * base + as_char[i] - '0';
        else 
            this->base10 = this->base10 * base + as_char[i] - 'A' + 10;
    return *this;
}

Number & Number::operator--(int) ///operator de decrementare postfixat (eliminam bitul din dreapta)
{
    int  lg = 0;
    while (this->as_char[lg] != '\0') lg++;
    this->as_char[lg - 1] = '\0'; ///stergem elementul de pe ultima pozitie
    this->base10 = 0;
    for (int i = 0; i < lg - 1; i++)
        if ('0' <= this->as_char[i] && this->as_char[i] <= '9') 
            this->base10 = this->base10 * base + this->as_char[i] - '0';
        else 
            this->base10 = this->base10 * base + this->as_char[i] - 'A' + 10;
    return *this;
}

char * Number::TransformareBaza(const char* value, int baza_i, int baza_f)
{
    ///transformam din baza curenta in baza 10
    int lg = 0,sol=0;
    while (value[lg] != '\0') lg++;
    for (int i = 0; i < lg; ++i) ///parcuregm vectorul
    {
        int c = 0;
        if ('0' <= value[i] && value[i] <= '9') c = value[i] - '0';
        if ('A' <= value[i] && value[i] <= 'F') c = value[i] - 'A' + 10;
        sol = sol * baza_i + c;
    }
    /// b10 -> baza_f
    char * nou = new char[16]; ///nu poate avea mai mult de 16 cifre
    int i = 0;
    while (sol != 0)
    {
        int r = sol % baza_f;///luam resturile
        char cifra;///transformam cifra in char
        if (r < 10) cifra = r + '0';
        else cifra = r + 'A' - 10;
        nou[i++] = cifra;
        sol = sol / baza_f;
    }
    if (i == 0)   nou[i++] = '0'; 
    nou[i] = '\0'; 
    ///in nou cifrele sunt puse invers si trebuie sa le inversam 
    for (int j = 0; j < i / 2; ++j)
    {
        char aux = nou[j];
        nou[j] = nou[i - j - 1];
        nou[i - j - 1] = aux;
    }
    return nou;
}

char * Number::TransformareIntToChar(int nr)
{
    int NR = nr, lg = 0;
    while (NR != 0) 
    { 
        lg++; 
        NR = NR / 10; 
    }
    char* value = new char[lg + 1];
    for (int i = lg - 1; i >= 0; i--)
    {
        value[i] = (nr % 10) + '0'; ///trecem cifrele in char
        nr /= 10;
    }
    value[lg] = '\0';
    return value;
}

