//Marco Sevilla Martín
//id00780760@usal.es
//Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.
//
//2.2
#ifndef FUNCIONES_H
#define FUNCIONES_H

#define COLS    25

typedef float * floatRef;
typedef int * intRef;
typedef char * charRef;

typedef struct matInt {
	int (*m)[COLS];
	int numFil, numCol;
} matInt;

typedef struct matFloat {
	float (*m)[COLS];
	int numFil, numCol;
} matFloat;

typedef matInt* matIntRef;
typedef matFloat * matFloatRef;

matFloatRef crearMatFloat(int numFil, int numCol, intRef errNum);
matIntRef crearMatInt(int numFil, int numCol, intRef errNum);

int liberarMatInt(matIntRef mat);
int liberarMatFloat(matFloatRef mat);

int leerMatFloat(matFloatRef m, charRef c);
int leerMatInt(matIntRef m, charRef c);


int mostrarMatFloat(matFloatRef m, charRef c);
int mostrarMatInt(matIntRef m, charRef c);


matFloatRef sumarMatFloat(matFloatRef a, matFloatRef b, intRef errNum);
matIntRef sumarMatInt(matIntRef a, matIntRef b, intRef errNum);

matFloatRef multiplicarMatFloat(matFloatRef a, matFloatRef b, intRef errNum);
matIntRef multiplicarMatInt(matIntRef a, matIntRef b, intRef errNum);

float *obtenerColumnaMaxMatFloat(matFloatRef mat, intRef errNum);
int *obtenerColumnaMaxMatInt(matIntRef mat, intRef errNum);
void mostrarVectorFloat(floatRef mat, int tam);
void mostrarVectorInt(intRef mat, int tam);

#endif
