#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Registro.h"

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

  public:
    MaxHeap();
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

template<class T>
MaxHeap<T>::MaxHeap(){
  std::cout << "--->Creando un MaxHeap: " << this << std::endl;
  numElements = 0;
  maxCapacity = 20000;
  data.resize(maxCapacity);
}

template <class T>
MaxHeap<T>::MaxHeap(int capacity) {
  std::cout << " ---> Creando un MaxHeap vacio: " << this << std::endl;
  numElements = 0;
  maxCapacity = capacity;
  data.resize(maxCapacity);
}

template <class T>
MaxHeap<T>::~MaxHeap() {
  std::cout << " ---> Liberando la memoria del MaxHeap: " << this << std::endl;
  numElements = 0;
  maxCapacity = 0;
  data.clear();
}

template <class T>
bool MaxHeap<T>::isEmpty() {
  return (numElements <= 0);
}

template <class T>
int MaxHeap<T>::getCapacity() {
  return maxCapacity;
}

template <class T>
int MaxHeap<T>::getNumElements() {
  return numElements;
}

template <class T>
void MaxHeap<T>::print() {
  std::cout << "El contenido del MaxHeap es: " << std::endl;
  for (int i = 0; i < numElements; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

template <class T>
int MaxHeap<T>::parent(int i) {
  return (i-1)/2;
}

template<class T>
int MaxHeap<T>::left(int i){
  return (2 * i + 1);
}

template<class T>
int MaxHeap<T>::right(int i){
  return (2 * i + 2);
}

template <class T>
void MaxHeap<T>::push(T key) {
  if (numElements == maxCapacity) {
    throw std::out_of_range("Overflow: no se puede insertar la llave");
  }
  // Insertar la nueva llave al final del vector
  int i = numElements;
  data[i] = key;
  numElements++;
  // Reparar las propiedades del MaxHeap
  while (i != 0 && data[parent(i)].getRep() < data[i].getRep()) {
    std::swap(data[i], data[parent(i)]);
    i = parent(i);
  }
}

template<class T>
T MaxHeap<T>::top(){
  return data[0];
}

template<class T>
void MaxHeap<T>::pop(){
  int current = 0;
  data[0] = data[numElements - 1];
  numElements--;
  while (left(current) < numElements){
    int child;
    if (right(current) == numElements){
      child = left(current);
    }else{
      if(data[left(current)].getRep() > data[right(current)].getRep()){
        child = left(current);
      }else{
        child = right(current);
      }
    }
    if (data[current].getRep() < data[child].getRep()){
      T x = data[current];
      data[current] = data[child];
      data[child] = x;
      current = child;
    }else{
      break;
    }
  }
}

#endif // _MAXHEAP_H_