#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Registro.h"
#include "MaxHeap.h"
#include "IP.h"

class Bitacora {
  private:
    // vector de objetos Registro (cada celda es un renglon de bitacora.txt)
    std::vector<Registro> listaRegistros;
    MaxHeap<IP> maxheap;

  public:
    Bitacora();
    ~Bitacora();
    void lecturaDatos(std::string fileName);
    void maxheapify(int x, int y);
    void heapSort();
    void sort();
    int reps(std::string ip);
    void write(std::string fileName);
    void LosRepetidos(std::string fileName);

};

#endif // _BITACORA_H_