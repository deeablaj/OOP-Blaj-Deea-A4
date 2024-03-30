class Number
{
    int base; ///baza initiala a nr
    int base10; ///transformarea nr in baza 10
    char * as_char; ///transformam cifrele numarului in char
public:
    Number(const char* value, int base); // where base is between 2 and 16
    ~Number(); ///destructorul

    // copy/move constructor

    Number(int nr); ///cand avem un nr (implicit in baza 10)
    Number(const Number & d); ///constructorul de copiere
    Number(Number && d); ///constructorul de mutare

    Number& operator = (const Number & d);
    Number& operator = (Number && d);
    Number& operator = (const char * value); 

    friend Number operator+(const Number & n1, const Number & n2);
    friend Number operator-(const Number & n1, const Number & n2);
    friend Number operator+=(Number & n1, Number & n2);

    // operators
    char& operator[](int index);
    bool operator==(const Number& d);
    bool operator!=(const Number& d);
    bool operator>(const Number & d);
    bool operator>=(const Number& d);
    bool operator<(const Number & d);
    bool operator<=(const Number & d);
    
    Number& operator--(); ///operator de decrementare prefixat
    Number& operator--(int); ///operator de decrementare postfixat

    void SwitchBase(int newBase); ///schimbam baza 
    void Print(); ///afisam
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base

private:
    ///apelate de metodele din clasa
    static char * TransformareBaza(const char* value, int baza_i, int baza_f);
    static char * TransformareIntToChar(int nr);
};

