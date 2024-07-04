#ifndef GSERIES_H
#define GSERIES_H

#include <iostream>
using rozmiarCiagu = int;
using ciag = float*;

ciag* GlobalTab=new ciag[10];  
int indeks;

ciag InicjalizujCiagGeometryczny(rozmiarCiagu rozmiar, float iloraz){
    if(rozmiar>0){
        ciag wsk = new float[rozmiar];
        if(wsk)
        {
            wsk[0]=1;    
            for(int i=1;i<rozmiar;i++)
                wsk[i]=wsk[i-1]*iloraz; 
        }
        GlobalTab[indeks++]=wsk;
        return wsk;
    } 
    return NULL;
}

void Wypisz(ciag wsk,rozmiarCiagu rozmiar){
    std::cout<<"(";
    for(int i=0;i<rozmiar;i++)
        std::cout<<wsk[i]<<" ";
    std::cout<<")\n";
}

void UsunCiagi(){
    for(int i=0;i<indeks;i++){
        delete[] GlobalTab[i];
    }
    delete[] GlobalTab;
}

#endif //GSERIES_H