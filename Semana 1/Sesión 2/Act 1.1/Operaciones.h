#ifndef _OPERACIONES_H_
#define _OPERACIONES_H_

#include <iostream>

class Operaciones {
  public:
    // Métodos de suma
    int sumaIterativa(int n);
    int sumaRecursiva(int n);

    // Métodos de Fibonacci
    void fibonacciIterativo(int n);
    int fibonacciRecursivo(int n);
};

// Calcula la sumatoria de 1 hasta n con un método iterativo con complejidad O(n).
int Operaciones::sumaIterativa(int n) {
    int acumulador = 0;
    for (int i = 0; i <= n; i++) {
        acumulador = acumulador + i;
    }
    return acumulador;
}

// Calcula la sumatoria de 1 hasta n con un método recursivo con complejidad de O(n). 
int Operaciones::sumaRecursiva(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumaRecursiva(n - 1);
}

// Calcula el n-ésimo número de la serie de Fibonacci usando un método iterativo con complejidad O(n).
void Operaciones::fibonacciIterativo(int n) {
    unsigned long int fibonacci = 0, aux = 1;
    std::cout << "fibonacciIterativo(" << n << "): ";
    for (int i = 0; i < n; i++) {
        aux = aux + fibonacci;
        fibonacci = aux - fibonacci;
        std::cout << fibonacci << ' ';
      if (i == n-1) {
        std::cout << "\n";
      }
    }
}

// Calcula el n-ésimo número de la serie de Fibonacci usando un método recursivo con complejidad O(2^n).
int Operaciones::fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
  else
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

#endif // _OPERACIONES_H_