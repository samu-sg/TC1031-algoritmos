27/Junio/2022  
# Plantillas para abstracción de algoritmos  
**Nos permiten definir una función que se ajusta al tipo de dato preferido**

## Plantillas para funciones
__Funciones que trabajan con un tipo de datos general.__  
 
Ejemplo:  
![2022-06-27 (2)](https://user-images.githubusercontent.com/69923215/176045065-c4b924ac-0509-4efa-b4aa-8607b94b8943.png)  
En lugar de escribir el nombre del tipo escribrimos un identificador.  
La primera línea indica que T será utilizada como un tipo general para la función. 
Se le conoce como prefijo de plantilla e indica que la definición siguiente es una plantilla
y que **T** es el **parámetro de tipo**.  
> El **parámetro de tipo** es un identificador que puede sustituirse por cualquier tipo de 
C++, que puede ser un tipo predefinido o uno definido por el programador, es decir, una clase

El compilador genera automáticamente, a partir de la plantilla, las funciones para cada 
tipo con el que se mande llamar la plantilla.

## Plantillas para clases
También podemos usar plantillas para clases: tener clases en donde alguno de sus datos miembro
es de un tipo genérico.

La clase y las funciones miembro deben ir precedidas por la línea:  
**"template <class parámetroDeTipo>"**

La definición de las funciones miembro normalmente llevan “nombreClase::”
en su encabezado, ahora esto se debe sustituir por:  
**"nombreClase<parámetroDeTipo>::"**

Y al declarar un objeto de la clase, se debe hacer con el siguiente formato:  
**"nombreClase<tipo_> nombreVariable"** donde tipo_ es el tipo que deseamos usar (ej. int,
double)
