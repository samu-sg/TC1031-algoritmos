#ifndef IP_H
#define IP_H

#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include "MaxHeap.h"

class IP {
  private:
    std::string ip;
    int ipIndex;
    int degree;
    unsigned int IPValue;
    int a, b, c, d;
  
  public:
    IP();
    IP(std::string ip);
    std::string getIP();
    int getIpIndex();
    int getDegree();
    unsigned int getIPValue();
    
    // sobre carga de operadores de comparacion
    bool operator ==(const IP&) const;
    bool operator !=(const IP&) const;
    bool operator >(const IP&) const;
    bool operator <(const IP&) const;
    bool operator >=(const IP&) const;
    bool operator <=(const IP&) const;
};

/*
  private:
    int repeticiones;
    std::string ip;
  public:
    IP();
    IP(int reps, std::string IP);
    int getRep();
    std::string getIP();
    std::string getData();
*/

#endif//IP_H