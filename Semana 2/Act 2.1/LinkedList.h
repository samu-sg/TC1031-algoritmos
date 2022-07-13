#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.h"
#include <iostream>

template <class T>
class LinkedList {
  private:
    Node<T> *head;
    Node<T> *tail;
    int numElements;

  public:
    LinkedList();
    ~LinkedList();
    int getNumElements();
    void printList();
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int posicion);
    T getData(int position);
    void updateData(T value, T newValue);

    int findData(T value);
    void updateAt(int posicion, T newValue);
    void operator=(const LinkedList<T> &other);
};

template<class T>
LinkedList<T>::LinkedList() {
  std::cout << "--- Creando una lista vacia --- " << &head << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
  std::cout << "--- Liberando memoria de la lista --- " << &head << std::endl;
  Node<T> *prev, *q;
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
int LinkedList<T>::getNumElements() {
  return numElements;
}

template<class T>
void LinkedList<T>::printList() {
  Node<T> *ptr = head;
  while (ptr != nullptr) {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

template<class T>
// Inserta un elemento al inicio de la lista. Complejidad O(1)
void LinkedList<T>::addFirst(T value) {
  // creando un nuevo nodo de la lista
  Node<T> *newNode = new Node<T>(value);
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) {
    head = newNode;
    tail = newNode; 
  } 
  else {
    newNode->next = head;
    head = newNode;
  }
  numElements++;
}

template<class T>
// Inserta un elemento al final de la lista. Complejidad O()
void LinkedList<T>::addLast(T value) {
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0) {
    addFirst(value);
  }
  else {
    // creando un nuevo nodo de la lista
    Node<T> *newNode = new Node<T>(value);
    tail->next = newNode;
    tail = newNode;
    numElements++;
  }
}

template<class T>
// Borra el primer elemento que se encuentre en la lista igual al parámetro de entrada. Complejidad O(n)
bool LinkedList<T>::deleteData(T value) {
  bool estado = false;
  // Si la lista esta vacia
  if (numElements == 0) {
    return estado;
  }
  else {
    Node<T> *p = head;
    Node<T> *prev = nullptr;
    // buscar value en la lista
    while (p != nullptr && p->data != value) {
      prev = p;
      p = p->next;
    }
    // si no existe value en la lista
    if (p == nullptr)
      return estado;
    // Si debe borrarse el primer elemento de la lista
    if (p == head) {
      head = p->next;
    } else if (p->next == nullptr) { // borrar ultimo en la lista
      prev->next = nullptr;
      tail = prev;     
    } else {
      prev->next = p->next;
    }
    delete p;
    numElements--;
    estado = true;
    return estado;
  }
}

template<class T>
// Borra un elemento en una posición de la lista dada. Complejidad O(n)
bool LinkedList<T>::deleteAt(int position) {
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango");
  }
  else if (position == 0) { // Si debe borrarse el primer elemento
    Node<T> *p = head;
    // Si la lista contiene solo un nodo
    if (head != nullptr && head->next == nullptr) {
      head = nullptr;
      tail = nullptr;
    }
    else {
      head = p->next;
    }
    delete p;
    numElements--;
    return true; 
  }
  else { // Si la lista contiene mas de un nodo
    Node<T> *p = head, *q = nullptr;
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
    }
    delete p;
    numElements--;
    return true;
  }
}

template<class T>
// Lee el valor de un dato de la lista, de acuerdo con la posición recibida como parámetro de entrada. Complejidad O(n)
T LinkedList<T>::getData(int position) {
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango");
  }
  else {
    if (position == 0)
      return head->data;
    Node<T> *p = head;
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
void LinkedList<T>::updateData(T value, T newValue) {
  if (numElements > 0) {
    Node<T> *p = head;
    Node<T> *prev = nullptr;
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
// Busca un elemento en la lista. Complejdad O(n)
int LinkedList<T>::findData(T value) {
  Node<T> *p = head;
  int position = 0;

  while(p->data != value && p->next != nullptr) {
    p = p->next;
    position++;
  }
  if(p->data == value) 
    return position;
  else
    return -1;
}

template<class T>
// Actualiza un elemento en una posición recibida como parámetro con el valor de un dato recibido como parámetro. Complejidad O(n)
void LinkedList<T>::updateAt(int posicion, T newValue) {
  if (numElements > 0) {
    Node<T> *p = head;
    int pos = 0; 
    while (pos != posicion && p->next != nullptr) {
      pos++;
      p = p->next;
    }
    if (pos == posicion) {
      p->data = newValue;
    }
    else
      throw std::out_of_range("La posición está fuera del rango");
  }  
}

template<class T>
// Actualiza la lista con base en otra lista. Complejidad O(n)
void LinkedList<T>::operator=(const LinkedList<T>& other){
    for(int i = 0; i < other.getNumElements(); i++) {
        other->addLast(i);
    }
}

#endif // _LINKEDLIST_H_