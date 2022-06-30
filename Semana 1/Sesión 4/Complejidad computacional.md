30/Junio/2022
# Complejidad computacional y clases de problemas
## Problemas de decisión
La teoría de complejidad se basa en la definición de clases que agrupan los problemas de acuerdo con la complejidad de los algoritmos que permiten resolverlos.  
La respuesta será "Sí" o "No"

## Algoritmo en tiempo polinómico
Algoritmo corre en tiempo polinómico si su complejidad en el peor caso está acotada por arriba por una función polinómica respecto al tamaño n de su entrada para alguna k positiva

Ejemplos  
- Ordenamiento de burbuja (bubble sort), O(n^2)
- Ordenamiento por fusión
- Ordenamiento por intercambio
- Multiplicación de matrices
- Unicidad de elementos
- Cálculo factorial

## Teoría de la complejidad computacional
**Clase P (Polynomial time)**  
Clase de problemas de decisión que se pueden resolver en una máquina de Turing determinista en tiempo polinómico.  
Son problemas para los que se han encontrado algoritmos eficientes con complejidad polinomial para resolverlos
- Son fáciles de resolver
- Sus soluciones son fáciles de verificar 

**Clase NP (Non-deterministic Polynomial time)**  
Problemas de decisión que se pueden resolver en una máquina de TUring no determinista en tiempo polinómico
- Pueden ser o no ser fáciles de resolver
- Es fácil verificar sus soluciones

## Reducción polinómica
Algoritmo determinista. Es una manera de relacionar dos problemas de decisión, de manera que la existencia de un algoritmo que resuelve el primer problema, grantiza la existencia de un algoritmo que resuelve el segundo, a través de un tiempo polinómico 

