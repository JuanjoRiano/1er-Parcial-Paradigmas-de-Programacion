#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definición de una estructura sin optimización
// Usa punteros para almacenar cadenas dinámicamente, lo que puede aumentar el consumo de memoria
typedef struct {
    char *nombre;        // Puntero para almacenar el nombre dinámicamente
    char *apellido;      // Puntero para almacenar el apellido dinámicamente
    unsigned int edad;   // Variable entera sin optimización de bits
    char *ID;           // Puntero para almacenar el ID dinámicamente
    int *calificaciones; // Puntero a un arreglo dinámico de calificaciones
    size_t num_calificaciones; // Número de calificaciones almacenadas
} EstudianteSinOpt;

// Definición de una estructura optimizada
// Reduce el uso de memoria mediante técnicas como el uso de bit fields y almacenamiento estático de cadenas
typedef struct {
    char *nombre;        // Puntero para almacenar el nombre dinámicamente
    char *apellido;      // Puntero para almacenar el apellido dinámicamente
    unsigned int edad : 7; // Uso de un bit field para reducir el espacio ocupado por la edad
    char id[9];          // Almacenamiento fijo para el ID en un arreglo estático
    int *calificaciones; // Puntero a un arreglo dinámico de calificaciones
    size_t num_calificaciones; // Número de calificaciones almacenadas
} EstudianteOpt;

// Función para crear un estudiante sin optimización
EstudianteSinOpt *crear_estudiante_sin_opt(const char *nombre, const char *apellido, unsigned int edad, const char *ID, int *calificaciones, size_t num_calificaciones) {
    // Reserva memoria para la estructura
    EstudianteSinOpt *nuevo = (EstudianteSinOpt *)malloc(sizeof(EstudianteSinOpt));
    if (!nuevo) return NULL; // Verifica si la asignación de memoria fue exitosa

    // Asigna memoria y copia los valores de los parámetros a la estructura
    nuevo->nombre = strdup(nombre);
    nuevo->apellido = strdup(apellido);
    nuevo->ID = strdup(ID);
    nuevo->edad = edad;
    nuevo->calificaciones = (int *)malloc(num_calificaciones * sizeof(int));
    memcpy(nuevo->calificaciones, calificaciones, num_calificaciones * sizeof(int));
    nuevo->num_calificaciones = num_calificaciones;

    return nuevo; // Retorna el puntero a la estructura creada
}

// Función para liberar la memoria de un estudiante sin optimización
void liberar_estudiante_sin_opt(EstudianteSinOpt *estudiante) {
    if (estudiante) {
        // Calcula la cantidad de memoria liberada
        size_t memoria_liberada = sizeof(EstudianteSinOpt) + strlen(estudiante->nombre) + strlen(estudiante->apellido) + strlen(estudiante->ID) + estudiante->num_calificaciones * sizeof(int);
        printf("Estudiante con ID %s eliminado correctamente. Memoria liberada: %zu bytes.\n", estudiante->ID, memoria_liberada);
        
        // Libera la memoria asignada dinámicamente
        free(estudiante->nombre);
        free(estudiante->apellido);
        free(estudiante->ID);
        free(estudiante->calificaciones);
        free(estudiante);
    }
}

// Función para crear un estudiante optimizado
EstudianteOpt *crear_estudiante_opt(const char *nombre, const char *apellido, unsigned int edad, const char *id, int *calificaciones, size_t num_calificaciones) {
    // Reserva memoria para la estructura
    EstudianteOpt *nuevo = (EstudianteOpt *)malloc(sizeof(EstudianteOpt));
    if (!nuevo) return NULL; // Verifica si la asignación de memoria fue exitosa

    // Asigna memoria y copia valores a la estructura
    nuevo->nombre = strdup(nombre);
    nuevo->apellido = strdup(apellido);
    nuevo->edad = edad;
    strncpy(nuevo->id, id, 8); // Copia hasta 8 caracteres del ID para evitar desbordamiento
    nuevo->id[8] = '\0'; // Asegura que la cadena termine correctamente
    nuevo->calificaciones = (int *)malloc(num_calificaciones * sizeof(int));
    memcpy(nuevo->calificaciones, calificaciones, num_calificaciones * sizeof(int));
    nuevo->num_calificaciones = num_calificaciones;

    return nuevo;
}

// Función para liberar la memoria de un estudiante optimizado
void liberar_estudiante_opt(EstudianteOpt *estudiante) {
    if (estudiante) {
        // Calcula la memoria liberada
        size_t memoria_liberada = sizeof(EstudianteOpt) + strlen(estudiante->nombre) + strlen(estudiante->apellido) + estudiante->num_calificaciones * sizeof(int);
        printf("Estudiante con ID %s eliminado correctamente. Memoria liberada: %zu bytes.\n", estudiante->id, memoria_liberada);
        
        // Libera la memoria asignada dinámicamente
        free(estudiante->nombre);
        free(estudiante->apellido);
        free(estudiante->calificaciones);
        free(estudiante);
    }
}

// Función principal
int main() {
    // Definición de calificaciones de prueba
    int calificaciones[] = {85, 90, 78};
    size_t num_calificaciones = 3;
    size_t memoria_sin_opt = 0, memoria_opt = 0;

    // Evaluación de la versión sin optimización
    printf("\n===== SIN OPTIMIZACION =====\n");
    clock_t tiempo_sin_opt = clock(); // Inicio de medición de tiempo
    EstudianteSinOpt *estudiante_sin_opt = crear_estudiante_sin_opt("Carlos", "Gomez", 20, "12345678", calificaciones, num_calificaciones);
    clock_t tiempo_sin_opt_fin = clock(); // Fin de medición de tiempo
    
    if (estudiante_sin_opt) {
        memoria_sin_opt = sizeof(EstudianteSinOpt) + strlen(estudiante_sin_opt->nombre) + strlen(estudiante_sin_opt->apellido) + strlen(estudiante_sin_opt->ID) + num_calificaciones * sizeof(int);
        printf("Estudiante \"%s %s\" agregado correctamente. Memoria utilizada: %zu bytes.\n", estudiante_sin_opt->nombre, estudiante_sin_opt->apellido, memoria_sin_opt);
        liberar_estudiante_sin_opt(estudiante_sin_opt);
    }

    // Evaluación de la versión optimizada
    printf("\n===== CON OPTIMIZACION =====\n");
    clock_t tiempo_opt = clock();
    EstudianteOpt *estudiante_opt = crear_estudiante_opt("Carlos", "Gomez", 20, "12345678", calificaciones, num_calificaciones);
    clock_t tiempo_opt_fin = clock();
    
    if (estudiante_opt) {
        memoria_opt = sizeof(EstudianteOpt) + strlen(estudiante_opt->nombre) + strlen(estudiante_opt->apellido) + num_calificaciones * sizeof(int);
        printf("Estudiante \"%s %s\" agregado correctamente. Memoria utilizada: %zu bytes.\n", estudiante_opt->nombre, estudiante_opt->apellido, memoria_opt);
        liberar_estudiante_opt(estudiante_opt);
    }

    // Comparación de métricas
    printf("\n===== COMPARACION =====\n");
    printf("| Memoria utilizada | %14zu bytes | %14zu bytes |\n", memoria_sin_opt, memoria_opt);
    printf("| Tiempo de ejecucion | %14.6lf ms | %14.6lf ms |\n", (double)(tiempo_sin_opt_fin - tiempo_sin_opt) / CLOCKS_PER_SEC * 1000, (double)(tiempo_opt_fin - tiempo_opt) / CLOCKS_PER_SEC * 1000);

    return 0;
}
