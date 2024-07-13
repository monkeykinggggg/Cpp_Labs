// Zadanie opiera się o implementację abstrakcyjnych klas Obszar i Zwierze, 
// a także ich konkretne implementacje w postaci klas Kontynent, Kraj, Ptak i Ssak. 
// Użyj wirtualnych funkcji, wirtualnego destruktora, 
// a także override i final do oznaczenia odpowiednich funkcji. 
// Klasa Ptak zawiera skłądową typu Kraj jako miejsce życia.
#ifndef ZWIERZE_H
#define ZWIERZE_H
#include "Obszar.h"
//abstrakcyjna klasa z czysto wirtualna przyn. jedna metoda
class Zwierze{
public:
//metody czysto abstrakcyjne
    virtual void wydajDzwiek()const=0;
    virtual void wyswietlInformacje()const =0;
};

class Ptak : public Zwierze{
public:
//konstruktor klasy Ptak, pozwalajacy na ustawienie msca zamieszkania
    Ptak(Kraj* k):_msce(k){}
//wywoluje polimorficznie okrzyk dla ptaka
    virtual void wydajDzwiek()const override;
//wyswietla informacje o miejscu zamieszkania
    void wyswietlInformacje()const override;
private:
//msce zamieszkania ptaka
    Kraj* _msce;
};

class Ssak: public Zwierze{
public:
//wywoluje polimorficznie okrzyk dla ssaka
    virtual void wydajDzwiek()const override;
//metoda polimorficzna, nie ma skutku jej dzialania
    void wyswietlInformacje()const override;
};
#endif //ZWIERZE_H