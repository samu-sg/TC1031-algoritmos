#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include "BSTNode.h"

template <class T> 
class BST {
  private:
    BSTNode<T> *root;
    BSTNode<T>* insertRecursive(BSTNode<T> *p, T value);
    BSTNode<T>* getSuccessor(BSTNode<T> *p);
    BSTNode<T>* deleteRecursive(BSTNode<T> *p, T value);
    void print2D(BSTNode<T> *p, int space);
    void inorderRecursive(BSTNode<T> *p);
    void postOrderRecursive(BSTNode<T> *p);
    void preOrderRecursive(BSTNode<T> *p);
    int getHeight(BSTNode<T>* root);
    void printNodesPerLevel(BSTNode<T> *root, int level);
    bool Ancestors(BSTNode<T>* root, int value);

  public:
    BST();
    ~BST();
    void clearMemory(BSTNode<T> *p);
    bool search(T value);
    void insert(T value);
    void deleteNode(T value);
    void print();
    void callInorder();
    void callPostOrder();
    void callPreOrder();
    // ToDo
    void levelByLevel();  
    int height();
    void ancestors(int value);
    int whatLevelAmI(int value);
};

template <class T>
BST<T>::BST() {
  std::cout << "---> Creando un BinarySearchTree vacio: " <<  this << std::endl;
  root = nullptr;
}

template <class T>
BST<T>::~BST() {
  std::cout << "---> Liberando memoria del BinarySearchTree: " <<  this << std::endl;
  clearMemory(root);
  root = nullptr;
}

template <class T>
// Libera la memoria del Binary Search Tree. Complejidad O(1)
void BST<T>::clearMemory(BSTNode<T> *p) {
  if (p != nullptr) {
    clearMemory(p->left);
    clearMemory(p->right);
    delete p;
    p = nullptr;
  }
}

template <class T>
// Verifica si el valor en el parametro se encuentra en el BST. Complejidad O(n)
bool BST<T>::search(T value) {
  BSTNode<T> *p = root;
  while (p != nullptr) {
    if (p->data == value)
      return true;
    else
      p = (value < p->data ? p->left : p->right);
  }
  return false;
}

template <class T>
// Inserta un nuevo nodo en el BST. Complejidad O(n)
BSTNode<T>* BST<T>::insertRecursive(BSTNode<T> *p, T value) {
  if (p == nullptr) // El BST esta vacio
    p = new BSTNode<T>(value);
  else if (value < p->data)
    p->left = insertRecursive(p->left, value);
  else if (value > p->data)
    p->right = insertRecursive(p->right, value);
  else
    std::cout << "El elemento " << value << " ya existe en el BST" << std::endl;
  return p;
}

template <class T>
// Complejidad O(n) 
void BST<T>::insert(T value) {
  root = insertRecursive(root, value);
}

template <class T>
// . Complejidad O(n) 
BSTNode<T> * BST<T>::getSuccessor(BSTNode<T> *p) {
  BSTNode<T> *current = p;
  while (current && current->left != nullptr) {
    current = current->left;
  }
  return current;
}

template <class T>
// Busca el nodo a borrar y lo elimina. Complejidad O(n) 
BSTNode<T>* BST<T>::deleteRecursive(BSTNode<T> *p, T value) {
  BSTNode<T> *current = p;
  // caso base, arbol vacio
  if (p == nullptr)
    return p;
  if (value < p->data)
    p->left = deleteRecursive(p->left, value);
  else if (value > p->data)
    p->right = deleteRecursive(p->right, value);
  else { // Hemos localizado el nodo a borrar (apuntado por p)
    // El nodo a borrar no tiene ningun hijo
    if (p->left == nullptr && p->right == nullptr) {
      delete p;
      p = nullptr;
      return p;
    }
    else if (p->left == nullptr) { // El nodo a borrar solo tiene hijo derecho
      current = p->right;
      delete p;
      p = nullptr;
      return current;
    } 
    else if (p->right == nullptr) { // El nodo a borrar solo tiene hijo izquierdo
      current = p->left;
      delete p;
      p = nullptr;
      return current;
    }
    // El nodo a borrar tiene dos hijos
    current = getSuccessor(p->right);
    p->data = current->data;
    p->right = deleteRecursive(p->right, current->data);
  }
  return p;
}

template <class T>
// Complejidad O(n) 
void BST<T>::deleteNode(T value) {
   root = deleteRecursive(root, value);
}

