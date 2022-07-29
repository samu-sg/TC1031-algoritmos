#ifndef __HASH_NODE_H_
#define __HASH_NODE_H_

#include <algorithm>
#include <iterator>
#include <vector>

template <class K, class T> class HashNode {

private:
	K key;
	T data;

public:
	HashNode();
	HashNode(K key, T data);
	K getKey();
	T getData();
	void setKey(K keyVal);
	// sobrecarga para findData()
	bool operator ==(const HashNode&) const;
	// sobrecarga para deleteData()
	bool operator !=(const HashNode&) const;
};

template <class K, class T> HashNode<K, T>::HashNode() {
	key = 0;
}

template<class K, class T> HashNode<K, T>::HashNode(K key, T data) {
	this->key = key;
	this->data = data;
}

template <class K, class T> K HashNode<K, T>::getKey() {
	return key;
}

template <class K, class T> T HashNode<K, T>::getData() { return data; }

template <class K, class T> void HashNode<K, T>::setKey(K keyVal) {
	key = keyVal;
}

template <class K, class T> bool HashNode<K, T>::operator ==(const HashNode<K, T>& other) const {
	return this->key == other.key;
}

template <class K, class T> bool HashNode<K, T>::operator !=(const HashNode<K, T>& other) const {
	return this->key != other.key;
}

#endif // __HASH_NODE_H_