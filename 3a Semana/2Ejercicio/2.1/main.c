//Marco Sevilla Martín
//id00780760@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.
//
//2.1


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main (int argc, const char * argv[]){
	char menu[] = "\nSuma de matrices: \nA) Leer datos \nB) Sumar matrices \nC) Multiplicar matrices \nD) Ver resultados \nE) Columna con mayor suma de valores \nF) Liberar matrices \nQ) Salir\n";
	char opcion;
    int numFil, numCol,errNum,errColMax;
	floatRef colMax;
	int i;
    
	matFloatRef A, B, C, D;
    
    A = B = C = D = NULL;
    
	do {
		printf("%s ",menu);
        scanf("%c%*c",&opcion);
		opcion = toupper(opcion);
		switch (opcion) {
			case 'A':
                if (A != NULL || B != NULL) {
                    printf("Ya existen matrices ... opciones C o D\n\n");
                    break;
                }
				printf("\n\nDimensiones de las matrices:\n\n");
                printf("Número de filas: ");
                scanf("%d%*c",&numFil);
                printf("Número de columnas: ");
                scanf("%d%*c",&numCol);
                
                printf("Primera matriz: \n");
                if (NULL != (A = crearMatFloat(numFil, numCol, &errNum)))
                    leerMatFloat(A, "Matriz A");
                else
                    printf("Fallo creación matriz: %d\n",errNum);
                
                printf("Segunda matriz: \n");
				if (NULL != (B = crearMatFloat(numFil, numCol, &errNum)))
                    leerMatFloat(B, "Matriz B");
                else
                    printf("Fallo creación matriz: %d\n",errNum);
                break;
			case 'B':
				printf("\n\nSuma...");
                if (NULL != C){
                    liberarMatFloat(C);
                    free(C);
                }
				if (NULL == (C = sumarMatFloat(A, B, &errNum)))
                    printf("... no realizada %d\n",errNum);
                else
                    printf("efectuada.\n\n");
				break;
			case 'C':
				printf("\n\nMultiplicación...");
                if (NULL != D){
                    liberarMatFloat(D);
                    free(C);
                }
				if (NULL == (D = multiplicarMatFloat(A, B, &errNum)))
                    printf("... no realizada %d\n",errNum);
                else
                    printf("efectuada.\n\n");
				break;
			case 'D':
				printf("\n\nVisualización de resultados\n\n");
				printf("\n\nPrimera matriz\n\n");
				mostrarMatFloat(A, " %2.2lf ");
				printf("\n\nSegunda matriz\n\n");
				mostrarMatFloat(B, " %2.2lf ");
				printf("\n\nMatriz suma\n\n");
				mostrarMatFloat(C, " %2.2lf ");
				printf("\n\nMatriz multiplicada:\n\n");
				mostrarMatFloat(D, " %2.2lf ");
				break;
			case 'E':
				printf("\n\nColumna que contiene el valor máximo de la matriz A\n");
				colMax = obtenerColumnaMaxMatFloat(A, &errColMax);
				mostrarVectorFloat(colMax, A->numFil);
				printf("\n\nColumna que contiene el valor máximo de la matriz B\n");
				colMax = obtenerColumnaMaxMatFloat(B, &errColMax);
				mostrarVectorFloat(colMax, B->numFil);
				break;
			case 'F':
				printf("\n\nLiberación de matrices...");
				liberarMatFloat(A);
				free(A);
				A = NULL;
				liberarMatFloat(B);
				free(B);
				B = NULL;
				liberarMatFloat(C);
				free(C);
				C = NULL;
				liberarMatFloat(D);
				D = NULL;
				printf("efectuada.\n\n");
                break;
			case 'Q':
				printf("\n\nSaliendo.\n\n");
				break;
			default:
				printf("\n\nOpción incorrecta!\a\n\n");
				break;
		}
	} while ('Q' != opcion);
	printf("\n\nTerminación normal del programa.\n\n");
    return 0;
}


