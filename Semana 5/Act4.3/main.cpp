/*
* compilar:
*   g++ -std=c++17 -Wall -o main *.cpp
*
* ejecutar:
*   ./main
*
*/

#include <iostream>
#include "Bitacora.h"

int main() {

  Bitacora myBitacora;
  myBitacora.lecturaDatos("bitacoraHeap.txt");
  myBitacora.sort();
  myBitacora.write("bitacora_ordenada.txt");
  myBitacora.LosRepetidos("ips_con_mayor_acceso.txt");
  
  return 0;
}