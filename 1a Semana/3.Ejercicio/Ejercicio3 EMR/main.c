//Marco Sevilla Martín 
//Grupo PB4 Programación II
//id00780760@usal.es


#include "recibirMatriz.h"
#define FIL 5
#define COL 5

int main(){

    int * ptr=NULL;
    int mat[FIL][COL];
    int fil, i, j;
    
    printf("\nIntroducir numero de filas: ");
    scanf("%d", &fil);
    
    rellenarMatriz(mat, fil, COL);
    ptr = (int*) recibirMatriz(mat, fil, COL);
    
    for(i=0;i<fil;i++){
        printf("| ");
        for(j=0;j<COL;j++){
            printf("%3d", mat[i][j]);
        }
        printf(" |\n");
    }

    puts("\n--Vector mayor--");
    
    for(i=0;i<COL;i++){
        printf("\n%d", *(ptr+i));
    }
    puts("\n\n");
}