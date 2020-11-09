#include <iostream>

class Wektor
{
public:
    int n;
    int get_dl() { return dlugosc; }
    int get_poj()
    {
        std::cout << "Pojemnosc wektora " << pojemnosc << std::endl;
        return pojemnosc;
    }
    void zmienDlugosc(int nd)
    {
        if (nd <= dlugosc) {
            for (int i = nd; i < dlugosc; ++i) {
                tablica[i] = 0;
            }
            dlugosc = nd;
        }
        else {
            double* tablica2 = tablica;
            tablica          = new double[nd];
            for (int i = 0; i < dlugosc; ++i) {
                tablica[i] = tablica2[i];
            }
            delete[] tablica2;
            for (int i = dlugosc; i < nd; ++i) {
                tablica[i] = 0;
            }
            dlugosc = nd;
        }
    }

    void print()
    {
        for (int i = 0; i < dlugosc; ++i) {
            std::cout << tablica[i] << std::endl;
        }
    }

    void print_dl() { std::cout << "dlugosc=" << dlugosc << std::endl; }

    Wektor(int a) : dlugosc{a}
    {
        n       = a;
        tablica = new double[n];
        for (int i = 0; i < n; ++i) {
            tablica[i] = i + 11;
            ++pojemnosc;
        }
    }

    Wektor(const Wektor& w) : dlugosc{w.dlugosc}
    // konstruktor kopiujacy
    {
        tablica = new double[dlugosc];
        tablica = w.tablica;
    }

    Wektor(Wektor&& w) // move constructor
    {
        tablica   = w.tablica;
        w.tablica = nullptr;
    }

    Wektor& operator=(Wektor&& other) // move operator
    {
        if (&other == this)
            return *this;
        delete tablica;
        tablica       = other.tablica;
        other.tablica = nullptr;
        return *this;
    }

    Wektor& operator=(const Wektor& w) // operator przypisania
    {
        // Sprawdzenie czy nie przypisujemy obiektu do samego siebie
        if (this != &w)
            *tablica = *w.tablica;
        return *this;
    }

    ~Wektor()
    {
        delete[] tablica;
        --pojemnosc;
    }
    double& operator[](const int i)
    {
        if (i < dlugosc) {
            double& el_vector = tablica[i];
            return el_vector;
        }
        else {
            zmienDlugosc(i);
            double& el_vector = tablica[i];
            return el_vector;
        }
    }
    int        dlugosc;
    static int pojemnosc;
    double*    tablica;
};

int Wektor::pojemnosc = 0;

int main()
{
    Wektor v{4};
    Wektor v2{6};
    v2 = std::move(v);
    v2.print();
}
