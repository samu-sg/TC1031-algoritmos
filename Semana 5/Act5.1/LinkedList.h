#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.h"
#include <iostream>

template <class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int numElements;

public:
    LinkedList();
    ~LinkedList();
    int getNumElements();
    void printList();
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    T getData(int position);
    T findData(T value);
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T>* prev, * q;
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
    Node<T>* ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->data.getData() << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

template<class T>
void LinkedList<T>::addFirst(T value) {
    // creando un nuevo nodo de la lista
    Node<T>* newNode = new Node<T>(value);
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
void LinkedList<T>::addLast(T value) {
    // Si la lista esta vacia if(head == nullptr)
    if (numElements == 0) {
        addFirst(value);
    }
    else {
        // creando un nuevo nodo de la lista
        Node<T>* newNode = new Node<T>(value);
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
        numElements++;
    }
}

template<class T>
bool LinkedList<T>::deleteData(T value) {
    bool estado = false;
    // Si la lista esta vacia
    if (numElements == 0) {
        return estado;
    }
    else {
        Node<T>* p = head;
        Node<T>* prev = nullptr;
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
        }
        else if (p->next == nullptr) { // borrar ultimo en la lista
            prev->next = nullptr;
            tail = prev;
        }
        else {
            prev->next = p->next;
        }
        delete p;
        numElements--;
        estado = true;
        return estado;
    }
}

template<class T>
T LinkedList<T>::getData(int position) {
    if (position < 0 || position >= numElements) {
        throw std::out_of_range("Indice fuera de rango");
    }
    else {
        if (position == 0)
            return head->data;
        Node<T>* p = head;
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
T LinkedList<T>::findData(T value) {
    Node<T>* p = head;
    while (p != nullptr) {
        if (p->data == value)
            return p->data;
        p = p->next;
    }
    return {};
}

#endif // _LINKEDLIST_H_