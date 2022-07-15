#ifndef _DoubleLinkedList_H_
#define _DoubleLinkedList_H_

#include "DLLNode.h"
#include <iostream>

template <class T>
class DoubleLinkedList {
  private:
    DLLNode<T> *head;
    DLLNode<T> *tail;
    int numElements;

  public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    int getNumElements();
    void printList();
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int posicion);
    T getData(int position);
    void updateData(T value, T newValue);
    void sort();
    void _sort(DLLNode<T>* low, DLLNode<T>* high);
    DLLNode<T>* Particion(DLLNode<T>* low, DLLNode<T>* high);
    void invert();
    DoubleLinkedList<T> getReversedSublist(int inicio, int fin);
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
  std::cout << "--- Creando una lista doblemente ligada vacia --- " << &head << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  std::cout << "--- Liberando memoria de la lista doblemente ligada --- " << &head << std::endl;
  DLLNode<T> *prev, *q;
  prev = head;
  while (prev != nullptr) {
    q = prev->next;
    delete prev;
    prev = q;
  }
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template<class T>
int DoubleLinkedList<T>::getNumElements() {
  return numElements;
}

template<class T>
void DoubleLinkedList<T>::printList() {
  DLLNode<T> *ptr = head;
  while (ptr != nullptr) {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

template<class T>
// Inserta un elemento al inicio de la lista. Complejidad O(1)
void DoubleLinkedList<T>::addFirst(T value) {
  // creando un nuevo nodo de la lista
  DLLNode<T> *newDLLNode = new DLLNode<T>(value);
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) {
    head = newDLLNode;
    tail = newDLLNode; 
  } 
  else {
    newDLLNode->next = head;
    head->prev = newDLLNode;
    head = newDLLNode;
  }
  numElements++;
}

template<class T>
// Inserta un elemento al final de la lista. Complejidad O(1)
void DoubleLinkedList<T>::addLast(T value) {
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) {
    addFirst(value);
  }
  else {
    // creando un nuevo nodo de la lista
    DLLNode<T> *newDLLNode = new DLLNode<T>(value);
    tail->next = newDLLNode;
    newDLLNode->prev = tail;
    tail = newDLLNode;
    numElements++;
  }
}

template<class T>
// Borra el primer elemento que se encuentre en la lista igual al parámetro de entrada. Complejidad O(n)
bool DoubleLinkedList<T>::deleteData(T value) {
  bool estado = false;
  // Si la lista esta vacia
  if (numElements == 0) {
    return estado;
  }
  else {
    DLLNode<T> *p = head;
    DLLNode<T> *previo = nullptr;
    // buscar value en la lista
    while (p != nullptr && p->data != value) {
      previo = p;
      p = p->next;
    }
    // si no existe value en la lista
    if (p == nullptr)
      return estado;
    // Si debe borrarse el primer elemento de la lista
    if (p == head) {
      head = p->next;
      if (head != nullptr)
        head->prev = nullptr;
    } else if (p->next == nullptr) { // borrar ultimo en la lista
      previo->next = nullptr;
      tail = previo;     
    } else { // cualquier otro elemento de la lista
      previo->next = p->next;
      p->next->prev = p->prev;
    }
    delete p;
    numElements--;
    estado = true;
    return estado;
  }
}

template<class T>
// Borra un elemento en una posición de la lista dada. Complejidad O(n)
bool DoubleLinkedList<T>::deleteAt(int position) {
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango");
  }
  else if (position == 0) { // Si debe borrarse el primer elemento
    DLLNode<T> *p = head;
    // Si la lista contiene solo un nodo
    if (head != nullptr && head->next == nullptr) {
      head = nullptr;
      tail = nullptr;
    }
    else {
      head = p->next;
      head->prev = nullptr;
    }
    delete p;
    numElements--;
    return true; 
  }
  else { // Si position > 0 
    DLLNode<T> *p = head, *q = nullptr;
    int index = 0;
    // Se busca el indice del elemento a borrar
    while (index != position) {
      q = p;
      p = p->next;
      index++;
    }
    // Si debe borrarse el último elemento
    if (p->next == nullptr) {
      q->next = nullptr;
      tail = q;
    }
    else { // Cualquier otro elemento en medio de la lista 
      q->next = p->next;
      p->next->prev = q;
    }
    delete p;
    numElements--;
    return true;
  }
}

