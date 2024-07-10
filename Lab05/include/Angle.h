#ifndef ANGLE_H
#define ANGLE_H
#include <iostream>
#include <cmath>
enum Unit{RADIAN,DEGREE};
class Angle{
public:
    Angle(float deg,int unit);
    float toRad()const{return _deg;}
    float toDeg()const{return _deg*360/(2*M_PI);}
    Angle& add(const Angle& other);
    void Repair();
private:
    float _deg;
};
#endif  //ANGLE_H


