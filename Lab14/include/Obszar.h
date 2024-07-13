#ifndef OBSZAR_H
#define OBSZAR_H
#include <iostream>
//klasa abstrakcyjna
class Obszar{
public:
//czysto wirtualna metoda
    virtual void wyswietlInformacje()const=0;
};

//nastepnie klasy pochodne sluzace juz do utworzenia konkretnych ich instancji
class Kontynent : public Obszar{
public:
//metoda wirtualna, dodajemy sprawdzanie poprawnosci przez override
    void wyswietlInformacje()const override;
};

class Kraj : public Obszar{
public:
//metoda wirtualna, dodajemy sprawdzanie poprawnosci przez override
    void wyswietlInformacje()const override;
};
#endif //OBSZAR_H

