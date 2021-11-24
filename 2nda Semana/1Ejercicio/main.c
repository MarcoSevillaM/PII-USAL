//Marco Sevilla Martín
//id00780760@usal.es
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
	int numEstudiantes, errNum;
	
	srandom(time(NULL));
	
	printf("\nNúmero de estudiantes: ");
	scanf("%d%*c", &numEstudiantes);
	printf("\nEl tamaño de un registro es: %ld\n",sizeof(Estudiante));
	
	
	regEstudiantes = crearVectorRegistros(numEstudiantes , &errNum);
	if (!cargarRegistrosAleatorios(regEstudiantes , numEstudiantes)) {
		mostrarRegistros(regEstudiantes , numEstudiantes); }
	regEstudiantesRef = crearVectorRegistrosRef(numEstudiantes , &errNum);
	
	if(!cargarRegistrosAleatoriosRef(regEstudiantesRef , numEstudiantes)){
		mostrarRegistrosRef(regEstudiantesRef , numEstudiantes); 
	}
	free(regEstudiantes);
	regEstudiantes = NULL;
	if (!liberarVectorRegistrosRef(regEstudiantesRef , numEstudiantes))
		regEstudiantesRef = NULL;
	
	
	
return 0;
 }
 
 
 
 
 
 
 
 
 