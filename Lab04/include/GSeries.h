#ifndef GSERIES_H
#define GSERIES_H

#include <iostream>
using rozmiarCiagu = int;
using ciag = float*;
using typCiagu=float; 
ciag* GlobalTab=nullptr;  
int indeks;                 //zmienna globalna inicjalizowana zerem, zakres pliku

ciag InicjalizujCiagGeometryczny(rozmiarCiagu rozmiar, float first,float iloraz){
    if(!GlobalTab)
        GlobalTab=new ciag[10];
    if(rozmiar>0){
        ciag wsk = new float[rozmiar];
        if(wsk)
        {
            wsk[0]=first;    
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
    if(GlobalTab){
        for(int i=0;i<indeks;i++)
        {
            if(GlobalTab[i]){
                delete[] GlobalTab[i];
                GlobalTab[i]=nullptr;
            } 
        }
        delete[] GlobalTab;
        GlobalTab=nullptr;              //preventing from double free
    }   
}

#endif //GSERIES_H