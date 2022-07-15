/*
* Johan Cabrera Peña A01635713
* Samuel Sánchez García A00831772
* Erika Alejandra Colín Tapia A01706555
*
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
  std::string mes, dia, hora, min, seg, ip = "", puerto = "", msg = "";
  Bitacora myBitacora;
  myBitacora.lecturaDatos("bitacora.txt");
  myBitacora.swapsort();
  // Escribes las variables de la fecha una por una con un espacio.
  std::cout<<"Escribe la fecha inicial (ej. Jun 01 00 22 36): ";
  std::cin >> mes >> dia >> hora >> min >> seg;
  //Entran en un objeto registro para compararlas con las demas fechas
  Registro fecha1(mes, dia, hora, min, seg, ip, puerto, msg);
  // Escribes las variables de la fecha una por una con un espacio.
  std::cout<<"Escribe la fecha final (ej. Jun 01 08 23 57): ";
  std::cin >> mes >> dia >> hora >> min >> seg;
  Registro fecha2(mes, dia, hora, min, seg, ip, puerto, msg);
  // Lee con posicion 1 y 2 le damos los paramatros a nuestro print de donde a donde queremos que lo haga.
  int posicion1 = myBitacora.busquedaBinaria(fecha1);
  int posicion2 = myBitacora.busquedaBinaria(fecha2);
  // Impresión con parametros
  myBitacora.print(posicion1, posicion2);
  return 0;
}