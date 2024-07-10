#ifndef POINT_3D_H
#define POINT_3D_H
#include <iostream>
#include <array>
#include <initializer_list>
#include <iomanip>
class Point3D{
public:
    static int DISPLAY_PRESITION;
//wartosc domyslna, argument kluczowy tylko w deklaracji, teraz konstruktor bedzie rowniez uzywany
//przy domyslnym tworzeniu obiektu za pomoca new, delete
    Point3D(std::initializer_list<double> list);
//delegeacja konstruktora wykorzystana w konstr. domniemanym - osobnym
    Point3D(): Point3D({0,0,0}){}
//nastepna delegacja konstr. tym razem w konstr. konwerujacym z double'a
    explicit Point3D(double x): Point3D({x,x,x}){}
    void displayCoordinates()const;
    double getX()const{return _coordinates[0];}
    double getY()const{return _coordinates[1];}
    double getZ()const{return _coordinates[2];}
private:
    std::array<double,3>_coordinates;
};
#endif  //POINT_3D_H