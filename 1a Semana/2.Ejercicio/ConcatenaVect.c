//Marco Sevilla MArtín
//Programación II PB4
//id00780760@usal.es

#include <stdio.h>
#include <stdlib.h>

int *leerVector (int *);

int *concatenaVectores (int *, int, int *, int);

void presentaVector (int *, int);

int main (){
	int dim1,dim2;
	int *vct1=NULL;
	int *vct2=NULL;
	int *vct=NULL;
	dim1=dim2=0;
	printf("\n==========================================\n");
	printf("Este programa realizará la concatenación de dos vectores; es decir une dos vectores uno tras otro.");
	printf("\n==========================================\n\n\n");
	vct1=leerVector(&dim1);
	
	if(vct1==NULL){
		printf("Error al cargar el vector 1\n");
		exit(-3);
	}
	printf("El valor de dim1 es: %d\n",dim1);
	printf("\n");
	vct2=leerVector(&dim2);
	
	if(vct2==NULL){
		printf("Error al cargar el vector 2\n");
		exit(-4);
	}		
	vct= concatenaVectores(vct1, dim1, vct2, dim2);
	int dim=0;
	
	dim=dim1+dim2;
	
	presentaVector(vct, dim);
	
	free(vct1);
	free(vct2);
	free(vct);
	printf("\n");
	return 0;
}



int * concatenaVectores (int *vct1, int dim1, int *vct2, int dim2){
	int *ptr=NULL;
	int i, sum;
	int aux=0;
	sum=dim1+dim2;
	ptr = (int *)calloc(dim1+dim2, sizeof(int));
	if (ptr==NULL)
	{
	printf("Error en la concatenación\n");
	exit(-2);
}
	
	for(i=0; i<dim1; i++){
		ptr[i]=vct1[i];
	}
	for(i=dim1; i<sum; i++){
		ptr[i]=vct2[aux];
		aux++;
	}
	if(aux>dim2)
	{
	printf("Error");
	}		
	if(aux<dim2)
	{
	printf("Éxito");
	}
	
	return ptr;
}




int *leerVector (int *dim){
	int *vct=NULL;
	do{
	printf("Introduce el numero de elementos:");
	scanf("%d",dim);}while ((*dim)<=0);
	vct= malloc ((*dim) * sizeof(int));
	if (vct==NULL)
	{
	printf("Error en la reserva de memoria\n");
	
	free(vct);
	
	exit(-1);
	}
	
	for(int i=0;i<(*dim);i++)
	{
	printf("Introduzca el elemento: %d\n",i+1);
	scanf("%d",&vct[i]);}
	return vct;
}
void presentaVector (int *vct, int dim)
{
	int i;
	printf("El vector concatenado es:\n\n");
	for(i=0; i<dim;i++){
		printf("%d\t",vct[i]);
	}
}

