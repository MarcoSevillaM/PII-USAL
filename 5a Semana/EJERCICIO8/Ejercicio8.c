#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 30

typedef struct persona{
char nombre[30];
char ciudad[15];
int edad;
float peso;
}Persona;

int leer_delimitado_aste (FILE *f1, char *nom, char *ciud, int *edad, float *peso);
int leer_tabulado (FILE *f2, char *nom, char *ciud, int *edad, float *peso);

int main (){
int i;
int dim1,dim2;
FILE *f1,*f2, *ftotal;
Persona lista1[DIM], lista2[DIM];

if((f1= fopen("f01.txt","r"))== NULL){
printf("ERROR\n");
return 1;
}
else{
dim1 = 0;	     
while (leer_delimitado_aste(f1, lista1[dim1].nombre, lista1[dim1].ciudad, &lista1[dim1].edad, &lista1[dim1].peso) != EOF ){
dim1++;
}
fclose(f1);
}

if((f2= fopen("f02.txt","r"))== NULL){
printf("ERROR\n");
return 1;
}
else{
dim2 = 0;	     
while ( leer_tabulado(f2, lista2[dim2].nombre, lista2[dim2].ciudad, &lista2[dim2].edad, &lista2[dim2].peso) != EOF ) {
dim2++;
}
fclose(f2);
}
if((ftotal= fopen("Resultado.txt","a"))== NULL){
printf("ERROR\n");
return 1;
}
else{
for (i=0; i<dim1; i++){
fprintf(ftotal, "%30s%14s%3d%5.2f\n", lista1[i].nombre, lista1[i].ciudad, lista1[i].edad, lista1[i].peso);
}
for (i=0; i<dim2; i++){
fprintf(ftotal, "%30s%14s%3d%5.2f\n", lista2[i].nombre, lista2[i].ciudad, lista2[i].edad, lista2[i].peso);
}
fclose(ftotal);
}

return 0;
}
//------------------------------------------------------------------------------------------------------------


int leer_delimitado_aste(FILE *f1, char *nom, char *ciud, int *edad, float *peso) {

if (fscanf(f1, "%[^*]%*c%[^*]%*c%d%*c%f%*c", nom, ciud, edad, peso) == EOF){
    return (EOF);
}
   else{
      return 0;
   }
}

int leer_tabulado(FILE *f2, char *nom, char *ciudad,int *edad, float *peso) {

   if ( fscanf(f2, "%[^\t]%*c%[^\t]%d%f%*c",nom, ciudad, edad, peso) == EOF){
      return (EOF);
   }
   else{
      return 0;
   }
}












