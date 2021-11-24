//Marco Sevilla Martín
//id00780760@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.
//1.2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main ()
{
	char opcion;
    int numFil, numCol,errNum;
    
	matFloatRef A, B;
	matFloat * C;
    
    A = B = C = NULL;
    
	do {
		printf("\nSuma de matrices:\n A) Leer datos\n B) Multiplicar matrices\n C) Ver resultados\n D) Liberar matrices\n Q) Salir\n");
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
				printf("\n\nMultiplicación...");
                if (NULL != C){
                    liberarMatFloat(C);
                    free(C);
                }
				C = multiplicarMatFloat(A, B, &errNum);
				if (NULL == C)
                    printf("... no realizada %d\n",errNum);
                else
                    printf("efectuada.\n\n");
				break;
			case 'C':
				printf("\n\nVisualización de resultados\n\n");
				printf("\n\nPrimera matriz\n\n");
				mostrarMatFloat(A, " %2.2lf ");
				printf("\n\nSegunda matriz\n\n");
				mostrarMatFloat(B, " %2.2lf ");
				printf("\n\nMatriz suma\n\n");
				mostrarMatFloat(C, " %2.2lf ");
				break;
			case 'D':
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


