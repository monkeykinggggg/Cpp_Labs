#ifndef ANGLE_H
#define ANGLE_H
#include <iostream>
#include <cmath>
enum Unit{RADIAN,DEGREE};
class Angle{
public:
    Angle(float deg,int unit);
    static Angle fromRadians(double deg);
    static Angle fromDegrees(double deg);

    float toRad()const{return _deg;}
    float toDeg()const{return _deg*360/(2*M_PI);}

    Angle& add(const Angle& other);
    void Repair();

    void print()const{
        std::cout<<"Angle[rad]: "<<_deg<<"\n";}

    static Angle distance(const Angle& ob1,const Angle& ob2);
    
private:
    float _deg;
};
#endif  //ANGLE_H