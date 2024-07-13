#ifndef KOLO_H
#define KOLO_H
#include "Ksztalt.h"
#define PI 3.1415
//klasa pochodna od klasy abstrakcyjnej Ksztalt
class Kolo : public Ksztalt{
public:
//Konstruktor domyslny, pobiera parametr - dlugosc promienia kola
    Kolo(int);
//metody wirtualne dla klasy Kolo
    double polePow()const override;
    virtual void wypisz(std::ostream& o)const override;
private:
//dlg. promienia kola
    int _r;
};
#endif //KOLO_H