/*
  compilar:
    g++ -std=c++17 -Wall *.cpp

  ejecutar:
    ./a.out
*/

#include <iostream>
#include "ListaTemplate.h"

int main()
{
  std::cout << "Template example!\n";
  ListaTemplate<int> myList;

  myList.insert(15);
  myList.insert(12);
  myList.insert(22);
  myList.print();
  std::cout << myList.getSize() << std::endl;
  // myList.erase();
  myList.getData(3);

  return 0;
}