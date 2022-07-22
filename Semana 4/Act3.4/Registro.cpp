#include "Registro.h"

Registro::Registro() {
  mes = "";
  dia = "";
  hora = "";
  min = "";
  seg = "";
  ip = "";
  puerto = "";
  msg = "";
}

Registro::Registro(std::string mes, std::string dia, std::string hora, std::string min, std::string seg, std::string ip, std::string puerto, std::string msg) {
  this->mes = mes;
  this->dia = dia;
  this->hora = hora;
  this->min = min;
  this->seg = seg;
  this->ip = ip;  
  this->puerto = puerto;
  this->msg = msg;
  // tranforma fecha completa a segundos desde 1970
  // Almacenar los campos de la fecha-hora en el struct tm
  dateStruct.tm_sec = std::stoi(seg);
  dateStruct.tm_min = std::stoi(min);
  dateStruct.tm_hour = std::stoi(hora);
  dateStruct.tm_mday = std::stoi(dia);
  // Agregado para resolver problema de compatibilidad en Windows
  dateStruct.tm_isdst = 0;
  for (int i=0; i < meses.size(); i++) {
    if (meses[i] == mes)
      dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2022 - 1900;  // Asumimos el año 2022
  // Obtener el Unix timestamp a partir del struct tm anterior 
  date = mktime(&dateStruct);

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
  a = std::stoi(resultados[0]);
  b = std::stoi(resultados[1]);
  c = std::stoi(resultados[2]);
  d = std::stoi(resultados[3]);
  IPV = a*(pow(256,3)) + b*(pow(256,2)) + c*(pow(256,1)) + d*(pow(256,0));
}

unsigned int Registro::getIPN(){
  return IPV;
}

std::string Registro::getIP(){
  return ip;
}

std::string Registro::getAll() {
  return mes + " " + dia + " " + hora + ":" + min + ":" + seg + " " + ip + ":" + puerto + " " + msg;
}

bool Registro::operator==(const Registro &other) const {
  return this->IPV == other.IPV;
}

bool Registro::operator!=(const Registro &other) const {
  return this->IPV != other.IPV;
}

bool Registro::operator>(const Registro &other) const {
  return this->IPV > other.IPV;
}

bool Registro::operator<(const Registro &other) const {
  return this->IPV < other.IPV;
}

bool Registro::operator<=(const Registro &other) const {
  return this->IPV <= other.IPV;
}

bool Registro::operator>=(const Registro &other) const {
  return this->IPV >= other.IPV;
}