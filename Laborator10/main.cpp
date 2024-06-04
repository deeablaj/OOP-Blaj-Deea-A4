#include <iostream>
#include <exception>
using namespace std;

class exceptie1 : public exception
{
    virtual const char* what() const throw()
    {
        return "Capacitatea maxima!";

    }
};

class exceptie2 : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este in afara domeniului!";

    }
};


exceptie1 out_capacity;
exceptie2 index_out_of_bounds;



class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

int compare(const int& n1, const int& n2)
{
    if (n1 > n2) return -1;
    if (n1 < n2) return 1;
    return 0;

}

template<class T>
class ArrayIterator
{
private:

    int Current;//pozitia din vector la care suntem
    T** p;///pointer la vectorul care trebuie iterat

public:
    ArrayIterator()//default constructor
    {
        this->Current = 0;
        this->p = nullptr;

    }


    ArrayIterator(T** p, int Current)//pointer catre poz curenta
    {
        this->Current = Current;
        this->p = p;

    }


    ArrayIterator& operator ++ ()
    {
        Current++;
        return (*this);

    }

    ArrayIterator& operator -- ()
    {
        Current--;
        return (*this);

    }


    bool operator==(ArrayIterator<T>& other)
    {
        if (Current == other.Current) return 1;
        return 0;

    }
    bool operator!=(ArrayIterator<T> other)
    {
        if (Current != other.Current) return 1;
        return 0;

    }

    T* GetElement()
    {
        return p[Current];
    }

};
template<class T>
class Array
{
private:

    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista


public:

    Array() // Lista nu e alocata, Capacity si Size = 0
    {
        this->List = nullptr;
        this->Capacity = 0;
        this->Size = 0;

    }


    ~Array() // destructor
    {
        int i;
        for (i = 0; i < Capacity; i++)
            delete[] List[i];
        delete[] List;
        this->Size = 0;
        this->Capacity = 0;

    }


    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        int i;
        this->Capacity = capacity;
        Size = 0;
        List = new T * [capacity];
        for (i = 0; i < capacity; i++)
            List[i] = new T;

    }


    Array(const Array<T>& otherArray) // constructor de copiere
    {
        int i;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (i = 0; i < Capacity; i++)
        {
            List[i] = new T;
            *List[i] = *otherArray.List[i];

        }
    }



    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        if (index < 0 || index >= Size) throw index_out_of_bounds;
        return *List[index];

    }

    const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        if (Size >= Capacity) throw out_capacity;
        *List[Size] = newElem;
        Size++;
        return (*this);

    }



    const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index >= Size) throw index_out_of_bounds;
        if (Size >= Capacity) throw out_capacity;
        int i;
        for (i = Size - 1; i >= index; i--)
            *List[i + 1] = *List[i];
        *List[index] = newElem;
        Size++;
        return (*this);

    }

    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size) throw index_out_of_bounds;
        if (Size + otherArray.Size > Capacity) throw out_capacity;
        if (otherArray.Size == 0) return (*this);

        int i;
        for (i = Size - 1; i >= index; i--)
            *List[i + otherArray.Size] = *List[i];
        for (i = 0; i < otherArray.Size; i++)
            *List[i + index] = *otherArray.List[i];

        Size += otherArray.Size;
        return (*this);

    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        if (index < 0 || index > Size) throw index_out_of_bounds;
        int i;
        for (i = index; i < Size - 1; i++)
            *List[i] = *List[i + 1];

        this->Size--;
        return (*this);

    }
    bool operator==(const Array<T>& otherArray)
    {
        if (Size == otherArray.Size)
        {
            int i;
            for (i = 0; i < Size; i++)
                if (*List[i] != *otherArray.List[i])
                    return false;
            return true;
        }
        return false;

    }




    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        bool ok = 0;
        int i;
        T* aux;
        while (ok == 0)
        {
            ok = 1;
            for (i = 0; i < Size - 1; i++)
                if (*List[i] > *List[i + 1])
                {
                    aux = List[i];
                    List[i] = List[i + 1];
                    List[i + 1] = aux;
                    ok = 0;

                }


        }

    }

    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        bool ok = 0;
        int i;
        T aux;
        while (ok == 0)
        {
            ok = 1;
            for (i = 0; i < Size - 1; i++)
                if (compare(*List[i], *List[i + 1]) > 0)
                {
                    aux = *List[i];
                    *List[i] = *List[i + 1];
                    *List[i + 1] = aux;
                    ok = 0;

                }


        }

    }
    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        bool ok = 0;
        int i;
        T* aux;
        while (ok == 0)
        {
            ok = 1;
            for (i = 0; i < Size - 1; i++)
                if (comparator->CompareElements(List[i], List[i + 1]) > 0)
                {
                    aux = List[i];
                    List[i] = List[i + 1];
                    List[i + 1] = aux;
                    ok = 0;

                }


        }

    }


    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista


    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        int st, dr;
        st = 0;
        dr = Size - 1;
        while (st <= dr)
        {
            int mij = (st + dr) / 2;
            if (*List[mij] == elem) return mij;
            else if (*List[mij] < elem) st = mij + 1;
            else dr = mij - 1;

        }
        return -1;



    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        int st, dr;
        st = 0;
        dr = Size - 1;
        while (st <= dr)
        {
            int mij = (st + dr) / 2;
            if (compare(*List[mij], elem) == 0) return mij;
            else if (compare(*List[mij], elem) > 0) st = mij + 1;
            else dr = mij - 1;

        }
        return -1;



    }

    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        int st, dr;
        st = 0;
        dr = Size - 1;
        while (st <= dr)
        {
            int mij = (st + dr) / 2;
            if (comparator->CompareElements(List[mij], &elem) == 0) return mij;
            else if (comparator->CompareElements(List[mij], &elem) < 0) st = mij + 1;
            else dr = mij - 1;

        }
        return -1;


    }
    int Find(const T& elem) // cauta un element in Array
    {
        int i;
        for (i = 0; i < Size; i++)
            if (*List[i] == elem) return i;
        return -1;

    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {

        int i;
        for (i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0) return i;
        return -1;


    }
    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {

        int i;
        for (i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], &elem) == 0) return i;
        return -1;


    }
    int GetSize()
    {
        return this->Size;

    }
    int GetCapacity()
    {
        return this->Capacity;

    }

    ArrayIterator<T> GetBeginIterator()
    {
        ArrayIterator<T> it(List, 0);
        return it;

    }
    ArrayIterator<T> GetEndIterator()
    {
        ArrayIterator<T> it(List, Size);
        return it;

    }
};

