#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
class Car{
public:
    Car(std::string b, int y, int m);
    void displayInfo();
    Car(const Car& other);
    Car(Car&& other);
    Car& operator=(Car&& other);
    ~Car();
private:
    std::string _brand;
    int* _year;
    int _mileage;
};
#endif //CAR_H