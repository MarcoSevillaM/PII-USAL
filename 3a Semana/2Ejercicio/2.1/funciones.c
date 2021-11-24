//Marco Sevilla Martín
//id00780760@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.
//2.1
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


matFloatRef crearMatFloat(int numFil, int numCol, intRef errNum)
{
	matFloatRef temp;
	if (!(numFil > 0 && numCol > 0)) {
#ifdef DEBUG
        fprintf(stderr, "Error: dimensiones incorrectas: %d, %d\n",numFil,numCol);
#endif
        *errNum = -1;
        return NULL;
	}
	if (NULL == (temp = malloc(sizeof(matFloat)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallor reserva memoria tipo matriz\n");
#endif
        *errNum = -2;
        return NULL;
    }
    else if (NULL == (temp->m = malloc(numFil*numCol*sizeof(float)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallor reserva memoria matriz\n");
#endif
        free(temp);
        *errNum = -3;
        return NULL;
    }
    else {
        temp->numFil = numFil;
        temp->numCol = numCol;
        *errNum = 0;
        return temp;
    }
}

matIntRef crearMatInt(int numFil, int numCol, intRef errNum)
{
	matIntRef temp;
	if (!(numFil > 0 && numCol > 0)) {
#ifdef DEBUG
        fprintf(stderr, "Error: dimensiones incorrectas: %d, %d\n",numFil,numCol);
#endif
        *errNum = -1;
        return NULL;
	}
	if (NULL == (temp = malloc(sizeof(matInt)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallo reserva memoria tipo matriz\n");
#endif
        *errNum = -2;
        return NULL;
    }
    else if (NULL == (temp->m = malloc(numFil*numCol*sizeof(int)))){
#ifdef DEBUG
        fprintf(stderr, "Error: fallo reserva memoria matriz\n");
#endif
        free(temp);
        *errNum = -3;
        return NULL;
    }
    else {
        temp->numFil = numFil;
        temp->numCol = numCol;
        *errNum = 0;
        return temp;
    }
}

int fallaMatrizFloat(matFloatRef mat)
{
    if (mat == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: referencia tipo matriz\n");
#endif
        return -1;
    }
    if (mat->numFil <= 0 || mat->numCol <=0 || mat->m == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: matriz mal construida\n");
#endif
        return -2;
    }
    return 0;
}

int fallaMatrizInt(matIntRef mat)
{
    if (mat == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: referencia tipo matriz\n");
#endif
        return -1;
    }
    if (mat->numFil <= 0 || mat->numCol <=0 || mat->m == NULL) {
#ifdef DEBUG
        fprintf(stderr, "Error: matriz mal construida\n");
#endif
        return -2;
    }
    return 0;
}

int leerMatFloat(matFloatRef mat, charRef c)
{
    int i,j,res;
	
	if (!(res = fallaMatrizFloat(mat))) {
        if (NULL == c)
            c = "m";
        for (i=0; i < mat->numFil; i++) {
            for (j=0; j < mat->numCol; j++) {
                printf("%s[%d][%d] = ",c,i,j);
                scanf("%f%*c",&(mat->m[i * mat->numCol + j]));
                //scanf("%f%*c",mat->m + i * mat->numCol + j);
            }
        }
        return 0;
    }
    else
        return res;
}

int leerMatInt(matIntRef mat, charRef c)
{
    
    int i,j,res;
	
	if (!(res = fallaMatrizInt(mat))) {
        if (NULL == c)
            c = "m";
        for (i=0; i < mat->numFil; i++) {
            for (j=0; j < mat->numCol; j++) {
                printf("%s[%d][%d] = ",c,i,j);
                scanf("%d%*c",&(mat->m[i * mat->numCol + j]));
                //scanf("%d%*c",mat->m + i * mat->numCol + j);
            }
        }
        return 0;
    }
    else
        return res;
}


int
mostrarMatFloat(matFloatRef mat, charRef c)
{
    int res,i,j;
	
    if (!(res = fallaMatrizFloat(mat))) {
        if (NULL == c) {
            c = " %g ";
        }
        for (i = 0; i < mat->numFil; i++) {
            printf("| ");
            for (j = 0; j < mat->numCol; j++) {
                printf(c,mat->m[i*mat->numCol+j]);
                //printf(c,*(mat->m + i*mat->numCol + j));
            }
            printf(" |\n");
        }
        return 0;
    }
	else
        return res;
}

int
mostrarMatInt(matIntRef mat, charRef c)
{
    int i,j,res;
	
    if (!(res = fallaMatrizInt(mat))) {
        if (NULL == c) {
            c = " %g ";
        }
        for (i = 0; i < mat->numFil; i++) {
            printf("| ");
            for (j = 0; j < mat->numCol; j++) {
                printf(c,mat->m[i*mat->numCol+j]);
                //printf(c,*(mat->m + i*mat->numCol + j));
            }
            printf(" |\n");
        }
        return 0;
    }
    else
        return res;
}


int
liberarMatFloat(matFloatRef mat)
{
    int res;
    
	if (!(res = fallaMatrizFloat(mat))) {
        free(mat->m);
        mat->m = NULL;
        mat->numFil = -1;
        mat->numCol = -1;
        return 0;
    }
	else
        return res;
}

int
liberarMatInt(matIntRef mat)
{
    int res;
    
	if (!(res = fallaMatrizInt(mat))) {
        free(mat->m);
        mat->m = NULL;
        mat->numFil = -1;
        mat->numCol = -1;
        return 0;
    }
	else
        return res;
}

matFloatRef
sumarMatFloat(matFloatRef a, matFloatRef b, intRef errNum)
{
	int i, totalElements, res;
    matFloatRef c;
    
    if (!(res =fallaMatrizFloat(a)) && !(res = fallaMatrizFloat(b))) {
        if (!(a->numFil == b->numFil && a->numCol == b->numCol)) {
#ifdef DEBUG
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (c = crearMatFloat(a->numFil, a->numCol, &res))) {
                totalElements = a->numFil * a->numCol;
                for (i=0; i<totalElements; i++) {
                    c->m[i] = a->m[i] + b->m[i];
                }
                *errNum = 0;
                return c;
            }
            else {
                *errNum = res;
                return NULL;
            }
        }
	}
    else {
        *errNum = res;
        return NULL;
    }
}

matIntRef
sumarMatInt(matIntRef a, matIntRef b, intRef errNum)
{
	int i, totalElements, res;
    matIntRef c;
    
    if (!(res =fallaMatrizInt(a)) && !(res = fallaMatrizInt(b))) {
        if (!(a->numFil == b->numFil && a->numCol == b->numCol)) {
#ifdef DEBUG
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (c = crearMatInt(a->numFil, a->numCol, &res))) {
                totalElements = a->numFil * a->numCol;
                for (i=0; i<totalElements; i++) {
                    c->m[i] = a->m[i] + b->m[i];
                }
                return 0;
            }
            else {
                *errNum = res;
                return NULL;
            }
        }
	}
    else {
        *errNum = res;
        return NULL;
    }
}

//Realiza la multiplicación de las matrices
matFloatRef multiplicarMatFloat(matFloatRef a, matFloatRef b, intRef errNum)
{
	int i,j,k, error;
    matFloatRef matMul;
    
    if (!(error =fallaMatrizFloat(a)) && !(error = fallaMatrizFloat(b))) {
        if (!(a->numCol == b->numFil)) {
#ifdef DEBUG
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (matMul = crearMatFloat(a->numFil, b->numCol, &error))) {
				
                for (i=0; i < a->numFil; i++)
                    for (j = 0; j < b->numCol; j++){
                    	(matMul->m[i*matMul->numCol+j])=0;
						for(k=0;k< b->numCol; k++)
							matMul->m[i*matMul->numCol+j] += (a->m[i*matMul->numCol+k]) * (b->m[k*matMul->numCol+j]);
                    }
                *errNum = 0;
                return matMul;
            }
            else {
                *errNum = error;
                return NULL;
            }
        }
	}
    else {
        *errNum = error;
        return NULL;
    }
}

matIntRef multiplicarMatInt(matIntRef a, matIntRef b, intRef errNum)
{
	int i,j,k, error;
    matIntRef matMul ;
    
    if (!(error =fallaMatrizInt(a)) && !(error = fallaMatrizInt(b))) {
        if (!(a->numCol == b->numFil)) {
#ifdef DEBUG
            fprintf(stderr, "Error: dimensiones incorrectas\n\n");
#endif
            *errNum = -5;
            return NULL;
        }
        else {
            if (NULL != (matMul= crearMatInt(a->numFil, b->numCol, &error))) {
		
                for (i=0; i < a->numFil; i++)
                    for (j = 0; j < b->numCol; j++){
                    	(matMul->m[i*matMul->numCol+j])=0; //[i*matMul->numCol+j]
						for(k=0;k< b->numCol; k++)
							matMul->m[i*matMul->numCol+j] += (a->m[i*matMul->numCol+k]) * (b->m[k*matMul->numCol+j]);
                    }
                *errNum = 0;
                return matMul;
            }
            else {
                *errNum = error;
                return NULL;
            }
        }
	}
    else {
        *errNum = error;
        return NULL;
    }
}
////////

float *obtenerColumnaMaxMatFloat(matFloatRef mat, intRef errNum)
{
	int i,j,numCol;
	float suma, sumaMax;
	floatRef colMax=NULL;
	
	*errNum = fallaMatrizFloat(mat);
	if(*errNum != 0) return NULL;
	//Calculo de la Columna con mayor suma de valores
	numCol=sumaMax=0;
	for(i=0;i<mat->numFil;i++){
		sumaMax += mat->m[i*mat->numFil];
	}
	for(i=1;i<mat->numCol;i++){
		for(j=0, suma=0;j<mat->numFil;j++){
			suma += mat->m[i*mat->numCol+j];  //mat->m[j][i]
		}
		if(suma >= sumaMax){
			numCol = i;
			sumaMax = suma;
		}
	}
	//Creación del vector para almacenar la columna máxima
	if(NULL == (colMax = (floatRef) malloc(mat->numFil*sizeof(float)))){
		*errNum = -5;
		return NULL;
	}
	else{
		for(i=0;i<mat->numFil;i++){
			colMax[i] = mat->m[i*mat->numCol+numCol];
		}
		*errNum = 0;
		return colMax;
	}
	
}

int *obtenerColumnaMaxMatInt(matIntRef mat, intRef errNum)
{
	int i,j,numCol;
	int suma, sumaMax;
	intRef colMax=NULL;
	
	*errNum = fallaMatrizInt(mat);
	if(*errNum != 0) return NULL;
	//Calculo de la Columna con mayor suma de valores
	numCol=sumaMax=0;
	for(i=0;i<mat->numFil;i++){
		sumaMax += mat->m[i*mat->numCol];
	}
	for(i=1;i<mat->numCol;i++){
		for(j=0, suma=0;j<mat->numFil;j++){
			suma += mat->m[j*mat->numCol+i];
		}
		if(suma >= sumaMax){
			numCol = i;
			sumaMax = suma;
		}
	}
	
	//Creación del vector para almacenar la columna máxima
	if(NULL == (colMax = (intRef) malloc(mat->numFil*sizeof(int)))){
		*errNum = -5;
		return NULL;
	}
	else{
		for(i=0;i<mat->numFil;i++){
			colMax[i] = mat->m[i*mat->numCol+numCol];
		}
		*errNum = 0;
		return colMax;
	}
}

void mostrarVectorFloat(floatRef mat, int tam)
{
	int i;
	if(mat == NULL){
		printf("\nError: matriz no válida\n");
		exit (-1);
	}
	for(i=0;i<tam;i++){
		printf("%.0f ,", mat[i]);
	}
}

void mostrarVectorInt(intRef mat, int tam)
{
	int i;
	if(mat == NULL){
		printf("\nError: matriz no válida\n");
		exit (-2);
	}
	for(i=0;i<tam;i++){
		printf("%d ,", mat[i]);
	}
}
