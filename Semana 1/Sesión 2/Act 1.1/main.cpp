// Samuel Sánchez García A00831772

#include <iostream>

// Calcula la sumatoria de 1 hasta n con un método iterativo
int sumaIterativa(int n) {
    int acumulador = 0;
    for (int i = 0; i <= n; i++) {
        acumulador = acumulador + i;
    }
    return acumulador;
}

// Calcula la sumatoria de 1 hasta n con un método recursivo
int sumaRecursiva(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumaRecursiva(n - 1);
}

unsigned int sumConst(unsigned int n) {
    unsigned int res = (n * (n + 1)) / 2;
    return res;
}

// Calcula el n-ésimo número de la serie de Fibonacci usando un método iterativo
char fibonacciIterativo(int n) {
    unsigned long int fibonacci = 0, aux = 1;
    for (int i = 0; i < n; i++) {
        aux = aux + fibonacci;
        fibonacci = aux - fibonacci;
        std::cout << fibonacci << ' ';
    }
    return ' ';
}

// Calcula el n-ésimo número de la serie de Fibonacci usando un método recursivo
int fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);

    for (int i = 1; i <= n; i++)
    {
        std::cout << ' ' << fibonacciRecursivo(i);
    }
}

int main() {
    /*std::cout << "sumConst(8): " << sumConst(8) << std::endl;
    std::cout << "sumaRecursiva(8): " << sumaRecursiva(8) << std::endl;
    std::cout << "sumaIterativa(8): " << sumaIterativa(8) << std::endl;*/
    std::cout << "fibonaccionacciIterativo(8) " << fibonacciIterativo(8) << std::endl;
    //std::cout << "fibonaccionacciRecursivo(8) " << fibonacciRecursivo(8) << std::endl;
    std::cout << "fibonaccionacciRecursivo(8)" << fibonacciRecursivo(8) << std::endl;
    /*for (int i = 1; i <= 8; i++)
    {
        std::cout << ' ' << fibonacciRecursivo(i);
    }*/
    
}