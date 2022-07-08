#include "Vector.h"
#include <iostream>

// Ordena en forma ascendente los datos con el método de Burbuja - Complejidad O(n^2)
void Vector::ordenaBurbuja(vector<int> &vector, int &compara, int &nSwaps) {
  compara = nSwaps = 0;
  for (int i = 0; i < vector.size() - 1; i++) {
    for (int j = 0; j < vector.size() - 1 - i; j++) {
      compara++;
      if (vector[j] > vector[j + 1])
        std::swap(vector[j], vector[j + 1]);
    }
  }
}

// Ordena en forma ascendente los datos con el método Merge - Complejidad O(n log n)
void Vector::ordenaMerge(vector<int> &vector, int low, int high, int &compara) {
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
void Vector::merge(vector<int>& vector, int low, int m, int high, int &compara) {
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
  // Se encargan de los elementos sobrantes
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

// Ordena en forma ascendente los datos con el método de Quicksort - Complejidad O(n^2)
void Vector::ordenaQuick(vector<int> &vector, int low, int high, int &compara, int &nSwaps) {
  if(low < high) {
    int pi = partition(vector, low, high, compara, nSwaps);
    ordenaQuick(vector, low, pi - 1, compara, nSwaps);
    ordenaQuick(vector, pi + 1, high, compara, nSwaps);
  }
}

int Vector::partition(vector<int> &vector, int low, int high, int &compara, int &nSwaps) {
  int pivot = vector[high];
  int i = low - 1;
  for(int j = low; j <= high; j++) {
    if(vector[j] < pivot) {
      i++;
      std::swap(vector[i], vector[j]);
      nSwaps++;
    }
    compara++;
  }
  std::swap(vector[i + 1], vector[high]);
  nSwaps++;
  return i + 1;
}

// Realiza la búsqueda secuencial de un dato entero dentro del vector ordenado - Complejidad O(n)
int Vector::busquedaSecuencialOrd(vector<int> vectorOrdenado, int dato, int &compara) {
  for(int i = 0; i < vectorOrdenado.size(); i++) {
    compara++;
    if(dato <= vectorOrdenado[i]) {
      if(dato == vectorOrdenado[i])
        return i;
      else
        return -1;
    }
  }
  return -1;
}

// Realiza la búsqueda binaria de un dato entero dentro del vector ordenado - Complejidad O(log n)
int Vector::busquedaBinaria(vector<int> vectorOrdenado, int low, int high, int dato, int &compara) {
  int m;
  if (low > high) return -1;
  m = low + (high - low)/2;
  compara++;
  if (dato == vectorOrdenado[m]) return m;
  else if (dato < vectorOrdenado[m]) 
      return busquedaBinaria(vectorOrdenado, low, m - 1, dato, compara);
  else 
    return busquedaBinaria(vectorOrdenado, m + 1, high, dato, compara);
}