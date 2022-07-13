# Árboles de búsqueda BST

Estructura de datos jerárquica.  
Relación entre elementos es de uno a muchos.  
**Nodo**: Cada elemento en un árbol (campo de información).  

**Nodo Raíz**: Primer elemento agregado al árbol, de donde derivan los demás nodos.  
Se usan los términos padre, hijo y hermanos para describir la relación entre los nodos.  
**Nodo Hoja**: Los nodos que ya no tienen descendientes.  
**Subárbol**: Todos los nodos descendientes por la izquierda o derecha de un nodo.  
**Altura y niveles** El conteo de niveles comienza en nivel 0. La altura del árbol se define por el número de niveles.  

**Árbol binario de búsqueda**  
Permite almacenar información ordenada.  
Reglas que debe cumplir:  
- Cada nodo puede tener 0, 1 o 2 hijos.  
- Los descencientes **izquierdos** deben tener un valor **menor** a su nodo padre.
- Los descencientes **derechos** deben tener un valor **mayor** a su nodo padre.

### Pasos para eliminar un nodo
***Eliminar un Nodo hoja***  
1. Buscar el Nodo Padre del nodo a borrar.
2. Desconectar el nodo.  
3. Librerar el nodo.  

***Eliminar un Nodo con un hijo***  
1. Buscar el Nodo Padre del nodo a borrar.
2. Conectar el hijo del nodo a borrar con el padre de este.  
3. Librerar el nodo.  

***Eliminar un Nodo con dos hijos***  
1. Localizar el nodo predecesor o sucesor del nodo a borrar.
- El *predecesor* es el Mayor de los Menores.
- El *sucesor* es el Menor de los Mayores.
2. El valor del Predecesor (o sucesor) se copia al nodo a borrar.  
3. Eliminar el nodo del predecesor (o sucesor, según el caso).  