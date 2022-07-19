/** 
* Ejemplo que implementa un MaxHeap (Priority queue)
*
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
#include "MaxHeap.h"

int main() {
  std::cout << "Prueba de un MaxHeap!\n";
  MaxHeap<int> myMaxHeap(100);
  std::cout << "isEmpty() " << myMaxHeap.isEmpty() << std::endl;
  std::cout << "getCapacity() " << myMaxHeap.getCapacity() << std::endl;
  std::cout << "push() de 7 valores" << std::endl;
  myMaxHeap.push(2);
  myMaxHeap.push(3);  
  myMaxHeap.push(1);
  myMaxHeap.push(15);
  myMaxHeap.push(5);
  myMaxHeap.push(4);
  myMaxHeap.push(45);
  /* Max Heap creado 
             45
            /  \
           5    15
          / \   / \
         2   3 1   4
  */
  
  myMaxHeap.print();
  std::cout << "top() " << myMaxHeap.top() << std::endl;
  std::cout << "pop()...\n";
  myMaxHeap.pop();
  myMaxHeap.print();
  
  return 0;
}