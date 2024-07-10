#include "CplxNumber.h"
void CplxNumber::Print()const{
    std::cout<<"("<<_Re<<", "<<_Im<<")\n";
}
CplxNumber::operator std::string(){
    return "("+ std::to_string(_Re)+","+std::to_string(_Im)+")";
}

CplxNumber::operator double(){
    return sqrt(_Im*_Im+_Re*_Re);
}

double CplxNumber::Abs(const CplxNumber& ob){
    return sqrt(ob._Im*ob._Im+ob._Re*ob._Re);
}

