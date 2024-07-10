#include "PointCloud.h"

VPointCloud& VPointCloud::add(const VPointCloud& other){
    if(this!=&other){
       _vect.insert(_vect.end(),other._vect.begin(),other._vect.end());
    }
    return *this;
}

void VPointCloud::displayPoints()const{
    for(auto &el:_vect){
        (*el).displayCoordinates();
    }
}

void VPointCloud::addPoint(const Point3D& ob){ 
    const Point3D*p=new Point3D(ob);
    _vect.push_back(p);
}

Point3D* VPointCloud::getCopyPoint(int index){
    Point3D* p=new Point3D(*_vect[index]);   //kopia skladnik po skladniku
    return p;
}