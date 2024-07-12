#include "Line.h"

LArray& LArray::Add(const Line& line){
    if(_idx<_size)
        _tab[_idx++]=line;
    return *this;
}
LArray::~LArray(){
    delete[] _tab;
}

void LPrint::operator()(const Line& line)const{
    std::cout<<"y = "<<line._a<<"* x + "<<line._b<<"\t x0 = "<<line.X0()<<"\n";
}
void LPrint::operator()(const LArray& array)const{
    for(int i=0;i<array._size;i++){
        std::cout<<"["<<i<<"] ";
        (this->operator())(array[i]);
    }       
}