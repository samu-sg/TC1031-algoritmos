#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <iostream>

class Registro {
  private:
    std::string mes;
    std::string dia;
    std::string hora;
    std::string min;
    std::string seg;
    std::string ip;
    std::string puerto;
    std::string msg;
    int a, b, c, d;
    unsigned int IPV;
    // usado para transformar fecha completa a segundos desde 1970
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // Struct que contiene todos los datos de la fecha-hora
    struct tm dateStruct;
    // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
    time_t date;
  
  public:
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string min, std::string seg, std::string ip, std::string puerto, std::string msg);
    std::string getAll();
    std::string getIP();
    unsigned int getIPN();
    
    // sobre carga de operadores de comparacion
    // Comapara dos objetos de la clase Registro usando
    // fecha convertida a segundos (date)
    bool operator ==(const Registro&) const;
    bool operator !=(const Registro&) const;
    bool operator >(const Registro&) const;
    bool operator <(const Registro&) const;
    bool operator >=(const Registro&) const;
    bool operator <=(const Registro&) const;
};

#endif //_REGISTRO_H_