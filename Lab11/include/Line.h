#ifndef LINE_H
#define LINE_H
#include <iostream>
class LPrint;
class Line{
public:
//deklaracja przyjazni, klasa LPrint bedzie mogla korzystac z prywatnych zasobow klasy Line
    friend class LPrint;
//konstr. parametryczny, wywolywany tylko  przy dwoch argumentach
    Line(int a,int b):_a(a),_b(b){}
//konstr. konwertujacy, pozwala na konwersje jawne, przy tworzeniu wektora, jest on zarazem konstr. domyslnym
    Line(int w=1): Line(w,w){}
//przeladowany operator(), pobierajacy argument x, zwracajacy wartosc funkcji liniowej w tym punkcie
    int operator()(int x)const{return _a*x+_b;}
//metoda zwracajaca poloz. msca zerowego
    int X0()const{return -_b/_a;}
private:
//wspolczynniki f. liniwej
    int _a, _b;
};

class LArray{
public:
//funktory klasy LPrint będą rowniez sluzyc do wypisywania tablicy linii
    friend class LPrint; 
//konstruktor domyslny a zaraazem parametryczny, tworzy tablice dynamicznie alokowana o wymaganej ilosci elementow
    LArray(int size=0):_tab(new Line[size]),_idx(0),_size(size){}
//Metoda dodajaca nastepne obiekty do tablicy, zwracajaca zmodyfikowany obiekt
    LArray& Add(const Line& line);
//operator zwraca obiekt pod danym indeksem dynamicznej tablicy
    Line& operator[](int i)const{return _tab[i];}
//Destruktor zwalniajacy pamiec
    ~LArray();
private:
//pryawtne skladniki, wskaznik do poczatku tablicy oraz index aktualnego elementu zapisywanego
    Line* _tab;
    int _idx;
    int _size;
};

//klasa typowa do tworzenia funktorow
class LPrint{
public:
//przeciazony operator () klasy kreujacej funkctory, gwaran tuje nie zmieniac stanu obiektu, an rzecz ktorego jest wywolywany, rowniez argument typu Line moze byc stalym obiektem
    void operator()(const Line& line)const;
    void operator()(const LArray& array)const;
};
#endif //LINE_H
