#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>
#include <vector>

const int MAX = 100;

template <class T>
class ListaTemplate
{
private:
  std::vector<T> data;
  int currentSize;

public:
  ListaTemplate();
  bool insert(T value);
  void erase();
  T getData(int indice);
  int getSize();
  void print();
};

// Constructor
template <class T>
ListaTemplate<T>::ListaTemplate()
{
  currentSize = 0;
}

// Recibe el valor del número que se desea insertar; si hay espacio disponible, se coloca al final del vector y se incrementa en 1 size.
template <class T>
bool ListaTemplate<T>::insert(T value)
{
  if (currentSize < MAX)
  {
    data.push_back(value);
    currentSize++;
    return true;
  }
  else
    return false;
}

// Si el vector no está vacío, despliega el último elemento del vector (el que está en la posición size-1) y disminuye en 1 el tamaño de size. Si el vector está vacío, despliega el mensaje: “NO HAY ELEMENTOS”.
template <class T>
void ListaTemplate<T>::erase()
{
  if (currentSize > 0)
  {
    std::cout << getData(currentSize - 1) << std::endl;
    data.pop_back();
    currentSize--;
  }
  else
    std::cout << "NO HAY ELEMENTOS" << std::endl;
}

// Recibe la posición de donde se desea obtener la información, y regresa el contenido del vector en esa posición. La precondición es que la posición sea un valor existente dentro de los datos
template <class T>
T ListaTemplate<T>::getData(int indice)
{
  if (0 <= indice && indice < currentSize)
  {
    std::cout << data[indice] << std::endl;
  }
  else
  {
    std::cout << "No hay nada" << std::endl;
  }
}

//  Regresa el valor del atributo size.
template <class T>
int ListaTemplate<T>::getSize()
{
  return currentSize;
}

// Imprime la lista de datos, uno por línea
template <class T>
void ListaTemplate<T>::print()
{
  for (int indice = 0; indice < currentSize; indice++)
  {
    std::cout << indice << " - " << data[indice] << std::endl;
  }
}

#endif // _LISTA_H_