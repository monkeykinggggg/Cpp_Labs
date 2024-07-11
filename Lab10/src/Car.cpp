#include "Car.h"
Car::Car(std::string b, int y, int m):_brand(b),_year(new int(y)),_mileage(m){}
void Car::displayInfo(){
    std::cout<<"Brand: "<<_brand;
    if(_brand!="-None-")
        std::cout<<", Year: "<<*_year<<", Mileage: "<<_mileage;
    else
        std::cout<<", Year: -None-, Mileage: -None-";
    std::cout<<std::endl;
            
}
Car::Car(const Car& other):_brand(other._brand),_year(new int(*other._year)),_mileage(other._mileage){}

Car::Car(Car&& other){
    _brand=std::exchange(other._brand,"-None-");
    _year=std::exchange(other._year,nullptr);
    _mileage=std::exchange(other._mileage,0);
}
Car& Car::operator=(Car&& other){
    if(this!=&other){
        delete _year;
        _brand=std::exchange(other._brand,"-None-");
        _year=std::exchange(other._year,nullptr);
        _mileage=std::exchange(other._mileage,0);
    }
    return *this;
}
Car::~Car(){delete _year;}
