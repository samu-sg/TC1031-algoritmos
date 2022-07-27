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
  Graph<std::string> ipGraph;
  try {
    ipGraph.readGraph("bitacoraGrafos.txt");
    ipGraph.writeDegrees("grados_ips.txt");
    ipGraph.writeIpTopDegrees("mayores_grados_ips.txt");
    ipGraph.writeShortestPath("distancia_bootmaster.txt");
  }
  catch (std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << std::endl << "Check your file name\n";
  }
  
  return 0;
}