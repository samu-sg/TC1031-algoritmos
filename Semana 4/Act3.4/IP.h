#ifndef IP_H
#define IP_H

#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Registro.h"
#include "MaxHeap.h"

class IP{
  private:
    int repeticiones;
    std::string ip;
  public:
    IP();
    IP(int reps, std::string IP);
    int getRep();
    std::string getIP();
    std::string getData();
};

#endif//IP_H