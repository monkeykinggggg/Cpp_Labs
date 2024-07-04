#ifndef GOPERATIONS_H
#define GOPERATIONS_H

typedef float(*operacja)(float*, int);

float Suma(ciag wsk, rozmiarCiagu rozmiar){
    float suma=0;
    for(int i=0;i<rozmiar;i++)
        suma+=wsk[i];
    return suma;
}

float Srednia(ciag wsk, rozmiarCiagu rozmiar){
    return Suma(wsk,rozmiar)/rozmiar;
}

float Wykonaj(operacja op, ciag wsk,rozmiarCiagu rozmiar){
    return op(wsk, rozmiar);
}

#endif //GOPERATIONS_H