template <class T>
// Imprime el BST. Complejidad O(n) 
void BST<T>::print2D(BSTNode<T> *root, int space) {
  // Caso base
  if (root == nullptr)
      return;
  // Incrementa la distancia entre niveles
  space += 5;
  // Procesa hijo derecho
  print2D(root->right, space);
  // Imprime el nodo actual despues de los espacios necesarios
  std::cout << std::endl;
  for (int i = 5; i < space; i++)
      std::cout << " ";
  std::cout << root->data << std::endl;
  // Procesa el hijo izquierdo 
  print2D(root->left, space);
}

template <class T>
// Complejidad O(n) 
void BST<T>::print() {
  print2D(root, 0);
}

template <class T>
// Despliega los datos Inorder. Complejidad O(n) 
void BST<T>::inorderRecursive(BSTNode<T> *p) {
  if (p != nullptr) {
    inorderRecursive(p->left);
    std::cout << p->data << " ";
    inorderRecursive(p->right);
  }
}

template <class T>
// Compplejidad O(n)
void BST<T>::callInorder() {
  inorderRecursive(root);
  std::cout << std::endl;
}

template<class T>
// Despliega los datos Postorder. Complejidad O(n) 
void 
BST<T>::postOrderRecursive(BSTNode<T> *p){
  if (p != nullptr) {
    postOrderRecursive(p->left);
    postOrderRecursive(p->right);
    std::cout << p->data << " ";
  }
}

template <class T>
// Compplejidad O(n)
void BST<T>::callPostOrder(){
  postOrderRecursive(root);
  std::cout << std::endl;
}

template <class T>
// Despliega los datos Preorder. Complejidad O(n) 
void BST<T>::preOrderRecursive(BSTNode<T> *p){
  if (p != nullptr) {
    std::cout << p->data << " ";
    preOrderRecursive(p->left);
    preOrderRecursive(p->right);
  }
}

template <class T>
// Compplejidad O(n)
void BST<T>::callPreOrder(){
  preOrderRecursive(root);
  std::cout << std::endl;
}

template<class T>
// Obtiene la altura del arbol. Complejidad O(n) 
int BST<T>::getHeight(BSTNode<T>* root){
  int LadoIzq;
  int LadoDer;
  if (root == nullptr)
    return 0;
  else {
    LadoIzq = getHeight(root->left);
    LadoDer = getHeight(root->right);
  }
  if (LadoIzq > LadoDer)
    return LadoIzq + 1;
  else
    return LadoDer + 1;
}
//codigo de: https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

template <class T>
// Regresa la altura del BST. Complejidad O(n) 
int BST<T>::height() {
  return getHeight(root);
}

template <class T>
// Despliega los nodos por cada nivel. Complejidad O(n) 
void BST<T>::printNodesPerLevel(BSTNode<T> *root, int level) {
  if (root == nullptr)
    return;
  else if (level == 1)
    std::cout << root->data << " ";
  else if (level > 1)
    printNodesPerLevel(root->left, level - 1);
    printNodesPerLevel(root->right, level - 1);
}

template <class T>
// Despliega los datos Level by level. Complejidad O(n) 
void BST<T>::levelByLevel() {
  int altura = getHeight(root);
  for (int i = 1; i <= altura; i++)
    printNodesPerLevel(root, i);
  std::cout << std::endl;
}

template<class T>
// Regresa un entero que indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre en el BST. Complejidad O(n) 
int BST<T>::whatLevelAmI(int value) {
  BSTNode<T>* p = root;
  while (p != nullptr) {
    if (p->data == value)
      return height() - getHeight(p) + 1;
    else
      p = (value < p->data ? p->left : p->right);
  }
  std::cout << std::endl;
  return -1;
}

template<class T>
// Despliega los ancestros de un dato. Compplejidad O(n)
bool BST<T>::Ancestors(BSTNode<T>* root, int value) {
  //casos base
  if (root == nullptr)
    return false;
  else if (root->data == value)
    return true;
  
  if (Ancestors(root->left, value) || Ancestors(root->right, value)) {
    std::cout << root->data<<" ";
    return true;
  }
  return false;
}

template<class T>
// Despliega los ancestros del dato en los parametros. Compplejidad O(n)
void BST<T>::ancestors(int value){
  Ancestors(root, value);
  std::cout << std::endl;
}

#endif // _BST__H_