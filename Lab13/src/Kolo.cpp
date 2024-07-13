#include "Kolo.h"
Kolo::Kolo(int r):_r(r){}

double Kolo::polePow()const{
    return _r*_r*PI;
}

void Kolo::wypisz(std::ostream& o)const{
    o<<"Kolo o promieniu: "<<_r<<"\n";
}