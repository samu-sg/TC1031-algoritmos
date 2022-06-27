# Abstracción de datos

### Abstracción
Proceso mental que extra rasgos esenciales de algo para representarlos mediante un lenguaje gráfico o escrito.  
Durante el diseño de la estructura se ignoran detalles de la implementación.  

## Tipo de datos abstractos (ADT)
Tipo de dato en que solo se definen los rasgos esenciales, sin entrar en detalles de implementación.  
Se realiza por medio de una especificación lógica.

### Se debe mencionar lo siguiente:
#### Elementos  
Escribir el tipo de dato de los elementos que almacenará la estructura  
Ej. fechas, cadenas, datos de un curso.  
#### Tipo de organización  
Como se va a relacionar la información del ADT  
- Lineal: relación uno a uno  
- Jerarquica: relación uno a muchos  
- Red: relación muchos a muchos  
- Sin relación  
#### Dominio  
Escribir el rango de posibles valores que pueden almacenarse dentro de la estructura.  
#### Operaciones  
Se debe especificar lo siguiente:  
- Nombre de la operación
- Descripción de su utilidad
- Datos de entrada a la operación
- Datos que se generan como salida
- Precondiciones: condición que debe de cumplirse antes de ejecutar la operación, para que funcione correctamente
- Postcondiciones: descripción del estado en el que queda el ADT después de ejecutar la operación

## Niveles de abstracción  
- Lógico o abstracto: se diseña el ADT por medio de la especificación lógica.
- Físico o de implementacicón: se impolementan cada una de las operaciones del ADT.
- Aplicación o de uso: se implementan programas en los que se utiliza la estructura de datos (ADT).

## Tipos de datos
- Primitivos o escalares: tienen un único valor
- Compuestos (Aggregates): colección de elementos
- Homogéneos (ej. arreglos)
- Heterogéneos (ej. clase)
- Combinado (ej. un arreglo de objetos)

## Características de los Arreglos
- Contenen datos homogéneos
- Se puede acceder a los elementos de forma directa
- Se definen con un tamaño fijo, ya no podemos agregar elementos
- Si no se utiliza por completo, se desperdicia espacio en la memoria
- Para intercalar un elemento se deben mover todos los demás
