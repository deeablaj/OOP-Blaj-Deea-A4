#include "Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height) 
{
    this->width = width;
    this->height = height;
    ///alocam dinamic memorie pt o matrice  in care fiecare element este un pointer catre un tablou de caractere alocat dinamic
    this->matrix = new char* [height]; 

    for (int i = 0; i < height; i++) ///parcurgere matrice
    {
        this->matrix[i] = new char[width]; 
        for (int j = 0; j < width; j++) 
        {
            this->matrix[i][j] = ' ';
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < this->height; i++) ///parcurgem matricea
    {
        for (int j = 0; j < this->width; j++)
        {
            ///pt fiecare pct calc dist de la el la centrul cercului cu form dist
            int dx = i - x;
            int dy = j - y;
            double dist = sqrt(dx * dx + dy * dy);

            if (abs(dist - ray) < 0.25) ///dist trebuie sa fie aprox egala cu raza pt a fi pe conturul cercului
            {
                this->matrix[i][j] = ch; ///punem caracterul
            }
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < this->height; i++) ///parcurgem matricea
    {
        for (int j = 0; j < this->width; j++)
        {
            ///pt fiecare pct calc dist de la el la centrul cercului cu form dist
            int dx = i - x;
            int dy = j - y;
            double dist = sqrt(dx * dx + dy * dy);

            if (dist <= ray) ///daca se afla in int cercului
            {
                this->matrix[i][j] = ch; // punem caracterul
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) 
{
    for (int i = left; i <= right; i++) ///pt marginile orizontale
    {
        this->SetPoint(top, i, ch); ///marginea de sus
        this->SetPoint(bottom, i, ch);///marginea de jos
    }
    for (int i = top; i <= bottom; i++) ///pt marginile verticale
    {
        this->SetPoint(i, left, ch); ///marginea din stanga
        this->SetPoint(i, right, ch);//marginea din dreapta
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) 
{
    ///umplem dreptunghiul sus->jos st->dr
    for (int i = top; i <= bottom; i++) 
        for (int j = left; j <= right; j++) 
            this->SetPoint(i, j, ch);
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) ///desenam linia cu alg Braseham
{
    int dx = abs(x2 - x1), sx;
    int dy = -abs(y2 - y1), sy;
    int error = dx + dy, e2;
    bool ok = 1;

    if (x1 < x2) sx = 1;
    else sx = -1;

    if (y1 < y2) sy = 1;
    else sy = -1;

    while (ok!=0) 
    {
        this->matrix[y1][x1] = ch;
        if (x1 == x2 && y1 == y2) { ok = 0; break;}
        e2 = 2 * error;
        if (e2 >= dy) { error = error + dy; x1 = x1 + sx; }
        if (e2 <= dx) { error = error + dx; y1 = y1 + sy; }
    }
}


void Canvas::SetPoint(int x, int y, char ch) 
{
    if (x >= 0 && x < this->width && y >= 0 && y < this->height) ///verificam ca x si y sa fie in interior
        this->matrix[x][y] = ch; ///punem caracterul
}

void Canvas::Print() ///afisam matricea
{
    for (int i = 0; i < this->height; i++) 
    {
        for (int j = 0; j < this->width; j++)
            cout << this->matrix[i][j] << ' ';
        cout << endl;
    }
}

void Canvas::Clear() ///reinitializam matricea cu ' '
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            this->matrix[i][j] = ' ';
}
