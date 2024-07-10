#include "CplxNumber.h"
#include <array>
class CplxVector{
public:
    CplxVector()=default;
//konstr. konwertujacy z doubla, pozwalamy na niejwane konwersje tj. w przypisaniach, przy operatorach, przy wywolaniu i zwracaniu z funkcji 
//korzysta z jawnego wywolania konstruktora obiektow przechowywanych   
    CplxVector(double);
//wypisuje obiekty w w array'u
    void Print()const;
//metody ustawiajace jako skladowe wektora, konkretne punkty, moga byc one stale
    CplxVector& SetX(const CplxNumber& ob);
    CplxVector& SetY(const double x,const double y );
    CplxVector& SetZ(const double x,const double y);
//metoda zwracajaca pierwszy biekt w tablicy
    CplxNumber& X();
private:
//tablica przechowujaca trzy uporzadkowane obiekty typu CmplNumber
    std::array<CplxNumber,3> _arr;
};