#include "Point3D.h"
Point3D::Point3D(std::initializer_list<double> list){
    //std::cout<<"\nDomniemany konstr.\n";
    if(list.size()==3){
        int i=0;
        for(auto el: list)
            _coordinates[i++]=el;
    }
    //this->displayCoordinates();
}
void Point3D::displayCoordinates()const{
    std::cout<<std::fixed<<std::setprecision(DISPLAY_PRESITION);
    std::cout<<"("<< _coordinates[0]<<", "
                  << _coordinates[1]<<", "
                  << _coordinates[2]<<")\n";
}
//definicja a zarazem inicjalizacja zmiennej statycznej
int Point3D::DISPLAY_PRESITION=1;