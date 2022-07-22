#include "IP.h"

IP::IP(){
  repeticiones = 0;
  ip = "";
}

IP::IP(int reps, std::string IP){
  repeticiones = reps;
  ip = IP;
}

int IP::getRep(){
  return repeticiones;
}

std::string IP::getIP(){
  return ip;
}

std::string IP::getData(){
  return ip + " las repetiones de este ip fueron: " + std::to_string(repeticiones);
}