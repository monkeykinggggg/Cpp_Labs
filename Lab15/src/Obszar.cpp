#include "Obszar.h"
void Kontynent::wyswietlInformacje()const{
    std::cout<<"Kontynent\n";
}
void Kraj::wyswietlInformacje()const{
    std::cout<<"Kraj "<<_name<<"\n";
}
Kraj::Kraj(std::string name):_name(name){}