# Informe comparativo: Factorial Iterativo vs Recursivo

---

## Introducción

A partir de este informe se muestran los resultados obtenidos del cálculo de un numero n **factorial** en su version **iterativa** y **recursiva**, estas hechas en el lenguaje **C**

---

## Datos a medir

- Tiempo de ejecución de numeros n (1000, 900, 800, 700, 600, 500)

## Resultados

| **Valor de n** | **Tiempo iterativo (s)** | **Tiempo Recursivo** |
| -------------- | ------------------------ | -------------------- |
| 1000           | 2,607                    | 2,419                |
| 950            | 1,019                    | 0,982                |
| 900            | 3,485                    | 1,42                 |
| 850            | 1,844                    | 0,996                |
| 800            | 1,799                    | 1,709                |
| 750            | 1,654                    | 1,153                |
| 700            | 1,375                    | 1,112                |
| 650            | 1,073                    | 1,176                |
| 600            | 1,369                    | 0,906                |
| 550            | 1,228                    | 0,836                |
| 500            | 1,075                    | 1,047                |

---

## Conclusiones

- Se concluye una mayor eficiencia en el programa recursivo, a pesar de que en algunos casos la diferencia es casi nula
- Sin embargo la recursividad aumenta el uso de la memoria, pero permitiendo el alcance de numeros mas grandes
