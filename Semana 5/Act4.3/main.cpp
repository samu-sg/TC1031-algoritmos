/*
*
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
#include "Graph.h"

int main() {
  Graph<std::string> io;
  io.readGraph("bitacoraGrafos.txt");
  io.writeDegrees("grados_ips.txt");
  io.writeIpTopDegrees("mayores_grados_ips.txt");
  io.writeShortestPath("distancia_bootmaster.txt");
  return 0;
}