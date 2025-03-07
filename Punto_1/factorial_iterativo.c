#include <stdio.h>
#include <time.h>


#define MAX 500  // Maximo tamaño 

int factorial_iterativo(int n, int result[]) {
    result[0] = 1;  
    int size = 1;   

    for (int num = 2; num <= n; num++) {
        int carry = 0;

        // Multiplica cada digito por num
        for (int i = 0; i < size; i++) {
            int product = result[i] * num + carry;
            result[i] = product % 10;  
            carry = product / 10;     
        }

        // Agregam los digitos restantes del acarreo
        while (carry) {
            result[size] = carry % 10;
            carry /= 10;
            size++;
        }
    }

    return size;  // Retorna el tamaño del resultado
}

int main() {
    int num;
    printf("Digite un numero entero: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("El factorial de un numero negativo no está definido.\n");
        return 1;
    }

    int result[MAX];
    clock_t inicio = clock();
    int size = factorial_iterativo(num, result);
    clock_t fin = clock();

    double tiempo = ((double)(fin - inicio))/CLOCKS_PER_SEC; 


    printf("El factorial es: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", result[i]);  // Imprime los digitos en orden inverso
    }
    printf("\nEl tiempo de ejecucion es de: %.6f segundos",tiempo);

    return 0;
}
