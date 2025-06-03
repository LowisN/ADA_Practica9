#include <stdio.h>
#include <stdlib.h>

int calcularAguaAtrapada(int* altura, int n) {
    if (n <= 2) return 0;
    
    int aguaTotal = 0;
    int* maxIzquierda = (int*)malloc(n * sizeof(int));
    int* maxDerecha = (int*)malloc(n * sizeof(int));
    
    //Encontrar máximo a la izquierda para cada posición
    maxIzquierda[0] = altura[0];
    for (int i = 1; i < n; i++) {
        maxIzquierda[i] = (altura[i] > maxIzquierda[i-1]) ? 
                          altura[i] : maxIzquierda[i-1];
    }
    
    //Encontrar máximo a la derecha para cada posición
    maxDerecha[n-1] = altura[n-1];
    for (int i = n-2; i >= 0; i--) {
        maxDerecha[i] = (altura[i] > maxDerecha[i+1]) ? 
                        altura[i] : maxDerecha[i+1];
    }
    
    //Calcular agua atrapada en cada posición
    for (int i = 1; i < n-1; i++) {
        int minAltura = (maxIzquierda[i] < maxDerecha[i]) ? 
                        maxIzquierda[i] : maxDerecha[i];
        if (minAltura > altura[i]) {
            aguaTotal += minAltura - altura[i];
        }
    }
    
    free(maxIzquierda);
    free(maxDerecha);
    return aguaTotal;
}

int main(int argc, char* argv[]) {
    //ejemplo 1
    int altura1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n1 = sizeof(altura1) / sizeof(altura1[0]);
    printf("Ejemplo 1:\n");
    printf("Entrada: height = [");
    for (int i = 0; i < n1; i++) {
        printf("%d", altura1[i]);
        if (i < n1-1) printf(",");
    }
    printf("]\n");
    printf("Salida: %d\n\n", calcularAguaAtrapada(altura1, n1));
    
    //ejemplo 2
    int altura2[] = {4,2,0,3,2,5};
    int n2 = sizeof(altura2) / sizeof(altura2[0]);
    printf("Ejemplo 2:\n");
    printf("Entrada: height = [");
    for (int i = 0; i < n2; i++) {
        printf("%d", altura2[i]);
        if (i < n2-1) printf(",");
    }
    printf("]\n");
    printf("Salida: %d\n", calcularAguaAtrapada(altura2, n2));
    
    return 0;
}