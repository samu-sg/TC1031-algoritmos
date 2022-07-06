#ifndef _ALGORITMOS_H
#define _ALGORITMOS_H

#include <iostream>
#include <vector>

using std::vector;

class Algoritmos {
  public:
    // Métodos de ordenamiento
    void ordenaBurbuja(vector<int> &vector, int &compara, int &nSwaps);
    void ordenaMerge(vector<int> &vector, int &compara, int &nSwaps);
    void ordenaQuick(vector<int> &vector, int &compara, int &nSwaps);

    // Métodos de búsqueda
    int busquedaSecuencialOrd(vector<int>, int dato);
    int busquedaBinaria(vector<int>, int dato);
};

// Ordena en forma ascendente los datos con el método de Burbuja - Complejidad O(n^2) en el peor caso
void Algoritmos::ordenaBurbuja(vector<int> &vector, int &compara, int &nSwaps) {
  compara = nSwaps = 0;
  for(int i = 0; i < vector.size() - 1; i++) {
    for(int j = 0; j < vector.size() - 1 - i; j++) {
      compara++;
      if(vector[j] > vector[j + 1]) {
        std::swap(vector[j], vector[j + 1]);
        nSwaps++;
      }
    }
  }
}

// Ordena en forma ascendente los datos con el método Merge - Complejidad O()
void Algoritmos::ordenaMerge(vector<int> &vector, int &compara, int &nSwaps) {
  
}

// Ordena en forma ascendente los datos con el método de Quicksort - Complejidad O()
void Algoritmos::ordenaQuick(vector<int> &vector, int &compara, int &nSwaps) {
  
}

// Realiza la búsqueda secuencial de un dato entero dentro del vector ordenado - Complejidad O(n)
int Algoritmos::busquedaSecuencialOrd(vector<int>, int dato) {
  
}

// Realiza la búsqueda binaria de un dato entero dentro del vector ordenado - Complejidad O(log n)
int Algoritmos::busquedaBinaria(vector<int>, int dato) {
  
}

#endif // _ALGORITMOS_H