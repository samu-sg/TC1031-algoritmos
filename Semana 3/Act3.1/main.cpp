/** 
* Johan Cabrera Peña A01635713
* Samuel Sánchez García A00831772
* Erika Alejandra Colín Tapia A01706555
*
* Actividad 3.1
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
#include "BST.h"

int main() {
  std::cout << "Ejemplo de un Binary Search Tree (BST)\n";

  BST<int> myBST;
  myBST.insert(10);
  myBST.insert(20);
  myBST.insert(30);
  myBST.insert(15);
  myBST.insert(5);
  myBST.insert(115);
  myBST.insert(3);
  myBST.insert(3);

  /*
                    10
            5               20          
        3             15          30
                                      115                           
  */
  
  myBST.print();

  std::cout << "Recorrido inorder" << std::endl;
  myBST.callInorder();
  std::cout << "Recorrido preorder" << std::endl;
  myBST.callPreOrder();
  std::cout << "Recorrido postorder" << std::endl;
  myBST.callPostOrder();

  // Actividad 3.1
  std::cout << "Level by level" << std::endl;
  myBST.levelByLevel();
  int altura = myBST.height();
  std::cout << "Altura: " << altura << std::endl;
  std::cout << "Ancestros(115) ";
  myBST.ancestors(115);
  int nivelActual = myBST.whatLevelAmI(20);
  std::cout << "whatLevelAmI(20) " << nivelActual << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "search(15) " << myBST.search(15) << std::endl;
  std::cout << "search(22) " << myBST.search(22) << std::endl;
  std::cout << "search(3) " << myBST.search(3) << std::endl;
  
  // Borrar nodo sin hijos
  std::cout << "deleteNode(115) " << std::endl;
  myBST.deleteNode(115);
  myBST.print();

  // Borrar nodo con un hijo
  std::cout << "deleteNode(5) " << std::endl;
  myBST.deleteNode(5);
  myBST.print();

  // Borrar nodo con dos hijos
  std::cout << "deleteNode(20) " << std::endl;
  myBST.deleteNode(20);
  myBST.print();

}