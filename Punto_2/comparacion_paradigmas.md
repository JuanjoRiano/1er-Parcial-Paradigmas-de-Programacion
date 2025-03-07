# Análisis comparativo: Programación imperativa vs programación declarativa/funcional

## Comparación de claridad y legibilidad del código

### Python (imperativa)
El código es fácil de entender para una persona relacionada con los algoritmos de ordenamiento en programación imperativa, sin embargo, el hecho de que haya bucles anidados y una extensa condición en el if-statement hace que el código reduzca su legibilidad a simple vista.

### Haskell (declarativa/funcional)
Si bien en Haskell el código es más claro y legible, su entendimiento puede ser algo difícil para una persona que no esté relacionada con las funciones de orden superior, como `sortBy` y `comparing`.

## Nivel de expresividad y abstracción

### Python (imperativa)
La programación imperativa tiene un nivel de expresividad y abstracción bajo debido a la necesidad de especificar el comportamiento del programa en cada línea de código, además, hace que sea propenso a errores por parte del programador.

### Haskell (declarativa/funcional)
La programación declarativa/funcional tiene un alto nivel de expresividad y abstracción debido a que no hay que detallar cómo hacer cierto cómputo sino simplemente expresar qué se desea hacer. Esto permite solucionar un problema con menos código que otros paradigmas.

## Manejo de estructuras de datos (mutabilidad vs inmutabilidad)

### Python (imperativa)
El código en Python permite mutar de manera directa la lista a medida que se ejecuta la variante del algoritmo de Bubble Sort. Esto puede llevar a errores en otras partes del programa en los que se comparta la lista.

### Haskell (declarativa/funcional)
El código en Haskell no permite mutar las listas, pues estas son inmutables. `sortBy` devuelve la lista ordenada con las condiciones que uno le pasa, pero sin modificar la lista original, haciendo que el código sea más seguro.

## Manejo de estado en cada paradigma

### Python (imperativa)
Esta implementación cambia el estado a través de modificaciones de la lista dentro de los bucles anidados.

### Haskell (declarativa/funcional)
Las listas, al ser inmutables, no permiten un cambio directo de estado. En lugar de eso, se crea una lista nueva ordenada con las condiciones establecidas.

## Facilidad de mantenimiento y extensión de cada enfoque

### Python (imperativa)
Puede ser más complicado el mantenimiento y la extensión en este paradigma, ya que cada cambio puede afectar múltiples líneas y requerir pruebas adicionales para confirmar que el programa sigue produciendo la salida esperada.

### Haskell (declarativa/funcional)
Debido a que este paradigma usa funciones en vez de especificar instrucción por instrucción cómo debe hacer el programa cierto proceso, es más fácil el mantenimiento y la extensión, ya que cada función es independiente y más predecible.

## Eficiencia de cada solución, considerando el algoritmo y el lenguaje utilizado

### Python (imperativa)
El algoritmo usado en este paradigma es BubbleSort, el cual tiene una complejidad algorítmica de \(O(n^2)\), lo que es ineficiente para altas cantidades de datos. Además, Python es un lenguaje interpretado, lo que lo hace menos eficiente.

### Haskell (declarativa/funcional)
La función `sortBy` se implementa con algoritmos más eficientes que el BubbleSort, por ejemplo, el QuickSort, el cual tiene una complejidad algorítmica de \(O(n \log n)\), siendo eficiente para altas cantidades de datos. Además, Haskell es un lenguaje compilado, lo que aumenta su eficiencia de manera notable.
