04/Julio/2022

# Algoritmos de ordenamiento

## Ordenamiento por selección (selection sort)
Consiste en encontrar el menor de todos los elementos del vector e intercambiarlo con el que está en la primera posición. Luego el segundo más pequeño, y así sucesivamente hasta ordenarlo completamente.  
En este proceso de ordenamiento **el número de comparaciones no varía de acuerdo a lo ordenado que se encuentre el vector, sino que se mantiene constante acorde al número de elementos en el vector** (siempre tiene que revisar todos los elementos del mismo).  
- Por esta razón, tiene una complejidad **O(n^2)** en todos los casos.

## Ordenamiento de burbuja (bubble sort)
Este proceso compara repetidamente los elementos adyacentes en un vector y su intercambio si están en un orden incorrecto. Las comparaciones repetidas hacen que el elemento más grande se desplace hacia el final del array, por lo que este algoritmo recibe el nombre de ordenación burbuja.  
- En el mejor caso, donde el vector está ordenado, tendría una complejidad **O(n)** porque haría las comparaciones pero no ocurriría ningún intercambio.
- En el peor caso, donde ningún elemento está ordenado, tendrá una complejidad **O(n^2)** porque alcanzaremos el máximo número de comparaciones e intercambios posibles (en el código entra a ambos ciclos).

## Ordenamiento por inserción (insertion sort)
Su funcionamiento consiste en el recorrido por la lista seleccionando en cada iteración un valor como clave y compararlo con el resto insertándolo en el lugar correspondiente.  
- En el mejor caso, si el vector ya está ordenado, tendría una complejidad **O(n)** porque haría las comparaciones pero no ocurriría ningún intercambio.
- En el peor caso, tendrá una complejidad **O(n^2)** porque alcanzaremos el máximo número de comparaciones e intercambios posibles.

## Complejidad temporal