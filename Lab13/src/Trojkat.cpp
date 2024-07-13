#include "Trojkat.h"
Trojkat::Trojkat(int a, int b, int c):_a(a),_b(b),_c(c){}

double Trojkat::polePow()const{
    float x=(_a+_b+_c)/2;
    return sqrt(x*(x-_a)*(x-_b)*(x-_c));
}
void Trojkat::wypisz(std::ostream& o)const{
    o<<"Trojkat bokach: "<<_a<<" "<<_b<<" "<<_c<<"\n";
}
