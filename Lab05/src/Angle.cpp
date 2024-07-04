#include "Angle.h"
Angle::Angle(float deg,int unit){  //nie ma wartosci domyslnej = nie mozna utworzyc elementu bez podania jednostki
        if(unit==DEGREE)
        {
            std::cout<<"... creating angle from degrees.\n";
            _deg=deg*2*M_PI/360;
        }
        else{
            std::cout<<"... creating angle from radians.\n";
            _deg=deg;
        }
        Repair();
    }
void Angle::Repair(){
        if(_deg<0)
        {
            while(_deg<0) _deg+=2*M_PI;
        }
        else if(_deg>2*M_PI)
        {
            while(_deg>2*M_PI) _deg-=2*M_PI;
        }
    }

Angle& Angle::add(const Angle& other){
        _deg+=other._deg;
        this->Repair();
        return *this;
    }    