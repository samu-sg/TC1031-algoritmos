#include <iostream>
#include "Bitacora.h"

Bitacora::Bitacora() {
  listaRegistros.resize(0);
}

Bitacora::~Bitacora() {
  listaRegistros.clear();
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
      // agregar el objeto al vector
      listaRegistros.push_back(tmpReg);
    }
    inputFile.close();
  }
}

// Complejidad O(n)
void Bitacora::print(int pos1, int pos2){
  for (int i = pos1; i <= pos2; i++) {
      std::cout<<listaRegistros[i].getAll()<<std::endl;
  }
}

// Complejidad O(n^2)
void Bitacora::swapsort() {
  for (int i = 0; i < listaRegistros.size(); i++) {
    for (int j = i+1; j < listaRegistros.size(); j++) {
      if (listaRegistros[i] > listaRegistros[j]) {
        std::swap(listaRegistros[i], listaRegistros[j]);
      }
    }
  }
}

// Complejidad caso promedio O(log n)
int Bitacora::busquedaBinaria(Registro key) {
  int low = 0;
  int high = listaRegistros.size()-1;
  int mid = 0;
  while (low <= high) {
    mid = low + (high-low)/2;
    if (key == listaRegistros[mid]) return mid;
    else if (key < listaRegistros[mid]) high = mid - 1;
    else low = mid + 1;
  } 
  return -1;
}