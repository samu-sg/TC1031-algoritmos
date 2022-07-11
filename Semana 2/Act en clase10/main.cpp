#include <iostream>
#include "LinkedList.h"

int main() {
    std::cout << "Ejemplo de listas ligadas\n";
    LinkedList<int> miLista;

    std::cout << "numElements: " << miLista.getNumElements() << std::endl;

    // addFirst
    std::cout << "Agregando 5 elementos al frente..." << std::endl;
    for (int i = 0; i < 6; i++) {
        miLista.addFirst(i);
    }

    std::cout << "numElements: " << miLista.getNumElements() << std::endl;
    miLista.printList();
    std::cout << std::endl;

    // addLast
    std::cout << "Agregando 5 elementos al final..." << std::endl;
    for (int i = 10; i < 15; i++) {
        miLista.addLast(i);
    }
    
    std::cout << "numElements: " << miLista.getNumElements() << std::endl;
    miLista.printList();
    std::cout << std::endl;

    return 0;
}
