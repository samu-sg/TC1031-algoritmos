
#include "Bitacora.h"

Bitacora::Bitacora() {
}

Bitacora::~Bitacora() {
  listaRegistros.clear();
}

void Bitacora::lecturaDatos(std::string fileName) {
  std::string month, day, hour, minute, second, ipAdd, port, message;
  std::ifstream inputFile(fileName);
  if (!inputFile.good()) {
    inputFile.close();
    throw std::invalid_argument("File not found");
  }
  else {
    while (!inputFile.eof()) {
      // to-do validar que la longitud de month sea mayor a cero
      std::getline(inputFile, month, ' ');
      std::getline(inputFile, day, ' ');
      std::getline(inputFile, hour, ':');
      std::getline(inputFile, minute, ':');
      std::getline(inputFile, second, ' ');
      std::getline(inputFile, ipAdd, ':');
      std::getline(inputFile, port, ' ');
      std::getline(inputFile, message);
      // crear un objeto de la clase Registro
      Registro tmpReg(month, day, hour, minute, second, ipAdd, port, message);
      // agragar el objeto al vector
      listaRegistros.push_back(tmpReg);
    }
    inputFile.close();
  }
}

void Bitacora::write(std::string fileName){
  std::ofstream archivo;
  archivo.open(fileName);
  for (int i = 0; i < listaRegistros.size(); i++){
    std::string all = listaRegistros[i].getAll();
    archivo << all <<std::endl;
  }
  archivo.close();
}

void Bitacora::maxheapify(int x, int y){
  int grnd = y;
  int left = 2 * y + 1;
  int right = 2 * y + 2;
  if (left < x && listaRegistros[left] > listaRegistros[grnd])
    grnd = left;
  if (right < x && listaRegistros[right] > listaRegistros[grnd])
    grnd = right;
  if (grnd != y){
    std::swap(listaRegistros[y], listaRegistros[grnd]);
    maxheapify(x, grnd);
  }
}

void Bitacora::heapSort(){
  int num = listaRegistros.size();
  for (int i = num / 2 - 1; i >= 0; i--){
    maxheapify(num, i);
  }
  for (int j = num - 1; j > 0; j--){
    std::swap(listaRegistros[0], listaRegistros[j]);
    maxheapify(j, 0);
  }
}

int Bitacora::reps(std::string ip){
  int index = 0;
  for (int i = 0; i <= listaRegistros.size(); i++){
    if (ip == listaRegistros[i].getIP()){
      index++;
    }
  }
  return index;
}

void Bitacora::sort(){
  heapSort();
  for (int i = 0; i <= listaRegistros.size(); i++){
    std::string ipr = listaRegistros[i].getIP();
    int repet = reps(ipr);
    IP ip(repet, ipr);
    if (listaRegistros[i].getIPN() != listaRegistros[i+1].getIPN()){
      maxheap.push(ip);
    }
  }
}

void Bitacora::LosRepetidos(std::string fileName){
  std::string ip;
  int x;
  std::ofstream archivo;
  archivo.open(fileName);
  for (int i = 0; i <= 4; i++){
    ip = maxheap.top().getIP();
    x = maxheap.top().getRep();
    std::cout << ip << " las veces que se repitio esta ip fueron: " << x << std::endl;
    std::string h = ip;
    archivo << h << " las veces que se repitio esta ip fueron: " << x << std::endl;
    maxheap.pop();
  }
  archivo.close();
  
}