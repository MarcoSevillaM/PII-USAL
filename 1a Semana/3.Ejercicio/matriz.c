#include <stdio.h>
#include <stdlib.h>
#define COLS 25

int* SumaFuncion (int (*matriz)[COLS], int fil, int col);

int main (){
	int **matriz=NULL;
	int fila, columna, i, j;
	int suma=0;
	int *vsuma=NULL;
	printf("El programa pedirá introducir una matriz y a continuación presentará la fila cuya suma sea mayor. ");
	printf("\n========================================================================================================================\n\n");
	do{
	printf("Introduce el numero de filas:\n");
	scanf("%d",&fila);
	}while (fila<=0||fila>COLS);
	
	
	matriz= (int**) malloc(fila * sizeof(int*));
	if(matriz==NULL){
		printf("Error al llenas el vector de punteros");
		exit(-1);
	}
	do{
	printf("Introduce el numero de columnas:\n");
	scanf("%d", &columna);
	}while (columna<=0||columna>COLS);
	
	for(i=0;i<fila;i++){
		matriz[i]=(int *)malloc (columna * sizeof(int));
		if(matriz[i]==NULL){
			printf("Error al llenar la fila %d", i+1);
			for (j=i;j>0;j--){
				free(matriz[j]);
			}
			free (matriz);
			exit(-2);
		}
	}
	
	printf("Llenamos la matriz:\n\n");
	for(i=0;i<fila;i++){
		for(j=0;j<columna;j++){
			printf("Introduce el elemento (%d,%d): ",i+1,j+1);
			scanf("%d",&matriz[i][j]);
		}
	}
	for(i=0;i<fila;i++){
		printf("\n");
		for(j=0;j<columna;j++){
			printf("%3d", matriz[i][j]);
		}
	}
	printf("\n");
	vsuma=SumaFuncion(*matriz, fila, columna);
	printf("El vector con mayor suma es: %d\n\n", *vsuma);
	printf("Suma: %d",suma);
	
	for (i=0;i<fila;i++){
		free(matriz[i]);
	}
	free(matriz);


	return 0;
}



int * SumaFuncion(int (*matriz)[COLS], int fil, int col){
	int i,j;
	int suma;
	int sumamax=0;
	int* vectorsuma=NULL;
	
	for (i=0;i<fil;i++){
		for (j=0;j<col;j++){
			suma+=matriz[i][j];
		}
	if (suma<sumamax){
		*vectorsuma=(*matriz)[col];
		}
	}
	return vectorsuma;
}





