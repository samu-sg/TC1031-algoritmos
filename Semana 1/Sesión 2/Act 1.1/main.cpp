// Johan Cabrera Peña A01635713
// Samuel Sánchez García A00831772
// Erika Alejandra Colín Tapia A01706555
// Fecha de creación: 28/06/2022
// Última modificación: 30/06/2022

#include <iostream>
#include "Operaciones.h"

int main() {
  Operaciones num;

  // Métodos de suma
  std::cout << "sumaIterativa(20): " << num.sumaIterativa(20) << std::endl;
  std::cout << "sumaRecursiva(20): " << num.sumaRecursiva(20) << std::endl;
  std::cout << "sumaIterativa(50): " << num.sumaIterativa(50) << std::endl;
  std::cout << "sumaRecursiva(50): " << num.sumaRecursiva(50) << std::endl;
  std::cout << "sumaIterativa(100): " << num.sumaIterativa(100) << std::endl;
  std::cout << "sumaRecursiva(100): " << num.sumaRecursiva(100) << std::endl;
  std::cout << "sumaIterativa(1000): " << num.sumaIterativa(1000) << std::endl;
  std::cout << "sumaRecursiva(1000): " << num.sumaRecursiva(1000) << std::endl; 

  std::cout << "\n";
  
  // Métodos de Fibonacci
  num.fibonacciIterativo(5);
  std::cout << "fibonacciRecursivo(5): ";
  for (int i = 1; i <= 5; i++) {
        std::cout << num.fibonacciRecursivo(i) << ' ';
    }
  std::cout << "\n";
  
  num.fibonacciIterativo(10);
  std::cout << "fibonacciRecursivo(10): ";
  for (int i = 1; i <= 10; i++) {
        std::cout << num.fibonacciRecursivo(i) << ' ';
    }
  std::cout << "\n";
  
  num.fibonacciIterativo(15);
  std::cout << "fibonacciRecursivo(15): ";
  for (int i = 1; i <= 15; i++) {
        std::cout << num.fibonacciRecursivo(i) << ' ';
    }
  std::cout << "\n";
  
  num.fibonacciIterativo(30);
  std::cout << "fibonacciRecursivo(30): ";
  for (int i = 1; i <= 30; i++) {
        std::cout << num.fibonacciRecursivo(i) << ' ';
    }  
}