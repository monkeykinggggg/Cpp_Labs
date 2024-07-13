#include "Line.h"

LArray& LArray::Add(const Line& line){
    if(_idx<_size)
        _tab[_idx++]=line;
    return *this;
}
LArray::~LArray(){
    delete[] _tab;
}

LArraySmartPtr::LArraySmartPtr(LArray* p):_p(p),_count(new int(1)){}

LArraySmartPtr& LArraySmartPtr::operator=(const LArraySmartPtr& other){
    if(this!=&other){
        (*_count)--;  //zmniejszamy odniesienie o 1
        if(!(*_count)){ //jezeli to bylo ostatnie odniesienie do tej konkretnej tablicy
            delete _p;
            delete _count;
        }
        _p=other._p;    //przypisujemy nowa wartosc
        _count=other._count;    //teraz wyliczamy iosc kopii innej  tablicy
        (*_count)++;
    }
    return *this;
}
LArraySmartPtr::~LArraySmartPtr(){
    (*_count)--;
    if(!(*_count)){
        delete _p;
        delete _count;
    }
}

std::ostream& operator<<(std::ostream& o, const Line& ob){
    o<<"y = "<<ob._a<<"* x + "<<ob._b<<"\tx0 = "<<ob.X0()<<"\n";
    return o;
}

std::ostream& operator<<(std::ostream& o, const LArray& ob){
    for(int i=0;i<ob._idx;i++)
        o<<ob[i];
    return o;
}