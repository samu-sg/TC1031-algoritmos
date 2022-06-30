29/Junio/2022
# Análisis de algoritmos parte 2
## Orden de crecimiento asintótico
**BigO**  
Acota por arriba, la función a comparar debe caer bajo cg(n).  
**BigTheta**  
La función cae entre c1g(n) y c2g(n), g(n) es la misma función multiplicada por dos diferentes constantes.  
**BigOmega**  
Acota por abajo, la función se encuentra por arriba de cg(n).

------ ***Clases básicas de eficiencia asintótica*** ------  
![2022-06-29 (1)](https://user-images.githubusercontent.com/69923215/176575119-0c5b9608-0f07-4888-b7f7-4fcc142dc89b.png)

## Análisis empírico de la eficiencia temporal
Se aplican reglas a los estatutos estructurados de un programa:  

**Secuencia de instrucciones**   
Si queremos analizar un bloque de líneas, evaluamos la complejidad de cada una de ellas, y la complejidad mayor que encontremos en las lineas determina la complejidad de todo el bloque.

**Decisiones**  
Evaluar la complejidad de cada rama de la condicional para encontrar la mayor complejidad, que va a determinar al complejidad de todo el bloque.

**Ciclos**  
Si el ciclo se repite m veces, la complejidad total es la complejidad máxima del bloque multiplicada por m.  
En decisiones y ciclos anidados, se analiza el código desde la instrucción más interna hacia la más externa.

**Recursividad**  
Al analizar la complejidad de un algoritmo recursivo observamos la cantidad de llamadas recursivas que realiza y el comportamiento del parámetro de control de la función.  
- O(n), 1 sola llamada, el parámetro de control decrementa o incrementa en valor constante.  
- O(log_b n), 1 sola llamada recursiva, el parámetro de control se divide o multiplica por un valor constante b.  
- O(c^n) hay c llamadas recursivas cada vez y el parámtro de control decrementa o incrementa en un valor constante.  
- O(n^log_b c), hay llamadas recursivas cada vez y el parámetro de control se divide o multiplica por un valor constante b.  
