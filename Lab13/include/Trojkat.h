#ifndef TROJKAT_H
#define TROJKAT_H
#include "Ksztalt.h"
class Trojkat : public Ksztalt{
public:
//konstruktor odmyslny oraz parametryczny
    Trojkat(int a=0, int b=0,int c=0);
//metody, wirtualne
    double polePow()const override;
    virtual void wypisz(std::ostream& o)const override;
private:
//dlugosc bokow trojkata
    int _a,_b,_c;
};
#endif //TROJKAT_H