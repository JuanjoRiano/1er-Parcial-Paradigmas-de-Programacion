# Función para ordenar una lista de estudiantes en orden descendente por calificación
# En caso de empate, los ordena por nombre en orden ascendente
def bubble_sort_descending(estudiantes):
    n = len(estudiantes)  # Obtener la cantidad de estudiantes
    for i in range(n - 1):  # Iterar a través de la lista
        for j in range(n - 1 - i):  # Recorrer la lista hasta el último elemento no ordenado
            # Comparar calificaciones en orden descendente
            # Si las calificaciones son iguales, ordenar por nombre en orden ascendente
            if (estudiantes[j][1] < estudiantes[j + 1][1]) or \
               (estudiantes[j][1] == estudiantes[j + 1][1] and estudiantes[j][0] > estudiantes[j + 1][0]):
                # Intercambiar los elementos si están en el orden incorrecto
                estudiantes[j], estudiantes[j + 1] = estudiantes[j + 1], estudiantes[j]
    return estudiantes  # Devolver la lista ordenada

# Lista de estudiantes con sus calificaciones
estudiantes = [
    ("Ana", 85),
    ("Luis", 90),
    ("Carlos", 85),
    ("Sofía", 92),
    ("María", 90)
]

# Llamamos a la función y mostramos el resultado
print(bubble_sort_descending(estudiantes))