int main()
{

    Array<int> l1(10);
    Array<int> l2(100);

    for (int i = 0; i <= 12; i++)
    {
        try
        {
            l1 += i;
        }
        catch (exception& e)
        {
            cout << "Exceptie la operatorul +=: " << e.what() << endl;
        }
    }

    try
    {
        l1[55] = 26;
    }
    catch (exception& e)
    {
        cout << "Exceptie la operatorul []: " << e.what() << endl;
    }

    for (int i = 0; i <= 8; i++)
    {
        try
        {
            l2 += i;
        }
        catch (exception& e)
        {
            cout << "Exceptie la operatorul +=: " << e.what() << endl;
        }
    }
    cout << "l1: ";
    for (auto it = l1.GetBeginIterator(); it != l1.GetEndIterator(); ++it)
        cout << *it.GetElement() << " ";
    cout << "\n";

    cout << "l2: ";
    for (auto it = l2.GetBeginIterator(); it != l2.GetEndIterator(); ++it)
        cout << *it.GetElement() << " ";
    cout << "\n";

    if (l1 == l2)
        cout << " l1 si l2 sunt egale" << "\n";
    else
        cout << "l1 si l2 nu sunt egale" << "\n";

    try
    {
        l1.Delete(7);
        cout << "Dupa stergere in l1: ";
        for (auto it = l1.GetBeginIterator(); it != l1.GetEndIterator(); ++it)
            cout << *it.GetElement() << " ";
        cout << "\n";
    }
    catch (exception& e)
    {
        cout << "Exceptie la stergere: " << e.what() << "\n";
    }

    try
    {
        l2.Insert(3, 9);
        cout << "Dupa inserare in l2 ";
        for (auto it = l2.GetBeginIterator(); it != l2.GetEndIterator(); ++it)
            cout << *it.GetElement() << " ";
        cout << "\n";
    }
    catch (exception& e)
    {
        cout << "Exceptie la inserare: " << e.what() << "\n";
    }

    l1[4] = 10;


    //
    //  l1.Sort(compare);

    cout << "l1 sortata : ";
    for (auto it = l1.GetBeginIterator(); it != l1.GetEndIterator(); ++it)
        cout << *it.GetElement() << " ";
    cout << "\n";

    l2.Sort();
    cout << "l2 sortata : ";
    for (auto it = l2.GetBeginIterator(); it != l2.GetEndIterator(); ++it)
        cout << *it.GetElement() << " ";
    cout << "\n";

    if (l2.BinarySearch(2, compare) == -1)
        cout << "2 nu a fost gasit in l1" << "\n";
    else
        cout << "2 a fost gasit in lista 1" << "\n";

    try
    {
        l2.Insert(3, l1);
        cout << "l2 dupa inserarea l1: ";
        for (auto it = l2.GetBeginIterator(); it != l2.GetEndIterator(); ++it)
            cout << *it.GetElement() << " ";
        cout << "\n";
    }
    catch (exception& e)
    {
        cout << "Exceptie la inserare:  " << e.what() << "\n";
    }

    return 0;

}
