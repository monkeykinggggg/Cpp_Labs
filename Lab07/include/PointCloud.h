#ifndef POINT_CLOUD_H
#define POINT_CLOUD_H
#include "Point3D.h"
#include <vector>
class VPointCloud;
class APointCloud{
public:
    friend VPointCloud;
    APointCloud():_size(0),_tab(nullptr){}
    //ta funkcja za kazdym razem powinna alokowac tablice o 1 weksza i wpisac wskaznik do nastepnego obiektu 
    void addPoint(const Point3D& ob);
    //funkcja zwraca nowy obiekt chwilowy funkcji z odpowiednimi wspolrz. przez kopie
    //w main'ie wykonujemy funkcje skladowa na tym obiekcie chwilowym, jednak nie mamy pozniej do niego dostepu
    Point3D geoCentre()const;
    void displayPoints()const;
    ~APointCloud();
private:
    Point3D* _tab;  //na razie mamy pusty wskaznik
    int _size;      //oraz rozmiar tablicy
};

class VPointCloud{
public:
    VPointCloud()=default;
    void addPoint(const Point3D& ob){_vect.push_back(ob);}
    int count()const {return _vect.size();}
    Point3D geoCentre()const;
    VPointCloud& add(const VPointCloud&);
    VPointCloud& add(const APointCloud&);
    void displayPoints()const;
private:
    std::vector<Point3D>_vect;
};
#endif  //POINT_CLOUD_H