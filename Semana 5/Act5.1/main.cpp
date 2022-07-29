/**
 * Johan Cabrera Peña A01635713
 * Samuel Sánchez García A00831772
 * Erika Alejandra Colín Tapia A01706555
 * 
 * Hashing Abierto
 * Metodo de Encadenamiento Externo
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
#include "OpenHash.h"

int main() {
    OpenHash<int, std::string> myTable(10);
    std::cout << "Table current size: " << myTable.getSize() << std::endl;

    try {
        std::cout << "ADD" << std::endl;
        std::cout << "add(3, \"5\")" << std::endl;
        myTable.add(3, "5");
        std::cout << "add(4, \"10\")" << std::endl;
        myTable.add(4, "10");
        std::cout << "add(6, \"15\")" << std::endl;
        myTable.add(6, "15");
        std::cout << "add(6, \"20\")" << std::endl;
        myTable.add(6, "20");
    }
    catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Table current size: " << myTable.getSize() << std::endl;
    myTable.print();
    std::cout << std::endl;

    std::cout << "FIND" << std::endl;
    try {
        std::cout << "Find 6: " << myTable.find(6) << std::endl;
        std::cout << "Find 3: " << myTable.find(3) << std::endl;
        std::cout << "Find 5: " << myTable.find(5) << std::endl;
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "REMOVE" << std::endl;
    std::cout << "remove(3)" << std::endl;
    myTable.remove(3);
    std::cout << "remove(6)" << std::endl;
    myTable.remove(6);
    myTable.print();
}