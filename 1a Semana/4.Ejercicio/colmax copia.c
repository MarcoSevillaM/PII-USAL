//Marco Sevilla Martín 
//Grupo PB4 Programación II
//id00780760@usal.es

#include <stdio.h>
#include <stdlib.h>
#define COLS 25

int *Vcolumna(int (*matriz)[COLS], int fil,, int col, int indicol);

int main (){
	int (*mat)[COLS];
	int fila, columna, i, j, colmos;
	int *vcol=NULL;
	printf("El programa pedirá introducir una matriz y a continuación presentará la coluna que indiquemos. ");
	printf("\n========================================================================================================================\n\n");
	
	
	do{
	printf("Introduce el numero de filas:\n");
	scanf("%d",&fila);
	printf("Introduce el numero de columnas:\n");
	scanf("%d",&columna);
	}while (columna<=0||columna>COLS);
	
	printf("Llenamos la matriz:\n\n");
	for(i=0;i<fila;i++){
		for(j=0;j<columna;j++){
			printf("Introduce el elemento (%d,%d): ",i+1,j+1);
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0;i<fila;i++){
		printf("\n");
		for(j=0;j<columna;j++){
			printf("%3d", mat[i][j]);
		}
	}
	printf("\nColumna que desee mostrar:");
	scanf("%d", &colmos);
	vcol=Vcolumna(mat, fila, colmos-1);
	if(vcol != NULL){
		for(i=0;i<fila; i++){
			printf("%d\n", vcol[i]);
		}
	}
	else{
		printf("\nError(Valor NULL)\n");
		return -1;
	}
	
	
	printf("\n");
	
	free(vcol);
	return 0;
}


int *Vcolumna(int (*matriz)[COLS], int fil, int indicol){
	int i;
	int *col;

}
	

	