#ifndef CPLXNUMBER_H
#define CPLXNUMBER_H
#include <iostream>
class CplxNumber{
public:
//konstruktor parametryczny, z ktorego korzystamy w wszelkich innych konstruktorach
    CplxNumber(double x,double y):_Re(x),_Im(y){}
//Konnstruktor konwertujacy z double'a, zabezpieczamy sie przed konwersja niejawna
    explicit CplxNumber(double x):CplxNumber(x,x){}
//nalezy rozdzielic definicje konstr. domyslnego, zeby poprzednie dwa mialy racje bytu
    CplxNumber():CplxNumber(0,0){}
    void Print()const;
//funkcja konwerujaca do stringa liczbe, korzysta metody klasy string: std::to_string(x) 
    operator std::string();
//jawna funkcja konwersji do double'a, dzieki niej mozemy tylko jawnie konwertowac obiekt, czyli za pomoca castow: static_cast ...
    explicit operator double();
    static double Abs(const CplxNumber& ob);
//zabezpieczenie prywatnych skladnikow, bedziemy ic potrzebowac w metodzie CmplxVector'a
    double Re()const{return _Re;}
    double Im()const{return _Im;}
private:
    double _Re,_Im;
};
#endif //CPLXNUMBER_H