#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include "HashNode.h"
#include "LinkedList.h"

template<class K, class T>
class OpenHash {
private:
    std::vector<LinkedList<HashNode<K, T>>> hashTable;
    int numElements;
    int maxCapacity; // preferible un numero primo

public:
    OpenHash(int selectedMaxSize);
    int getIndex(K keyVal);
    int getSize();
    void add(K keyVal, T value);
    T find(K keyVal);
    void remove(K keyVal);
    void print();
};

template<class K, class T>
OpenHash<K, T>::OpenHash(int selectedMaxSize) {
    maxCapacity = selectedMaxSize;
    numElements = 0;
    hashTable = std::vector<LinkedList<HashNode<K, T>>>(maxCapacity);
}

// Hash function recibe una llave
template<class K, class T>
int OpenHash<K, T>::getIndex(K keyVal) {
    return keyVal % maxCapacity;
}

template<class K, class T>
int OpenHash<K, T>::getSize() {
    return numElements;
}

template<class K, class T>
void OpenHash<K, T>::print() {
    std::cout << "Content of the hash table: " << std::endl;
    for (int i = 0; i < maxCapacity; i++) {
        if (hashTable[i].getNumElements() != 0) {
            std::cout << "Cell " << i << " - Data: ";
            hashTable[i].printList();
        }
    }
}

template<class K, class T>
void OpenHash<K, T>::add(K keyVal, T value) {
    if (numElements == maxCapacity) {
        throw std::out_of_range("Hash Table full");
    }

    // Compute the index of the table using a key and a hash function
    int hashIndex = getIndex(keyVal);
    HashNode<K, T> hashNode(keyVal, value);
    hashTable[hashIndex].addLast(hashNode);
    numElements++;
}

template<class K, class T>
T OpenHash<K, T>::find(K keyVal) {
    int hashIndex = getIndex(keyVal);
    HashNode<K, T> hashNode;
    hashNode.setKey(keyVal);
    HashNode<K, T> X = hashTable[hashIndex].findData(hashNode);
    if (X.getData() == "")
        throw std::invalid_argument("Cell is empty");
    return X.getData();
}

template<class K, class T>
void OpenHash<K, T>::remove(K keyVal) {
    find(keyVal);
    int hashIndex = getIndex(keyVal);
    HashNode<K, T> hashNode;
    hashNode.setKey(keyVal);
    hashTable[hashIndex].deleteData(hashNode);
    numElements--;
}

#endif // __HASH_TABLE_H_