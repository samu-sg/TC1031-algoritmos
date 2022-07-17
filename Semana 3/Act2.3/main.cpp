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
  myBitacora.sort();
  myBitacora.escribeBitacora("bitacoraOrdenada.txt");
  
  // Escribes las variables de la fecha una por una con un espacio.
  std::cout<<"------ Escribe la fecha inicial ------" << std::endl;
  std::cout << "Mes (ej. Jun): ";
  std::cin >> mes;
  std::cout << "Dia: ";
  std::cin >> dia;
  std::cout << "Hora: ";
  std::cin >> hora;
  std::cout << "Minuto: ";
  std::cin >> min;
  std::cout << "Segundo: ";
  std::cin >> seg;
  //Entran en un objeto registro para compararlas con las demas fechas
  Registro fecha1(mes, dia, hora, min, seg, ip, puerto, msg);
  // Escribes las variables de la fecha una por una con un espacio.
  std::cout<<"------ Escribe la fecha final ------"<<std::endl;
  std::cout << "Mes (ej. Ago): ";
  std::cin >> mes;
  std::cout << "Dia: ";
  std::cin >> dia;
  std::cout << "Hora: ";
  std::cin >> hora;
  std::cout << "Minuto: ";
  std::cin >> min;
  std::cout << "Segundo: ";
  std::cin >> seg;
  Registro fecha2(mes, dia, hora, min, seg, ip, puerto, msg);
  // Lee con posicion 1 y 2 le damos los paramatros a nuestro print de donde a donde queremos que lo haga.
  int posicion1 = myBitacora.busquedaBinaria(fecha1);
  int posicion2 = myBitacora.busquedaBinaria(fecha2);
  // Impresión con parametros
  myBitacora.print(posicion1, posicion2);
  // Guarda los resultados de la búsqueda en resultado_busqueda.txt
  myBitacora.nuevoRegistro("resultado_busqueda.txt", posicion1, posicion2);
  
  return 0;
}