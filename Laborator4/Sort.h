class Sort
{
    // add data members
    int* elemente;
    int nrElemente;
public:
    // add constuctors
    Sort(int nrElemente, int min, int max); ///bulina 1
    Sort(int nrElemente, char s);///bulinuta 2
    Sort(int v[100], int nrElemente); ///bulina 3
    Sort(int nrElemente, ...); ///bulina 4
    Sort(char s[]); ///bulina 5
    ~Sort(); ///destructorul
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
