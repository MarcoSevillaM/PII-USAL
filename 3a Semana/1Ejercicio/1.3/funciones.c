//Marco Sevilla Martín
//id00780760@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.
//1.3

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



matFloatRef crearMatFloat(int numFil, int numCol, intRef errNum)
{
	matFloatRef temp;
    int i;
    
	if (!(numFil > 0 && numCol > 0 )) {
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
    else if (NULL == (temp->m = malloc(numFil*sizeof(float *)))){
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
        for (i = 0; i < numFil; i++) {
            if (NULL == (temp->m[i] = malloc(numCol*sizeof(float)))){
                for (i--; i >= 0; i--)
                    free(temp->m[i]);
                free(temp->m);
                free(temp);
#ifdef DEBUG
                fprintf(stderr, "Error: fallor reserva memoria matriz\n");
#endif
                *errNum = -4;
                return NULL;
            }
        }
        *errNum = 0;
        return temp;
    }
}



matIntRef crearMatInt(int numFil, int numCol, intRef errNum)
{
	matIntRef temp;
    int i;
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
    else if (NULL == (temp->m = malloc(numFil*sizeof(int *)))){
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
        for (i = 0; i < numFil; i++) {
            if (NULL == (temp->m[i] = malloc(numCol*sizeof(int)))){
                for (i--; i >= 0; i--)
                    free(temp->m[i]);
                free(temp->m);
                free(temp);
#ifdef DEBUG
                fprintf(stderr, "Error: fallor reserva memoria matriz\n");
#endif
                *errNum = -4;
                return NULL;
            }
        }
        *errNum = 0;
        return temp;
    }
}

int fallaMatrizFloat(matFloatRef mat)
{
    int i;
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
    for (i = 0; i < mat->numFil; i++)
        if (mat->m[i] == NULL){
#ifdef DEBUG
            fprintf(stderr, "Error: fila %d nula\n",i);
#endif
            return -3;
        }
    return 0;
}

int fallaMatrizInt(matIntRef mat)
{
    int i;
    
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
    for (i = 0; i < mat->numFil; i++)
        if (mat->m[i] == NULL){
#ifdef DEBUG
            fprintf(stderr, "Error: fila %d nula\n",i);
#endif
            return -3;
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
                scanf("%f%*c",&(mat->m[i][j]));
                //scanf("%f%*c",(*(mat->m + i) + j));
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
                scanf("%d%*c",&(mat->m[i][j]));
                //scanf("%d%*c",(*(mat->m + i) + j));
            }
        }
        return 0;
    }
    else
        return res;
}


int mostrarMatFloat(matFloatRef mat, charRef c)
{
    int res,i,j;
	
    if (!(res = fallaMatrizFloat(mat))) {
        if (NULL == c) {
            c = " %g ";
        }
        for (i = 0; i < mat->numFil; i++) {
            printf("| ");
            for (j = 0; j < mat->numCol; j++) {
                printf(c,mat->m[i][j]);
                //printf(c,*(*(mat->m + i) + j));
            }
            printf(" |\n");
        }
        return 0;
    }
	else
        return res;
}

int mostrarMatInt(matIntRef mat, charRef c)
{
    int i,j,res;
	
    if (!(res = fallaMatrizInt(mat))) {
        if (NULL == c) {
            c = " %g ";
        }
        for (i = 0; i < mat->numFil; i++) {
            printf("| ");
            for (j = 0; j < mat->numCol; j++) {
                printf(c,mat->m[i][j]);
                //printf(c,*(*(mat->m + i) + j));
            }
            printf(" |\n");
        }
        return 0;
    }
    else
        return res;
}


int liberarMatFloat(matFloatRef mat)
{
    int res,i;
    
	if (!(res = fallaMatrizFloat(mat))) {
		for(i = 0; i < mat->numFil ; i++)
			free(mat->m[i]);
        free(mat->m);
        mat->m = NULL;
        mat->numFil = -1;
        mat->numCol = -1;
        return 0;
    }
	else
        return res;
}

int liberarMatInt(matIntRef mat)
{
    int res,i ;
    
	if (!(res = fallaMatrizInt(mat))) {
		for(i = 0; i < mat->numFil ; i++)
			free(mat->m[i]);
        free(mat->m);
        mat->m = NULL;
        mat->numFil = -1;
        mat->numCol = -1;
        return 0;
    }
	else
        return res;
}

matFloatRef sumarMatFloat(matFloatRef a, matFloatRef b, intRef errNum)
{
	int i,j, res;
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
                for (i=0; i < a->numFil; i++) 
                    for (j = 0; j < a->numCol; j++) 
                        c->m[i][j] = a->m[i][j] + b->m[i][j];
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

matIntRef sumarMatInt(matIntRef a, matIntRef b, intRef errNum)
{
	int i, j, res;
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
                for (i=0; i < a->numFil; i++)
                    for (j = 0; j < a->numCol; j++)
                        c->m[i][j] = a->m[i][j] + b->m[i][j];
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
                    	(matMul->m[i][j])=0;
						for(k=0;k< b->numCol; k++)
							matMul->m[i][j] += (a->m[i][k]) * (b->m[k][j]);
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
                    	(matMul->m[i][j])=0;
						for(k=0;k< b->numCol; k++)
							matMul->m[i][j] += (a->m[i][k]) * (b->m[k][j]);
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



