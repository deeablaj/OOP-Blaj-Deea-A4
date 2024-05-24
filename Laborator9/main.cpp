#include <cstring>
#include <iostream>

using namespace std;

template <typename K, typename V>

class Map
{
private:
    int ct = 0;
    struct MapStructure
    {
        K key;
        V value;
        int index;

    };
    MapStructure* elements;

public:
    Map()
    {
        this->elements = nullptr;
        this->ct = 0;
    }

    ~Map()
    {
        delete[] elements;
    }

    int Count() ///returneaza numarul elementelor dintr-o mapa
    {
        return ct;
    }

    void Clear() ///stergem intreaga mapa    
    {
        delete[] elements;
        elements = nullptr;
        ct = 0;
    }

    void Set(const K& key, const V& value)
    {  
        ///cautam elementul pentru a vedea daca acesta exista deja
        int i;
        for (i = 0; i < ct; i++)
            if (elements[i].key == key)
            { 
                elements[i].value = value;
                return;  ///daca am gasit, iesim
            }
        ///daca nu l-am gasit, il cream si ii asociem o valoare
        MapStructure* aux = new MapStructure[ct + 1];
        for (i = 0; i < ct; i++)
            aux[i] = elements[i];
        aux[ct].key = key;
        aux[ct].value = value;
        aux[ct].index = ct;
        ct++;
        delete[] elements;
        elements = aux;

    }

    bool Get(const K& key, V& value)
    {
        for (int i = 0; i < ct; i++)

            if (elements[i].key == key)
            {
                value = elements[i].value;
                return true;
            }
        return false;
    }

    bool Delete(const K& key) /// sterge o anumita cheie (daca acesta exista) 
    {
        int i, j;
        for (i = 0; i < ct; i++)
        {
            if (elements[i].key == key)
            {
                MapStructure* aux = new MapStructure[ct - 1];
                for (j = 0; j < i; j++)
                    aux[j] = elements[j];
                for (j = i; j < ct - 1; j++)
                {
                    elements[j + 1].index--;
                    aux[j] = elements[j + 1];

                }
                ct--;
                delete[] elements;
                elements = aux;
                return true;

            }

        }
        return false;

    }


    bool Includes(const Map<K, V>& map) ///verifica daca un map e inclus in alt map
    {
        bool ok;
        if (map.ct > ct) return false;

        ////verificam daca toate cheile dintr-o mapa coincid cu toate cheile din alta mapa
        
        for (int i = 0; i < map.ct; i++)
        {
            ok = 0;
            for (int j = 0; j < ct; j++)
                if (map.elements[i].key == elements[j].key) { ok = 1; break; }
            if (ok == 1) return false;
        }
        return true;

    }

    V& operator[](const K& key)
    {
        for (int i = 0; i < ct; i++)
            if (elements[i].key == key) return elements[i].value;

        ///daca nu exista, o cream
        Set(key, "");
        return elements[ct - 1].value;

    }
    const MapStructure* begin() const
    {
        return &elements[0];
    }

    const MapStructure* end() const
    {
        return &elements[ct];
    }

};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}