#include "IP.h"


IP::IP() {

}

IP::IP(std::string ip) {
  int inicio = 0;
  int fin = 0;
  std::string parte;
  std::vector<std::string> resultados;
  while (fin >= 0){
    fin = ip.find(".", inicio);
    parte = ip.substr(inicio, fin - inicio);
    inicio = fin + 1;
    resultados.push_back(parte);
  }
  a = std::stoi(resultados[0]);
  b = std::stoi(resultados[1]);
  c = std::stoi(resultados[2]);
  d = std::stoi(resultados[3]);
  IPValue = a*(pow(256,3)) + b*(pow(256,2)) + c*(pow(256,1)) + d*(pow(256,0));
}

unsigned int IP::getIPValue(){
  return IPValue;
}

std::string IP::getIP(){
  return ip;
}

bool IP::operator==(const IP &other) const {
  return this->IPValue == other.IPValue;
}

bool IP::operator!=(const IP &other) const {
  return this->IPValue != other.IPValue;
}

bool IP::operator>(const IP &other) const {
  return this->IPValue > other.IPValue;
}

bool IP::operator<(const IP &other) const {
  return this->IPValue < other.IPValue;
}

bool IP::operator<=(const IP &other) const {
  return this->IPValue <= other.IPValue;
}

bool IP::operator>=(const IP &other) const {
  return this->IPValue >= other.IPValue;
}

/*
IP::IP() {
  repeticiones = 0;
  ip = "";
}

IP::IP(int reps, std::string IP) {
  repeticiones = reps;
  ip = IP;
}

int IP::getRep() {
  return repeticiones;
}

std::string IP::getIP() {
  return ip;
}

std::string IP::getData() {
  return ip + " las repetiones de este ip fueron: " + std::to_string(repeticiones);
}
*/