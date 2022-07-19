#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class MaxHeap {
  private:
    // contiene los elementos del heap
    std::vector<T> data;
    // capacidad maxima del heap
    int maxCapacity;
    // numero de elementos actualmente en el heap
    int numElements;

    int parent(int i);
    int left(int i);
    int right(int i);

    void maxHeapify(int i);

  public:
    MaxHeap(int capacity);
    ~MaxHeap();
    bool isEmpty();
    int getCapacity();
    int getNumElements();
    void print();
    void push(T key);
    T top();
    void pop();
  
};

template <class T>
// Complejidad O(1)
MaxHeap<T>::MaxHeap(int capacity) {
  std::cout << " ---> Creando un MaxHeap vacio: " << this << std::endl;
  numElements = 0;
  maxCapacity = capacity;
  data.resize(maxCapacity);
}

template <class T>
// Complejidad O(1)
MaxHeap<T>::~MaxHeap() {
  std::cout << " ---> Liberando la memoria del MaxHeap: " << this << std::endl;
  numElements = 0;
  maxCapacity = 0;
  data.clear();
}

template <class T>
// Complejidad O(1)
bool MaxHeap<T>::isEmpty() {
  return (numElements == 0);
}

template <class T>
// Complejidad O(1)
int MaxHeap<T>::getCapacity() {
  return maxCapacity;
}

template <class T>
// Complejidad O(1)
int MaxHeap<T>::getNumElements() {
  return numElements;
}

template <class T>
// Complejidad O(1)
int MaxHeap<T>::parent(int i) {
  return (i-1)/2;
}

template <class T>
// Complejidad O(1)
int MaxHeap<T>::left(int i) {
  return (2*i + 1);
}

template <class T>
// Complejidad O(1)
int MaxHeap<T>::right(int i) {
  return (2*i + 2);
}


template <class T>
// Complejidad O(n)
void MaxHeap<T>::print() {
  std::cout << "El contenido del MaxHeap es: " << std::endl;
  for (int i = 0; i < numElements; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

template <class T>
// Agrega un dato a la fila priorizada. Complejidad O(log n)
void MaxHeap<T>::push(T key) {
  if (numElements == maxCapacity) {
    throw std::out_of_range("Overflow: no se puede insertar la llave");
  }
  // Insertar la nueva llave al final del vector
  int i = numElements;
  data[i] = key;
  numElements++;
  // Reparar las propiedades del MaxHeap
  while (i != 0 && data[parent(i)] < data[i]) {
    std::swap(data[i], data[parent(i)]);
    i = parent(i);
  }
}

template <class T> 
// Regresa el valor con mayor prioridad en la fila priorizada. Complejidad O(1)
T MaxHeap<T>::top() {
  if (isEmpty()) 
    throw std::out_of_range("El vector está vacío\n");
  else
    return data[0];
}

template <class T>
// https://www.geeksforgeeks.org/binary-heap/
// max-heapify tree with the root at given index. Complejidad O(log n)
void MaxHeap<T>::maxHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int max = i;
  if (l < numElements && data[l] > data[i])
    max = l;
  if (r < numElements && data[r] > data[i])
    max = r;
  if (max != i) {
    std::swap(data[i], data[max]);
    maxHeapify(max);
  }
}

template <class T> 
// Saca el dato que tiene mayor prioridad. Complejidad O(log n)
void MaxHeap<T>::pop() {
  if (isEmpty()) {
    throw std::out_of_range("El vector está vacío\n");
  }
  else {
    // Borrar el dato 
    data[0] = data[numElements - 1];
    numElements--;
    // Repara el MaxHeap
    maxHeapify(0);
  }
}

#endif // _MAXHEAP_H_