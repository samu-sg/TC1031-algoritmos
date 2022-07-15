#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <sstream>

#include "Registro.h"

class Bitacora {
private:
  // vector de objetos Registro (cada celda es un renglon de bitacora.txt)
  std::vector<Registro> listaRegistros;

public:
  Bitacora();
  ~Bitacora();
  void lecturaDatos(std::string fileName);
  void swapsort();
  int busquedaBinaria(Registro);
  void print(int, int);
};

#endif // _BITACORA_H_