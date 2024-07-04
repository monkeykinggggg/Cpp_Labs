#ifndef GOPERATIONS_H
#define GOPERATIONS_H

typedef float(*operacja)(float*, int);

float Suma(ciag wsk, rozmiarCiagu rozmiar){
    float suma=0;
    for(int i=0;i<rozmiar;i++)
        suma+=wsk[i];
    return suma;
}

float Iloczyn(ciag wsk, rozmiarCiagu rozmiar){
    float iloczyn=1;
    for(int i=0;i<rozmiar;i++)
        iloczyn*=wsk[i];
    return iloczyn;
}

float Max(ciag wsk, rozmiarCiagu rozmiar){
    int ind=0;
    for(int i=1;i<rozmiar;i++){
        if(wsk[i]>wsk[ind])
            ind=i; 
    }
    return wsk[ind];
}

float Wykonaj(operacja op, ciag wsk,rozmiarCiagu rozmiar){
    return op(wsk, rozmiar);
}

#endif //GOPERATIONS_H