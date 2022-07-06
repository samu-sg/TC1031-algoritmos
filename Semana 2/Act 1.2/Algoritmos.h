#ifndef _ALGORITMOS_H
#define _ALGORITMOS_H

#include <iostream>
#include <vector>

using std::vector;

class Algoritmos {
  public:
    // Métodos de ordenamiento
    void ordenaBurbuja(vector<int> &vector, int &compara, int &nSwaps);
    void ordenaMerge(vector<int> &vector, int low, int high, int &compara);
    void merge(vector<int> &vector, int low, int m, int high, int &compara);
    void ordenaQuick(vector<int> &vector, int &compara, int &nSwaps);

    // Métodos de búsqueda
    int busquedaSecuencialOrd(vector<int> vectorOrdenado, int dato, int &compara);
    int busquedaBinaria(vector<int> vectorOrdenado, int low, int high, int dato, int &compara);
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

// Ordena en forma ascendente los datos con el método Merge - Complejidad O(n log n)
void Algoritmos::ordenaMerge(vector<int> &vector, int low, int high, int &compara) {
  if(low < high) {
    int m = (low + high) / 2;
    // Utiliza recursión para ordenar las mitades
    ordenaMerge(vector, low, m, compara);
    ordenaMerge(vector, m + 1, high, compara);
    // Fusiona ambas mitades ordenadas
    merge(vector, low, m, high, compara);
  }
}

// Método auxiliar de ordenaMerge - fusiona las mitades ordenadas
void Algoritmos::merge(vector<int> &vector, int low, int m, int high, int &compara) {
  int i, j, k;
  int n1 = m - low + 1;
  int n2 = high - m;
  std::vector<int> L(n1);
  std::vector<int> R(n2);

  for (i = 0; i < n1; i++)
    L[i] = vector[low + i];
  for (j = 0; j < n2; j++)
    R[j] = vector[m + 1 + j];
  i = j = 0;
  k = low;
  while (i < n1 && j < n2) {
    compara++;
    if (L[i] < R[j]) {
      vector[k] = L[i];
      i++;
    } else {
      vector[k] = R[j];
      j++;
    }
    k++;
  }
  
  // Revisa si hay elementos sobrantes 
  while (i < n1) {
    vector[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    vector[k] = R[j];
    j++;
    k++;
  }
}

// Ordena en forma ascendente los datos con el método de Quicksort - Complejidad O(n^2) en el peor caso
void Algoritmos::ordenaQuick(vector<int> &vector, int &compara, int &nSwaps) {
  
}

// Realiza la búsqueda secuencial de un dato entero dentro del vector ordenado - Complejidad O(n)
int Algoritmos::busquedaSecuencialOrd(vector<int> vectorOrdenado, int dato, int &compara) {
  compara++;
  for(int i = 0; i < vectorOrdenado.size(); i++) {
    if(dato <= vectorOrdenado[i]) {
      if(vectorOrdenado[i] == dato)
        return i;
      else
        return -1;
    }
  }
  return -1;
}

// Realiza la búsqueda binaria de un dato entero dentro del vector ordenado - Complejidad O(log n)
int Algoritmos::busquedaBinaria(vector<int> vectorOrdenado, int low, int high, int dato, int &compara) {
  int m;
  if (low > high) return -1;
  m = low + (high -low)/2;
  compara++;
  if (dato == vectorOrdenado[m]) return m;
  else if (dato < vectorOrdenado[m]) 
      return busquedaBinaria(vectorOrdenado, low, m - 1, dato, compara);
  else 
    return busquedaBinaria(vectorOrdenado, m + 1, high, dato, compara);
}

#endif // _ALGORITMOS_H