/** 
* Ejemplo que implementa Grafos ponderados con una
* Lista de adyacencia y el algoritmo BFS, Dijkstra
*
* Johan Cabrera Peña A01635713
* Samuel Sánchez García A00831772
* Erika Alejandra Colín Tapia A01706555
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main < test04.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < test04.txt
**/

#include <iostream>
#include <sstream>
#include "Graph.h"

int main() {
  std::cout << "Ejemplo de grafos (representaciones)!" << std::endl;
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf(); 
  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  Graph<std::string> g1;
  g1.readGraph(inputInfo);
  g1.print();
  //std::cout << std::endl;
  //g1.printGraphInfo();
  std::cout << std::endl;
  g1.BFS(1);
  std::cout << std::endl;
  g1.shortestPath(1);
  
  return 0;
} 