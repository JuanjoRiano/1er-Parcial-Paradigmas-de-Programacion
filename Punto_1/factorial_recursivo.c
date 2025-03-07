#include <stdio.h>
#include <time.h>

#define MAX 500  // Tamaño máximo del array para guardar el factorial


void multiply(int num, int result[], int *size) {
    int carry = 0;
    for (int i = 0; i < *size; i++) {
        int product = result[i] * num + carry;
        result[i] = product % 10;
        carry = product / 10;
    }
    while (carry) {
        result[*size] = carry % 10;
        carry /= 10;
        (*size)++;
    }
}

void factorial_recursivo(int n, int result[], int *size) {
    if (n == 1) return;  

    factorial_recursivo(n - 1, result, size);
    multiply(n, result, size);
}

int main() {
    int num;
    printf("Digite un número entero: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("El factorial de un número negativo no está definido.\n");
        return 1;
    }

    int result[MAX];  // Array para guardar el factorial
    result[0] = 1;    // 0! = 1 y 1! = 1
    int size = 1;     // Tamaño del número (1 dígito inicial)

    // Tomamos el tiempo de inicio
    clock_t inicio = clock();
    
    factorial_recursivo(num, result, &size);
    
    // Tomamos el tiempo de finalización
    clock_t fin = clock();

    // Calculamos el tiempo transcurrido en segundos
    double tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    // Mostramos el resultado
    printf("El factorial de %d es: ", num);
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");

    // Mostramos el tiempo de ejecución
    printf("Tiempo de ejecución: %.15f segundos\n", tiempo);

    return 0;
}
