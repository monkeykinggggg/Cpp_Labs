#ifndef OBSZAR_H
#define OBSZAR_H
#include <iostream>
//klasa abstrakcyjna
class Obszar{
public:
//czysto wirtualna metoda
    virtual void wyswietlInformacje()const=0;
//Skoro mamy metody wirtualne, destruktor rowniez powinien byc, aby odpowiedni zostal wywolany
    virtual ~Obszar()=default;
};

//nastepnie klasy pochodne sluzace juz do utworzenia konkretnych ich instancji
class Kontynent : public Obszar{
public:
//metoda wirtualna, dodajemy sprawdzanie poprawnosci przez override
    void wyswietlInformacje()const override;
//polimorficzny destruktor
    ~Kontynent()=default;
};

class Kraj : public Obszar{
public:
//konstruktor konwertujacy oraz domyslny
    explicit Kraj(std::string name="-None-");
//metoda wirtualna, dodajemy sprawdzanie poprawnosci przez override
    void wyswietlInformacje()const override;
    std::string Nazwa()const{return _name;}
//polimorficzny destruktor
    ~Kraj()=default;
private:
//atrybut kraju - jego nazwa
    std::string _name;
};
#endif //OBSZAR_H

