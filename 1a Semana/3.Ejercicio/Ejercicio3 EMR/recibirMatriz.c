//Marco Sevilla Martín 
//Grupo PB4 Programación II
//id00780760@usal.es

#include "recibirMatriz.h"
#define COL 5

int *recibirMatriz(int (*mat)[COL], int fil, int col){
    
    int i, j, suma=0, mayor=0;
    int *ptr = NULL;
    
    ptr = (int*) malloc(fil*sizeof(int));

    if(ptr == NULL){
        exit (-1);}
    
    for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
            suma += mat[i][j];
            if(suma>=mayor){
                ptr[j] = mat[i][j];
                mayor = suma;
                suma = 0;
            }else{suma = 0;}
        }
    }

    return ptr;
}

void rellenarMatriz(int (*mat)[COL],int fil, int col){
    
    int i, j;
    
    for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
            printf("Introduce valor para posicion (%d,%d): ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}