template<class T>
// Lee el valor de un dato de la lista, de acuerdo con la posición recibida como parámetro de entrada. Complejidad O(n)
T DoubleLinkedList<T>::getData(int position) {
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango");
  }
  else {
    if (position == 0)
      return head->data;
    DLLNode<T> *p = head;
    int index = 0;
    while (p != nullptr) {
      if (index == position)
        return p->data;
      index++;
      p = p->next;
    }
    return {};
  }
}

template<class T>
// Actualiza el primer elemento que sea igual al valor recibido como parámetro con el valor del dato nuevo recibido como parámetro. Complejidad O(n)
void DoubleLinkedList<T>::updateData(T value, T newValue) {
  if (numElements > 0) {
    DLLNode<T> *p = head;
    DLLNode<T> *prev = nullptr;
    // buscar value en la lista
    while (p != nullptr && p->data != value) {
      prev = p;
      p = p->next;
    }
    // si existe value en la lista
    if (p != nullptr)
      p->data = newValue;
    else
      throw std::out_of_range("No se encontró el valor en la lista");
  }  
}

template<class T>
// Selecciona un elemento como pivote y lo coloca en su posición correcta. Los elementos más grandes a la derecha y los más pequeños a la izquierda. Complejidad O(n)
DLLNode<T>* DoubleLinkedList<T>::Particion(DLLNode<T>* low, DLLNode<T>* high) {
  // set pivot as h element 
  int x = high->data; 
  // similar to i = l-1 for array implementation 
  DLLNode<T> *i = low->prev; 
  // Similar to "for (int j = l; j <= h- 1; j++)" 
  for (DLLNode<T> *j = low; j != high; j = j->next) { 
    if (j->data <= x) { 
      // Similar to i++ for array 
      i = (i == nullptr)? low : i->next; 

      std::swap(i->data, j->data); 
    } 
  } 
  i = (i == nullptr)? low : i->next; // Similar to i++ 
  std::swap(i->data, high->data); 
  return i;
}

template<class T>
// Complejidad O(n)
void DoubleLinkedList<T>::_sort(DLLNode<T>* low, DLLNode<T>* high){
  if (high != nullptr && low != high && low != high->next) {
    DLLNode<T>* p = Particion(low, high);
    _sort(low, p->prev);
    _sort(p->next, high);
  }
}

template<class T>
// Ordena los datos de la lista usando el algoritmo quicksort. Complejidad O(n)
void DoubleLinkedList<T>::sort() {
    //llamamos al quicksort recursivo
    _sort(head, tail);
}

template<class T>
// Devuelve la misma lista en orden invertido. Complejidad O(n)
void DoubleLinkedList<T>::invert() {
  DLLNode<T>* ptr = head;
  while(ptr != nullptr) {
    std::swap(ptr->next, ptr->prev);
    ptr = ptr->prev;
  }
  std::swap(head, tail);
}

template<class T>
// Regresa una nueva sublista que comprende los elementos, en orden inverso, ubicados entre las posiciones inicio y fin de la lista. Complejidad O(n)
DoubleLinkedList<T> DoubleLinkedList<T>::getReversedSublist(int inicio, int fin){
  DoubleLinkedList<T> salida;
  DLLNode<T> *p = head;
  if (inicio < 0 || fin > numElements) {
    throw std::out_of_range("Indice fuera de rango");
  }
  else {
    for (int i = inicio; i <= fin; i++) {
      salida.addFirst(p->data);
      p = p->next;
    }
  }
  return salida;
}

#endif // _DoubleLinkedList_H_