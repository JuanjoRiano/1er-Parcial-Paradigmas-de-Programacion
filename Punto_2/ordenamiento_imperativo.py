def bubble_sort_descending(estudiantes):
    n = len(estudiantes)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if (estudiantes[j][1] < estudiantes[j + 1][1]) or (estudiantes[j][1] == estudiantes[j + 1][1] and estudiantes[j][0] > estudiantes[j + 1][0]):
                estudiantes[j], estudiantes[j + 1] = estudiantes[j + 1], estudiantes[j]
    return estudiantes

estudiantes = [
    ("Ana", 85),
    ("Luis", 90),
    ("Carlos", 85),
    ("Sofía", 92),
    ("María", 90)
]

print(bubble_sort_descending(estudiantes))
