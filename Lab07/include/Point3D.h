#ifndef POINT_3D_H
#define POINT_3D_H
#include <iostream>
#include <array>
#include <initializer_list>
class Point3D{
public:
//wartosc domyslna, argument kluczowy tylko w deklaracji, teraz konstruktor bedzie rowniez uzywany
//przy domyslnym tworzeniu obiektu za pomoca new, delete
    Point3D(std::initializer_list<double> list={0,0,0});
    void displayCoordinates()const;
    double getX()const{return _coordinates[0];}
    double getY()const{return _coordinates[1];}
    double getZ()const{return _coordinates[2];}
private:
    std::array<double,3>_coordinates;
};
#endif  //POINT_3D_H