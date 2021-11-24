//Marco Sevilla Martín 
//Grupo PB4 Programación II
//id00780760@usal.es



#include <stdio.h>
#include "vectorDinamica.h"
#include "vectorAux.h"
#define N 5

int main(void) {
	int vx[N] = {0};
	int i, errNum;
	int *ptr;
	
	puts("VECTOR CREADO CON MALLOC");
	puts("========================");
	puts("");
	puts("Estudio de las posiciones de memoria donde se almacenan los datos estáticos");
	puts("y las variables generadas con reserva de memoria dinámica.");
	puts("");
	if ((ptr = creaVectorInt(N, &errNum)) == NULL)
		return errNum;
	else {
		puts ("Variables estáticas:");
		puts ("		int vx[N] = {0};	N=5");
		puts ("		int i;				   ");
		puts ("		int *ptr;			   ");
		puts ("							   ");
		printf("Dirección último elemento de vx: %p \n", vx+(N-1));
		printf("Dirección comienzo de vx.......: %p \n", vx);
		printf("Dirección de i.................: %p \n", &i);
		printf("Dirección de ptr...............: %p \n", &ptr);
		
		printf("Dirección último elemento vector dinámico ptr: %p \n", ptr+(N-1));
		printf("Dirección comienzo vector dinámico ptr.......: %p \n", ptr);
		
		printf("\n\n");
		printf("Carga valores aleatorios:\n");
		
		if (!cargarValoresAleatorios(ptr, N, 10, 100))
			mostrarValores(ptr, N);
		if (!cargarValoresAleatorios(vx, N, 10, 100))
			mostrarValores(vx, N);
		
		printf("\n\n");
		printf("Carga valores teclado:\n");
		if (!cargarValoresTeclado(ptr, N))
			mostrarValores(ptr, N);
		if (!cargarValoresTeclado(vx, N))
			mostrarValores(vx, N);
		free(ptr);
	}
	
	return 0;
}