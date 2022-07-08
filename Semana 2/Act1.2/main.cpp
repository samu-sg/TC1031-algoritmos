 /*
  * Johan Cabrera Peña A01635713
  * Samuel Sánchez García A00831772
  * Erika Alejandra Colín Tapia A01706555
  *
  * Compilación:
  *  g++ -std=c++17 *.cpp -o main
  *
  * Ejecución:
  *  ./main < TestCases-SortingAlgorithms/test01.txt
  */

//librerias
#include "Vector.h"
#include <iostream>
#include <vector>

//metodos
using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main(void) {
  Vector array;
    
  int i, tmp, size, opcOrden,opcBusqueda, key, valor; 
  int comparaOrden = 0;
  int comparaBusqueda = 0;
  int nswap, low = 0;
    
  cin >> size; 
  // cout << "Size: " << size << endl;
  cin >> opcOrden;
  // cout << "Algoritmo de ordenamiento: " << opcOrden << endl;
  cin >> opcBusqueda;
  // cout << "Algoritmo de búsqueda: " << opcBusqueda << endl;
  cin >> key;
  // cout << "Número a buscar: " << key << endl;
  
  // Declaración del vector
  vector<int> myVector;
  // Lectura de los elementos del arreglo
  for(i = 0; i < size; i++) {
    cin >> tmp;
    myVector.push_back(tmp);
  }

  // Bubble Sort
  if (opcOrden == 1) {
    array.ordenaBurbuja(myVector, comparaOrden, nswap);
    cout << "Comparaciones en ordenamiento: " << comparaOrden << endl;
    cout << "Intercambios (swaps): " << nswap << endl;
    if (opcBusqueda == 1) {
      cout << "Posición: " << array.busquedaSecuencialOrd(myVector, key, comparaBusqueda) << endl;
      cout << "Comparaciones en búsqueda: " << comparaBusqueda << endl;
    }
    else if (opcBusqueda == 2) {
      cout << "Posición: " << array.busquedaBinaria(myVector, low, size, key, comparaBusqueda) << endl;
      cout << "Comparaciones en búsqueda: " << comparaBusqueda << endl;
    }
  }

  // Merge Sort
  else if (opcOrden == 2) {
    array.ordenaMerge(myVector, low, size - 1, comparaOrden); 
    cout << "Comparaciones en ordenamiento: " << comparaOrden << endl;
    cout << "Intercambios (swaps): N/A" << endl;
    if (opcBusqueda == 1) {
      cout << "Posición: " << array.busquedaSecuencialOrd(myVector, key, comparaBusqueda) << endl;
      cout << "Comparaciones en búsqueda: " << comparaBusqueda << endl;
    }
    else if (opcBusqueda == 2) {
      cout << "Posición: " << array.busquedaBinaria(myVector, low, size, key, comparaBusqueda) << endl;
      cout << "Comparaciones en búsqueda: " << comparaBusqueda << endl;
    }
  }

  // Quick Sort
  else if (opcOrden == 3) {
    array.ordenaQuick(myVector, low, size - 1, comparaOrden, nswap);
    cout << "Comparaciones en ordenamiento: " << comparaOrden << endl;
    cout << "Intercambios (swaps): " << nswap << endl;
    if (opcBusqueda == 1) {
      cout << "Posición: " << array.busquedaSecuencialOrd(myVector, key, comparaBusqueda) << endl;
      cout << "Comparaciones en búsqueda: " << comparaBusqueda << endl;
    }
    else if (opcBusqueda == 2) {
      cout << "Posición: " << array.busquedaBinaria(myVector, low, size, key, comparaBusqueda) << endl;
    }    
  }

  cout << "Arreglo ordenado\n";
  for (int j = 0; j < size; j++) {
    cout << myVector[j] << " ";
  }
  cout << endl;

  return 0;
}