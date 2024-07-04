// UWAGA na temat pragma once oraz podziału programu na pliki:
// #pragma once po prostu blokuje includowanie danego pliku 
// > tej samej jednostce kompilacji < więcej niż raz, 
// ale nie blokuje includowanie tego samego pliku
// > w różnych jednostkach kompilacji <
// Dlatego, jeśli funkcje są zdefiniowane w nagłówku i nie znajdują się 
// wewnątrz struktury lub klasy (a więc są globalne lub znajdują się w przestrzeni nazw),
// to należy albo zdefiniować je inline, albo podzielić ich definicję na plik .cpp.
//
// Prosze napisac funkcje tworzace i operaujace na ciagach. 
// Należy utworzyć ciągi geometryczne o pierwszym wyrazie 1 i zadanym ilorazie:
// wynik[i] = wynik[i-1]*iloraz;
// Oprocz tego należy obliczyc sume oraz iloczyn wszystkich
// elementow ciagu, a takze znalezc jego najwiekszy element.
//
// Prosze zadbać o dobre zarządzanie pamiecią (valgrind jest pomocny).
// * tworzenie archiwum: tar -czvf nazwa.tar.gz katalog/

#include "GSeries.h"
#include "GOperations.h"

int main ()
{
  const rozmiarCiagu rozmiar = 4;
  const float iloraz = 2;
  
  // pierwszy element ciagu to 1
  const ciag geometryczny = InicjalizujCiagGeometryczny (rozmiar, iloraz);
  Wypisz(geometryczny, rozmiar);
  
  const ciag geometryczny2 = InicjalizujCiagGeometryczny (6, 3.);
  Wypisz(geometryczny2, 6);

  printf("Suma: %.2f\n",Suma(geometryczny, rozmiar));
  
  const char* op_nazwa [] = {"Suma", "Iloczyn", "Max"};
  operacja op [] = {Suma, Iloczyn, Max};  //tablica wkzanikow na funkcje z danej grupy

  const int ileOperacji = sizeof(op)/sizeof(operacja);
  for (int i = 0; i < ileOperacji; ++i)
    printf("%s: %.2f\n",op_nazwa[i], Wykonaj(op[i],geometryczny2, 6));

  UsunCiagi();
}
/* 
(1, 2, 4, 8)

(1, 3, 9, 27, 81, 243)

Suma: 15.00

Suma: 364.00

Iloczyn: 14348907.00

Max: 243.00*/
