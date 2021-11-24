//Marco Sevilla Martín
//id00780760@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <strings.h> 
#include <time.h> 
#include "estudiante.h"

int cargarUnRegistroAleatorio(Estudiante * unEstudiante)
{
	
	static char apellidos [][15] = {"ALONSO","ALVAREZ","ARBESU", "DOMINGUEZ","FERNANDEZ","FLORIANO", "GONZALEZ","GOMEZ", "GUTIERREZ","MARTIN", "MORO", "PEREZ","TURRION","ZAMBRANO"};
	static char nombres [][15] = {"ALVARO","ARSENIO","DOMINGO", "FELIPE","FATIMA","FABIAN", "GONZALO","PEDRO","PATRICIA", "TOMAS", "ZOILO"};
	int numApellidos = sizeof(apellidos)/15; 
	int numNombres = sizeof(nombres)/15;
	int i;
	if (unEstudiante == NULL) {
	#ifdef DEBUG
		fprintf(stderr , "Error: registro no válido!\n");
	#endif
		return -1;

}
	sprintf(unEstudiante ->apellidos ,"%s %s",
		apellidos[random() % numApellidos],
		apellidos[random() % numApellidos]); 
	sprintf(unEstudiante->nombre,"%s",nombres[random() % numNombres]);
		for (i = 0; i < NUM_ASIGNATURAS; i++){
			unEstudiante->calificaciones[i] = (random() % 100 + 1)/10.0f;
	}
return 0;
}