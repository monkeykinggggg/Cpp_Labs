#include "PointCloud.h"
void APointCloud::addPoint(const Point3D& ob){  //kopiujemy sb jakis obiekt tymczasowy
    if(!_tab){
        _tab=new Point3D;                //skoro uzywamy new to potrzebujemy tez konstruktor domyslny
                                         //kopiujemy 1:1 skladnik po skladniku
    }
    else{
        Point3D* tmp=new Point3D[_size];
        for(int i=0;i<_size;i++)
            tmp[i]=_tab[i];
        delete[]_tab;
        _tab=new Point3D[_size+1];      //teraz bedzie o 1 wiekszy niz byl
        for(int i=0;i<_size;i++)
            _tab[i]=tmp[i];             //kopiujemy obiekty skladnik po skladniku -std::array ma swoj konstr. kopiujacy
        delete[]tmp;
    }
    _tab[_size++]=ob;
}

void APointCloud::displayPoints()const{
    for(int i=0;i<_size;i++){
        _tab[i].displayCoordinates();
    }
}

Point3D APointCloud::geoCentre()const{
    double x=0;
    double y=0;
    double z=0;
    for(int i=0;i<_size;i++){
        x+=_tab[i].getX();
        y+=_tab[i].getY();
        z+=_tab[i].getZ();
    }
   return Point3D({x/_size,y/_size,z/_size});       //zwracamy wartosc chwilowa funkcji
}
APointCloud::~APointCloud(){
    if(_tab)
        delete[] _tab;
    _tab=nullptr;
}

Point3D VPointCloud::geoCentre()const{
    double x=0;
    double y=0;
    double z=0;
    for(auto el: _vect){
        x+=el.getX();
        y+=el.getY();
        z+=el.getZ();
    }
    int s=_vect.size();
    return Point3D({x/s,y/s,z/s});       //zwracamy wartosc chwilowa funkcji
}

VPointCloud& VPointCloud::add(const VPointCloud& other){
    _vect.reserve(_vect.size()+other._vect.size());  
    for(auto& el:other._vect)
        _vect.push_back(el);            //reserve space for 6 elements
    return *this;
}

VPointCloud& VPointCloud::add(const APointCloud& other){
    for(int i=0;i<other._size;i++){
        _vect.push_back(Point3D({other._tab[i].getX(),other._tab[i].getY(),other._tab[i].getZ()}));
    }
    return *this;
}

void VPointCloud::displayPoints()const{
    for(auto &el:_vect){
        el.displayCoordinates();
    }
}