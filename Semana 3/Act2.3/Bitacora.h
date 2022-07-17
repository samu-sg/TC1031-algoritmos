#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <sstream>

#include "Registro.h"
#include "DoubleLinkedList.h"

class Bitacora {
private:
  // Lista de objetos Registro (cada celda es un renglon de bitacora.txt)
  DoubleLinkedList<Registro> listaRegistros;

public:
  Bitacora();
  ~Bitacora();
  void lecturaDatos(std::string fileName);
  void sort();
  void escribeBitacora(std::string filename);
  int busquedaBinaria(Registro);
  void print(int, int);
  void nuevoRegistro(std::string filename, int, int);
};

#endif // _BITACORA_H_