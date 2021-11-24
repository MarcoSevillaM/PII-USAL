//Marco Sevilla Martín
//marcosevillam@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.
#include <stdio.h>
#include <stdlib.h>
#include "estudiante.h" 

//1Ejercicio
Estudiante *crearVectorRegistros(int num, int *codError){
	Estudiante *ptr=NULL;
	if(num<=0){
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

	ptr=(Estudiante **)malloc(num*sizeof(Estudiante*));
	if(ptr==NULL){
		*codError=-2;
		return NULL;
	}
	for (i=0;i<num;i++){
		ptr[i]=(Estudiante *)malloc(num* sizeof(Estudiante));
		if(ptr[i]==NULL){
			printf("Error en la invocacion a la función\n");
			*codError=-3;
			for(j=i;i>=0;i--){
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
	return 0;
}
//2Ejercicio
Estudiante * pasarRegistrosAVector(Estudiante ** estudiantesRef, int num, int *codError){
	
	Estudiante *RegistroAVector;
	int i;
	if(estudiantesRef==NULL){
		printf("El parámetro es un puntero a NULL\n");
		*codError=-10;
	}
	RegistroAVector=crearVectorRegistros (num, codError);
	for(i=0;i<num;i++){
		(RegistroAVector[i])= *(estudiantesRef[i]);
	}
	*codError=0;
	return RegistroAVector;
}


Estudiante ** pasarVectorARegistros(Estudiante * estudiantes, int num, int *codError){
	Estudiante **VectorARegistro;
	int i;
	if(estudiantes==NULL){
		printf("Error en la función 'pasarVectoARegistros'");
	*codError=-10;}
	VectorARegistro=crearVectorRegistrosRef(num, codError);
	for(i=0; i<num;i++){
		*(VectorARegistro[i])=estudiantes[i];
	}
	
	return VectorARegistro;
}

//3ejercicio
float * devolverVectorPromedios(Estudiante * estudiantes, int num){
	float *media;
	int i,j;
	float suma;
	if(estudiantes==NULL)exit(-1);
	media=(float *)malloc(num*sizeof(float));
		if(media==NULL)exit(-1);
		
		else{
			for(i=0;i<num;i++){
				suma=0;
				for (j=0;j<NUM_ASIGNATURAS;j++)
					suma+=estudiantes[i].calificaciones[j];
			media[i]=suma/NUM_ASIGNATURAS;
			}
			return media;
		}
}

float * devolverVectorPromediosRef(Estudiante ** estudiantesRef, int num){
	float *media;
	int i, j;
	float suma;
	if(estudiantesRef==NULL)exit(-1);
	media=(float *)malloc(num*sizeof(float));
		if(media==NULL)exit(-1);
		
		else{
			for(i=0;i<num;i++){
				suma=0;
				for (j=0;j<NUM_ASIGNATURAS;j++)
					suma+=estudiantesRef[i]->calificaciones[j];
			media[i]=suma/NUM_ASIGNATURAS;
			}
	return media;
	}
}
//4Ejercicio

Estudiante * devolverVectorRegistrosRango(Estudiante * estudiantes, int num,
 float bajo, float alto, int *codError){
	 Estudiante *VectorRang=NULL;
	 float *VectorPromedio=NULL;
	 int i=0,cont=0,j=0;
	 if(estudiantes==NULL){
		 *codError=-10;
		 return VectorRang;
	 }
	 else{
	 	if(bajo<0||alto>10)
		{
			 bajo=(bajo<=0||bajo>=10)  ? 0 :bajo;
			 alto=(alto>=10||alto<=0) ? 10:alto;
		 }
	 	VectorPromedio=devolverVectorPromedios(estudiantes,num);
	 	for(i=0;i<num;i++){
			 if(bajo<=VectorPromedio[i]&&alto>=VectorPromedio[i])
			 cont++;
		 }
		 if (cont==0){
			 printf("No hay ningún alumno comprendido entre las notas de regEstudiantes");
			 return NULL;
		 }
		 VectorRang=crearVectorRegistros(cont, codError);
		 for(i=0;i<num;i++)
	 	{
			  if(bajo<=VectorPromedio[i]&&alto>VectorPromedio[i]){
			  VectorRang[j]= estudiantes[i];
			  j++;}
		  }
	 mostrarRegistros(VectorRang, cont);
	  }
	 return VectorRang;
 }
 
 Estudiante * devolverVectorRegistrosRangoRef(Estudiante ** estudiantesRef, int num,
 float bajo, float alto, int *codError){
	 Estudiante *VectorRang=NULL;
	 float *VectorPromedio=NULL;
	 int i=0,cont=0,j=0;
	 if(estudiantesRef==NULL){
		 *codError=-10;
		 return VectorRang;
	 }
	 else{
	 	if(bajo<0||alto>10)
		{
			 bajo=(bajo<=0||bajo>=10)  ? 0 :bajo;
			 alto=(alto>=10||alto<=0) ? 10:alto;
		 }
	 	VectorPromedio=devolverVectorPromediosRef(estudiantesRef,num);
	 	for(i=0;i<num;i++){
			 if(bajo<=VectorPromedio[i]&&alto>=VectorPromedio[i])
			 cont++;
		 }
		 if (cont==0){
			 printf("No hay ningún alumno comprendido entre las notas de regEstudiantesRef");
			 return NULL;
		 }
		 VectorRang=crearVectorRegistros(cont, codError);
		 for(i=0;i<num;i++)
	 	{
			  if(bajo<=VectorPromedio[i]&&alto>VectorPromedio[i]){
			  VectorRang[j]= *(estudiantesRef[i]);
			  j++;}
		  }
	 mostrarRegistros(VectorRang, cont);
	  }
	 return VectorRang;
	
 }
 

