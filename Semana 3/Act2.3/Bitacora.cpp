#include <iostream>
#include "Bitacora.h"

Bitacora::Bitacora() {
}

Bitacora::~Bitacora() {
}

// Complejidad O(n)
void Bitacora::lecturaDatos(std::string fileName) {
  std::string month, day, hour, minute, second, ipAdd, port, message;
  std::ifstream inputFile(fileName);
  if (!inputFile.good()) {
    inputFile.close();
    throw std::invalid_argument("File not found");
  }
  else {
    while (!inputFile.eof()) {
      // to-do validar que la longitud de month sea mayor a cero
      std::getline(inputFile, month, ' ');
      std::getline(inputFile, day, ' ');
      std::getline(inputFile, hour, ':');
      std::getline(inputFile, minute, ':');
      std::getline(inputFile, second, ' ');
      std::getline(inputFile, ipAdd, ':');
      std::getline(inputFile, port, ' ');
      std::getline(inputFile, message);
      // crear un objeto de la clase Registro
      Registro tmpReg(month, day, hour, minute, second, ipAdd, port, message);
      // agregar el objeto
      listaRegistros.addLast(tmpReg);
    }
    inputFile.close();
  }
}

// Complejidad O(n)
void Bitacora::print(int pos1, int pos2) {
  for (int i = pos1; i <= pos2; i++) {
      std::cout << listaRegistros.getData(i).getAll() << std::endl;
  }
}

void Bitacora::nuevoRegistro(std::string filename, int pos1 , int pos2) {
  std::ofstream file;
  file.open(filename);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  }
  else {
    for (int i = pos1; i <= pos2; i++) {
      file << listaRegistros.getData(i).getAll() << std::endl;
    }
    file.close();
  }
}

// Complejidad O(n)
void Bitacora::sort() {
  listaRegistros.sort();
}

void Bitacora::Escritura(std::string filename) {
  std::ofstream file;
  file.open(filename);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  }
  else {
    DLLNode<Registro> *h = listaRegistros.getHead();
    DLLNode<Registro> *t = listaRegistros.getTail();
    DLLNode<Registro> *ptr = h;
    while (ptr != nullptr) {
      file << ptr->data.getAll() << std::endl;
      ptr = ptr->next;
    }
    file.close();
  }
}

// Complejidad caso promedio O(log n)
int Bitacora::busquedaBinaria(Registro key) {
  int low = 0;
  int high = listaRegistros.getNumElements()-1;
  int mid = 0;
  while (low <= high) {
    mid = low + (high-low)/2;
    if (key == listaRegistros.getData(mid)) return mid;
    else if (key < listaRegistros.getData(mid)) high = mid - 1;
    else low = mid + 1;
  } 
  return -1;
}