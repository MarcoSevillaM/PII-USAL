//Marco Sevilla Martín
//id00780760@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.
#include <stdio.h>
#include <stdlib.h>
#include "estudiante.h" 

Estudiante *crearVectorRegistros(int num, int *codError){
	Estudiante *ptr=NULL;
	if(num<=0){
		printf("Valor del parametro incorrecto\n");
		*codError=-1;
		return NULL;
	}
	ptr=(Estudiante *)malloc(num*sizeof(Estudiante));
	if(ptr==NULL){
		*codError=-2;
		printf("\nError en la invocación a la función reserva de memoria\n");
		return NULL;
	}
	*codError=0;
	return ptr;	
}

int cargarRegistrosAleatorios(Estudiante * estudiantes , int num){
	int i, error;
	if(estudiantes==NULL){
		printf("El valor introducido es menor que 1\n"); 
		error=-1;
		return error;
		exit(-1);}
	
	if(num<=0){
		printf("El valor introducido es menor que 1\n"); 
		error=-1;
		return error;}
	
	for (i=0;i<num;i++)
	{
		error=cargarUnRegistroAleatorio(&estudiantes[i]);
		if(error==-1){
			printf("Error al cargar el registro %d\n",i);
			return -1;}
	}
	return 0;
}

void mostrarRegistros(Estudiante * estudiantes , int num){
	int i;
	for (i=0; i<num; i++)
		{
		printf("Alumno %d:\n",i+1);
		mostrarUnRegistro(estudiantes[i]);
		}
	}


Estudiante **crearVectorRegistrosRef(int num, int *codError){
	Estudiante **ptr=NULL;
	int i,j;
	if(num<=0){
		printf("El valor introducido es incorrecto\n");
		*codError=-1;
		return NULL;
	}

	ptr=malloc(sizeof(Estudiante));
	if(ptr==NULL){
		*codError=-2;
		return NULL;
	}
	for (i=0;i<num;i++){
		ptr[i]=(Estudiante *)malloc(num* sizeof(Estudiante));
		if(ptr[i]==NULL){
			printf("Error en la invocacion a la función\n");
			*codError=-3;
			for(j=i--;i>=0;i--){
				free(ptr[j]);
			}
			free (ptr);
			return NULL;
		}
	}
	printf("VECTOR DE REF CREADO\n");
	*codError=0;
	return ptr;	
}

int cargarRegistrosAleatoriosRef(Estudiante **estudiantesRef , int num){
	int i,j;
	if(estudiantesRef==NULL){
		printf("Error al cargar <Registros AleatoriosRef>\n");
		return -1;
	}
	for (i=0; i<(num);i++){
			cargarUnRegistroAleatorio(estudiantesRef[i]);
	}
	return 0;
}

void mostrarRegistrosRef(Estudiante ** estudiantesRef , int num){
	int i,j;
	for(i=0; i<num; i++){
		printf("Alumno %d:\n",i+1);
			mostrarUnRegistro(*(estudiantesRef[i]));
		
	}
}

int liberarVectorRegistrosRef(Estudiante **estudiantesRef , int num){
	int i;
	if(estudiantesRef==NULL){
		printf("Error en la liberación de memoria\n\n");
		return -1;
	}
	for(i=0;i<num;i++){
		free(estudiantesRef[i]);
	}
	free(estudiantesRef);
	printf("\nLiberado el vector con éxito\n");
	return 0;
}


