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
};

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T> *prev, *q;
    p = head;
    while (prev != nullptr) {
        q = prev->next;
        delete prev;
        prev = q;
    }
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template <class T>
int LinkedList<T>::getNumElements() {
    return numElements;
}

template <class T>
void LinkedList<T>::printList() {
    Node<T> *newNode = head;
    while (newNode != nullptr) {
        std::cout << newNode->data << " ";
        newNode = newNode->next;
    }
    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::addFirst(T value) {
    // crear un nuevo nodo de la lista
    Node *newNode = new Node<T>(value);

    // Si la lista está vacía
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    numElements++;
}

template <class T>
void LinkedList<T>::addLast(T value) {
    // Si la lista está vacía
    if (head == nullptr) {
        addFirst();
    }
    else {
        // Crear un nuevo nodo de la lista
        Node *newNode = new Node<T>(value);
        tail->next = newNode;
        tail = newNode;
        numElements++;
    }
}

#endif // _LINKEDLIST_H_