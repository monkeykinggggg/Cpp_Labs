#include "Zwierze.h"
void Ssak::wydajDzwiek()const{
    std::cout<<"Ssak wydaje dzwiek!\n";
}
void Ptak::wydajDzwiek()const{
    std::cout<<"Ptak wydaje dzwiek!\n";
}
std::string Ptak::wyswietlInformacje()const {
    return "Ptak zyje w "+_msce->Nazwa();
}
std::string Ssak::wyswietlInformacje()const{
    return "";
}

std::ostream& operator<<(std::ostream& o,const Zwierze& ob){
    o<<ob.wyswietlInformacje();
    return o;
}
Ptak::~Ptak(){
    std::cout<<"Ptak umiera!\n";
}