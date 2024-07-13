#ifndef LINE_H
#define LINE_H
#include <iostream>

/*class Line;class LArray;
std::ostream& operator<<(std::ostream& o, const Line& ob);
std::ostream& operator<<(std::ostream& o, const LArray& ob);*/
class Line{
public:
    friend std::ostream& operator<<(std::ostream& o, const Line& ob);
//konstr. parametryczny, wywolywany tylko  przy dwoch argumentach
    Line(int a,int b):_a(a),_b(b){}
//konstr. konwertujacy, pozwala na konwersje jawne, przy tworzeniu wektora, jest on zarazem konstr. domyslnym
    Line(int w=1): Line(w,w){}
//metoda zwracajaca poloz. msca zerowego
    int X0()const{return -_b/_a;}
private:
//wspolczynniki f. liniwej
    int _a, _b;
};

class LArray{
public:
//przeciazony operator globalny, majacy dostep do zmiennych prywatnych klasy LArray
    friend std::ostream& operator<<(std::ostream& o, const LArray& ob);
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

//Klasa ktorej kazdy obiekt wskazuje na ten sam obiekt typu LArray
class LArraySmartPtr{
public:
//konstruktor przypisuje adres oraz ustawia ilosc kopii na 1, nie mozna innego obiektu zainicjalizowac tym samym wskaznikiem
    LArraySmartPtr(LArray* p=nullptr);
//przeladowane operatory zwracajace obiekt oraz jego adres
    LArray& operator*(){return *_p;}
    LArray* operator->(){return _p;}
//przypisuje inny wskaznik do danego obiektu
    LArraySmartPtr& operator=(const LArraySmartPtr& other);
//destruktor - zwalnia pamiec jezeli jest to ostatnia kopia na ten obiekt
    ~LArraySmartPtr();
private:
//wskaznik przechowywany oraz liczba kopii tego wskaznika, czyli wspolny wskaznik na int'a dla obiektow ktore przechowuja ten sam adres LArray
    LArray* _p;
    int* _count;
};

#endif //LINE_H

