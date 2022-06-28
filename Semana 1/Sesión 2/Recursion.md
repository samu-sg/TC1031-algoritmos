28/Junio/2022

# Recursividad
Técnica para diseño de algoritmos para resolver problemas.  
Reducir el tamaño del problema que queremos resolver hasta llegar a una versión que ya no se puede subdividir más.  

## Definiciones recursivas
__Explica un concepto en términos de versiones más pequeñas de él mismo__   
Ej. Folders, oraciones compuestas, factoriales.

## Algoritmos recursivos
Es un método de solución que se expresa en términos de:
- instancias más pequeñas de él mismo
- tiene un caso base

### Caso base
El caso para el cual la solución puede ser expresada sin recursión
### Caso general(recursivo)
El caso en el que la solución se expresa en términos de versiones más pequeñas de él mismo

## Llamada a una subrutina
- Cargar en memoria el código de subrutina llamada en el segmento de código  
- El registro de activación contiene información sobre constantes, variables locales y parámetros que se pasan a la subrutina.  
- Cada vez que se llama a una subrutina se almacena el registro de activación de la subrutina en la pila de llamadas a subrutinas (stack).  
- Cuando la subrutina termina, su registro de activación se desapila
