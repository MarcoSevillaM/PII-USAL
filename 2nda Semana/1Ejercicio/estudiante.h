//Marco Sevilla Martín
//id00780760@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.

#ifndef __ESTUDIANTE_H 
#define __ESTUDIANTE_H  

#define NUM_ASIGNATURAS 10

typedef struct tipoEstudiante {
char apellidos [30];
char nombre [15];
float calificaciones[NUM_ASIGNATURAS];
} Estudiante;

Estudiante *crearVectorRegistros(int num, int *codError);
int cargarRegistrosAleatorios(Estudiante * estudiantes , int num);
Estudiante **crearVectorRegistrosRef(int num, int *codError);

int liberarVectorRegistrosRef(Estudiante **estudiantesRef , int num);
int cargarRegistrosAleatoriosRef(Estudiante **estudiantesRef , int num);
int cargarUnRegistroAleatorio(Estudiante * unEstudiante);
void mostrarUnRegistro(Estudiante unEstudiante);
void mostrarRegistrosRef(Estudiante ** estudiantesRef , int num);
void mostrarRegistros(Estudiante * estudiantes , int num);
///////////
Estudiante * pasarRegistrosAVector(Estudiante ** estudiantesRef, int num, int *codError);

#endif