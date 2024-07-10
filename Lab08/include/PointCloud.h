#ifndef POINT_CLOUD_H
#define POINT_CLOUD_H
#include "Point3D.h"
#include <vector>

class VPointCloud{
public:
    VPointCloud()=default;
//ze wzgledow modyfikacji, metoda bedzie dluzsza, definicje przenosimy do pliku zrodlowego
//pobieramy referencje, gdyby obiekt byl spory
    void addPoint(const Point3D& ob);
//metoda dodajaca za pomoca wskaznika na obiekt, pobiera wskaznik na staly obiekt
    void addPoint(const Point3D* p){_vect.push_back(p);}
    int count()const {return _vect.size();}
    VPointCloud& add(const VPointCloud&);
    void displayPoints()const;
//funkcja tworzy nowy wskaznik, do ktorego kopiuje zawartosc punktu z innej chmury, zwraca tenwskaznik, na podstawie 
//ktorego, metoda addPoint nastepnie doda go na koniec wektora
    Point3D* getCopyPoint(int index);
private:
//w tej wersji cwiczenia przechowujemy wskazniki na punkty
    std::vector<const Point3D*>_vect;
};
#endif  //POINT_CLOUD_H