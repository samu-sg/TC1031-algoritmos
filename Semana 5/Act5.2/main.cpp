/**
 * Johan Cabrera Peña A01635713
 * Samuel Sánchez García A00831772
 * Erika Alejandra Colín Tapia A01706555
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/

#include <iostream>
#include "HashTable.h"
#include "Graph.h"

int main() {
  Graph<std::string> ipGraph;
  try {
    ipGraph.readGraph("bitacoraGrafos.txt");
    ipGraph.writeDegreesOut("grados_ips.txt");
    ipGraph.writeIpTopDegreesOut("mayores_grados_ips.txt");
    ipGraph.writeShortestPath("distancia_bootmaster.txt");
  }
  catch (std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << std::endl << "Check your file name\n";
  }

  std::cout << std::endl;
  ipGraph.createHashTable();
  ipGraph.getIpSummary();
  
  return 0;
}