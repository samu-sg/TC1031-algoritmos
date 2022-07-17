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
    //nuevos metodos
    DLLNode<T>* merge(DLLNode<T> *first, DLLNode<T> *second);
    DLLNode<T>* mergeSort(DLLNode<T> *head);
    DLLNode<T>* split(DLLNode<T> *head);

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
    void invert();
    DoubleLinkedList<T> getReversedSublist(int inicio, int fin);
    DLLNode<T> *getHead();
    DLLNode<T> *getTail();
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
  std::cout << "--- Creando una lista doblemente ligada vacia --- " << &head << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template<class T>
DLLNode<T>* DoubleLinkedList<T>::getHead() {
  return head;
}

template<class T>
DLLNode<T>* DoubleLinkedList<T>::getTail() {
  return tail;
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
DLLNode<T>* DoubleLinkedList<T>::merge(DLLNode<T> *first, DLLNode<T> *second){
  // If first linked list is empty 
    if (!first) 
        return second; 
  
    // If second linked list is empty 
    if (!second) 
        return first; 
  
    // Pick the smaller value 
    if (first->data < second->data) { 
        first->next = merge(first->next,second); 
        first->next->prev = first; 
        first->prev = nullptr; 
        return first; 
    } 
    else{ 
        second->next = merge(first,second->next); 
        second->next->prev = second; 
        second->prev = nullptr; 
        return second; 
    } 
}

template<class T>
DLLNode<T>* DoubleLinkedList<T>::mergeSort(DLLNode<T>* head){
   if (!head || !head->next) 
        return head; 
    DLLNode<T>* second = split(head); 
  
    // Recur for left and right halves 
    head = mergeSort(head);
    second = mergeSort(second);
  
    // Merge the two sorted halves 
    return merge(head,second);
}

template<class T>
DLLNode<T>* DoubleLinkedList<T>::split(DLLNode<T> *head) {
  DLLNode<T> *high = head, *low = head;
  while (high->next && high->next->next) {
    high = high->next->next;
    low = low->next;
  }
  DLLNode<T> *p = low->next;
  low->next = nullptr;
  return p;
}

template<class T>
// Ordena los datos de la lista usando el algoritmo mergesort. Complejidad O(n)
void DoubleLinkedList<T>::sort() {
  head = mergeSort(head);
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