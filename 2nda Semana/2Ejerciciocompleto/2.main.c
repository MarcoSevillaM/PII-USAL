//Marco Sevilla Martín
//marcosevillam@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <strings.h> 
#include <time.h> 
#include "estudiante.h"


int main(void)
{
	Estudiante *regEstudiantes; 
	Estudiante **regEstudiantesRef; 
	int numEstudiantes, errNum, i;
	
	srandom(time(NULL));
	
	printf("\nNúmero de estudiantes: ");
	scanf("%d%*c", &numEstudiantes);
	printf("\nEl tamaño de un registro es: %ld\n",sizeof(Estudiante));
	
	//Ejercicio1
		//Crear, cargar y mostrar regEstudiantes
	regEstudiantes = crearVectorRegistros(numEstudiantes , &errNum);
	if (!cargarRegistrosAleatorios(regEstudiantes , numEstudiantes)) {
		mostrarRegistros(regEstudiantes , numEstudiantes); }
		//Crear, cargar y mostrar regEstudiantesRef
	regEstudiantesRef = crearVectorRegistrosRef(numEstudiantes , &errNum);
	if(!cargarRegistrosAleatoriosRef(regEstudiantesRef , numEstudiantes)){
		mostrarRegistrosRef(regEstudiantesRef , numEstudiantes); 
	}
	//Ejercicio2
	Estudiante *nuevoVectorCopia;
		//Crea un nuevo registro y copia el anterior
	nuevoVectorCopia= pasarRegistrosAVector(regEstudiantesRef,numEstudiantes, &errNum);
		//Muestra el vector copiado
	mostrarRegistros(nuevoVectorCopia, numEstudiantes);
	
	Estudiante **VectorARegistro;
		//Crear un nuevo puntero a un vector de registros y lo copia 
	VectorARegistro=pasarVectorARegistros(regEstudiantes, numEstudiantes, &errNum);
		//Muestra el vectro de un puntero a puntero de registros.
	mostrarRegistrosRef(VectorARegistro, numEstudiantes);
	
	//Ejercicio3
		//Crea el vector promedio de regEstudiantes
	float *media;
	media=devolverVectorPromedios(regEstudiantes,numEstudiantes);
		//Presenta el vector promedio regEstudiantes
	printf("El vector de las medias de regEstudiantes es:\n ");
	for (i=0;i<numEstudiantes;i++)
		printf("%3.2f\t",media[i]);
	
		//Crea el vector promedio de regEstudiantesRef
	float *mediaRef;
	mediaRef=devolverVectorPromediosRef( regEstudiantesRef, numEstudiantes);
		//Presenta el vector promedio regEstudiantesRef
	printf("\nEl vector de las medias de regEstudiantesRef es:\n ");
	for (i=0;i<numEstudiantes;i++)
		printf("%3.2f\t",mediaRef[i]);
	//Ejercicio4
	float min,max;
	Estudiante *vectorRang;
	Estudiante *vectorRangRef;
	printf("\nIntroduce la nota media minima:\n");
	scanf("%f",&min);
	printf("Introduce la nota media maxima:\n");
	scanf("%f",&max);
	vectorRang= devolverVectorRegistrosRango( regEstudiantes,numEstudiantes,
	 min, max, &errNum);
	vectorRangRef= devolverVectorRegistrosRangoRef(regEstudiantesRef, numEstudiantes,
	min, max, &errNum);
	

	//Liberación de memoria
	//1.1Libero *media
	free(media);
	media=NULL;
	//1.2Libero *mediaRef
	free(mediaRef);
	mediaRef=NULL;
	//2.Libero **VectorARegistro
	if (!liberarVectorRegistrosRef(VectorARegistro , numEstudiantes))
	VectorARegistro = NULL;
	
	//3.Libero *nuevoVectorCopia
	free(nuevoVectorCopia);
	nuevoVectorCopia=NULL;
	
	//4.Libero **regEstudiantesRef
	if (!liberarVectorRegistrosRef(regEstudiantesRef , numEstudiantes))
		regEstudiantesRef = NULL;
	
	//5.Libero *regEstudiantes
	free(regEstudiantes);
	regEstudiantes = NULL;
	
	//6.Libero *vectorRang
	free(vectorRang);
	vectorRang=NULL;
	
	if(media==NULL){
		if(mediaRef==NULL)
			if(VectorARegistro==NULL)
				if(nuevoVectorCopia==NULL)
					if(regEstudiantesRef==NULL)
						if(regEstudiantes==NULL)
							if(vectorRang==NULL)printf("\nVectores liberados correctamente\n");
	}
return 0;
 }
 
 
 
 
 
 
 
 
 