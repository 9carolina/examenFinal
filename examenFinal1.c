#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 30
#define REPETICIONES 10000
void llenarMatriz(int matriz[TAM][TAM]){
	int i,j;
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            matriz[i][j]=rand()%10;
        }
    }
}
void imprimirMatriz(int matriz[TAM][TAM]){
   	int i,j;
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
void multiplicarMatrices(int matriz1[TAM][TAM], int matriz2[TAM][TAM], int resultado[TAM][TAM]){
    int i,j,k;
	for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            resultado[i][j]=0;
            for (k=0;k<TAM;k++){
                resultado[i][j]+=matriz1[i][k]*matriz2[k][j];
            }
        }
    }
}
int main(){
    int matriz1[TAM][TAM], matriz2[TAM][TAM], resultado[TAM][TAM];
    clock_t inicio, fin;
    double tiempo_usado;

    srand(time(NULL));

    llenarMatriz(matriz1);
    llenarMatriz(matriz2);

    printf("MATRIZ 1:\n");
    imprimirMatriz(matriz1);
    printf("\nMATRIZ 2:\n");
    imprimirMatriz(matriz2);

    inicio=clock();
    int i;
    for (i=0;i<REPETICIONES;i++){
        multiplicarMatrices(matriz1, matriz2, resultado);
    }
    fin=clock();

    tiempo_usado=((double) (fin - inicio)) / CLOCKS_PER_SEC/REPETICIONES*1000.0;

    printf("\nMATRIZ RESULTANTE (MULTIPLICACION):\n");
    imprimirMatriz(resultado);

    printf("\nTiempo de ejecucion: %.2f milisegundos\n", tiempo_usado);

    return 0;
}
