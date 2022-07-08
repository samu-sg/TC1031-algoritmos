#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

using std::vector;

class Vector{
  public:

    // Métodos de ordenamiento
    void ordenaBurbuja(vector<int> &vector, int &compara, int &nSwaps);
    void ordenaMerge(vector<int> &vector, int low, int high, int &compara);
    void merge(vector<int> &vector, int low, int m, int high, int &compara);
    void ordenaQuick(vector<int> &vector, int low, int high, int &compara, int &nSwaps);
    int partition(vector<int> &vector, int low, int high, int &compara, int &nSwaps);

    // Métodos de búsqueda
    int busquedaSecuencialOrd(vector<int> vectorOrdenado, int dato, int &compara);
    int busquedaBinaria(vector<int> vectorOrdenado, int low, int high, int dato, int &compara);

};


#endif//VECTOR_H