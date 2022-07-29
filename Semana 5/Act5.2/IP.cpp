#include "IP.h"

IP::IP() {
  ip = "";
  //IPport = "";
  ipIndex = 0;
  IPValue = 0;
  degree = 0;
  degreeIn = 0;
}

IP::IP(std::string ip, int ipIndex){
  this->ip = ip;
  //this->IPport = IPport;
  this->ipIndex = ipIndex;
  degree = 0;
  degreeIn = 0;
  //IP
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
  int a = std::stoi(resultados[0]);
  int b = std::stoi(resultados[1]);
  int c = std::stoi(resultados[2]);
  int d = std::stoi(resultados[3]);
  IPValue = a*(pow(256,3)) + b*(pow(256,2)) + c*(pow(256,1)) + d*(pow(256,0));
}

std::string IP::getIp(){
  return ip;
}

unsigned int IP::getIPValue(){
  return IPValue;
}

int IP::getIpIndex(){
  return ipIndex;
}

int IP::getDegreeOut(){
  return degree;
}

void IP::addDegreeOut() {
  degree++;
}

int IP::getDegreeIn() {
  return degreeIn;
}

void IP::addDegreeIn() {
  degreeIn++;
}

std::string IP::getData() {
  return ip + std::to_string(degree);
}

bool IP::operator==(const IP &other) {
  return this->IPValue == other.IPValue;
}

bool IP::operator!=(const IP &other) {
  return this->IPValue != other.IPValue;
}

bool IP::operator>(const IP &other) {
  return this->IPValue > other.IPValue;
}

bool IP::operator<(const IP &other) {
  return this->IPValue < other.IPValue;
}

bool IP::operator>=(const IP &other) {
  return this->IPValue >= other.IPValue;
}

bool IP::operator<=(const IP &other) {
  return this->IPValue <= other.IPValue;
}