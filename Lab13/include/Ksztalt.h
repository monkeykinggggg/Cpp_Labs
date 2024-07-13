#ifndef KSZTALT_H
#define KSZTALT_H
#include <iostream>
//klasa abstrakcyjna  - baza dla konretnych ksztaltow
class Ksztalt{
public:
//metody czysto wirtualne - bedziemy korzystac z polimorficznosci ich wywolana dla konkretnych obiektow
    virtual double polePow()const =0;
    virtual void wypisz(std::ostream& o)const =0;
    virtual ~Ksztalt()=default;
};
//globalna funkcja korzystajaca z metod polimorficznych
void wypisz(const Ksztalt& ob);
#endif //KSZTALT_H


