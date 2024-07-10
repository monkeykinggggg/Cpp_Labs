#include "CplxVector.h"
CplxVector::CplxVector(double x){
    for(int i=0;i<4;i++){
        _arr[i]=CplxNumber(x);
    }
}

void CplxVector::Print()const{
    std::cout<<"[";
    for(const CplxNumber el: _arr){
        std::cout<< "("+ std::to_string(el.Re())+","+std::to_string(el.Im())+"), ";
    }
    std::cout<<"]\n";
}   
CplxVector& CplxVector::SetX(const CplxNumber& ob){
    _arr[0]=ob;
    return *this;
}
CplxVector& CplxVector::SetY(const double x,const double y ){
    _arr[1]=CplxNumber(x,y);
    return *this;
}
CplxVector& CplxVector::SetZ(const double x,const double y){
    _arr[2]=CplxNumber(x,y);
    return *this;
}
CplxNumber& CplxVector::X(){
    return _arr[0];
}
