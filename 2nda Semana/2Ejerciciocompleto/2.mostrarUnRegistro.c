//Marco Sevilla Martín
//marcosevillam@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <strings.h> 
#include <time.h> 
#include "estudiante.h"


void mostrarUnRegistro(Estudiante unEstudiante)
{
	int i;
	float media , suma;
	printf("%s, %s\n", unEstudiante.apellidos, unEstudiante.nombre);
	suma = 0.0f;
	for (i = 0; i < NUM_ASIGNATURAS; i++){
		printf("%3.1f\t", unEstudiante.calificaciones[i]);
		suma += unEstudiante.calificaciones[i]; 
	}
media = suma/NUM_ASIGNATURAS;
printf("\nCalificación media: %3.2f\n\n", media); }