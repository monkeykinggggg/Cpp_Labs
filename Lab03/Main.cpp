// Proszę zdefiniować w CMakeLists.txt odpowiednie definicje zmiennej LONG_LOOP
// tak aby program kompilował się i wykonywał w zależności od jej wartości, którą
// odpowiednio możemy modyfikować za pomocą wykonania cmake:
// cmake ../ -DPERFORME_LONG_LOOP=0 -> tożsame z camke ../
// cmake ../ -DPERFORME_LONG_LOOP=1
//prosze skorzystac w gzipa -bk 
#include "GSeries.h"
#include "GOperations.h"
#include "GOperations.h" // To nie pomyłka, ponowne include
#include <chrono>

using time_point = std::chrono::time_point<std::chrono::high_resolution_clock>; 

time_point start(){
  return std::chrono::high_resolution_clock::now();
}

void stop(const std::string& name, const time_point& start){
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Czas wykonania " << name << ": "
         << duration.count() << " mikrosekund" << std::endl;
}

int main ()
{
  auto _start{start()};

  const rozmiarCiagu rozmiar = 5;
  const typCiagu pierwszy = 0.5;
  const typCiagu iloraz = 3;
  
  const ciag geometryczny = InicjalizujCiagGeometryczny (rozmiar, pierwszy, iloraz);
  Wypisz(geometryczny, rozmiar);
  std::cout<<"Suma: " << Suma(geometryczny, rozmiar) << std::endl;

  if(LONG_LOOP){ // Zmienna zdefiniowana na poziomie CMakeLists.txt
    const rozmiarCiagu rozmiar = 10e5;
    const float iloraz = 1.00001;
    const ciag geometryczny = InicjalizujCiagGeometryczny (rozmiar, 0.00001, iloraz);
    const char* op_nazwa [] = {"Suma", "Srednia"};
    operacja op [] = {Suma, Srednia};
    const int ileOperacji = sizeof(op)/sizeof(operacja);
    for (int i = 0; i < ileOperacji; ++i)
      std::cout << op_nazwa[i] << ": " << Wykonaj(op[i],geometryczny, rozmiar) <<std::endl;
  }

  UsunCiagi();

  stop("main",_start);
}
/* wynik dzialania programu (ostatnia linia oczywiście będzie się różnić wartością)
(0.5, 1.5, 4.5, 13.5, 40.5)
Suma: 60.50
Suma: 22292.6
Srednia: 0.0222926
Czas wykonania main: 8117 mikrosekund
*/
