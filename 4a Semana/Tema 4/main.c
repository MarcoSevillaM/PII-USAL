//Sergio Sánchez García
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo *sig;
} nodo;

int main(void){
	nodo *listaEnlazada = NULL;
	nodo *indice = NULL;
	nodo *nuevo = NULL;
	nodo *aBorrar = NULL;
	nodo *anterior = NULL;
	int i, numNodos, numNuevo;
	
	do{
		printf("Nodos: ");
		scanf("%d", &numNodos);
	}while(numNodos<=0);
	
	//1. Creación de la lista enlazada añadiendo nodos por el final
	for(i=0;i<numNodos;i++){
		nuevo = malloc(sizeof(nodo));
		if(nuevo != NULL){
			nuevo->dato = 2*i +1;
			nuevo->sig = NULL;
			if(listaEnlazada == NULL)
				listaEnlazada = nuevo;
			else
				indice->sig = nuevo;
			indice = nuevo;
		}
		else{
			printf("\n\nError: reserva de memoria incorrecta.\n\n");
			indice = listaEnlazada;
			while(indice != NULL){
				aBorrar = indice;
				indice = indice->sig;
				free(aBorrar);
			}
			listaEnlazada = NULL;
		}
	}
	
	//2. Recorrido de la lista enlazada
	printf("\n\nRecorrido de la lista\n");
	indice = listaEnlazada;
	while(indice != NULL){
		printf("%d, ", indice->dato);
		indice = indice->sig;
	}
	
	//3. Liberación de todos los nodos e intento de recorrerlos
	indice = listaEnlazada;
	aBorrar = NULL;
	while(indice != NULL){
		aBorrar = indice;
		indice = indice->sig;
		free(aBorrar);
	}
	listaEnlazada = NULL;
	
	indice = listaEnlazada;
	while(indice != NULL){
		printf("%d, ", indice->dato);
		indice = indice->sig;
	}
	
	//4. Creación del la lista enlazada de 9 nodos, inserción de un nodo en una posición ordenada, inserción de un nodo al principio y final de la lista y recorrido
	indice = listaEnlazada = nuevo = NULL;
	for(i=0;i<9;i++){
		nuevo = malloc(sizeof(nodo));
			if(nuevo != NULL){
				nuevo->dato = i*2+1;
				nuevo->sig = NULL;
				if(listaEnlazada == NULL)
					listaEnlazada = nuevo;
				else
					indice->sig = nuevo;
				indice = nuevo;
			}
			else{
				printf("\n\nError: reserva de memoria incorrecta.\n\n");
				indice = listaEnlazada;
					while(indice != NULL){
						aBorrar = indice;
						indice = indice->sig;
						free(aBorrar);
					}
					listaEnlazada = NULL;
			}
	}
	
	printf("\n\nValor del nuevo nodo: ");
	scanf("%d", &numNuevo);
	nuevo = malloc(sizeof(nodo));
	if(nuevo != NULL){
		nuevo->dato = numNuevo;
		nuevo->sig = NULL;
		if(listaEnlazada == NULL || nuevo->dato < listaEnlazada->dato){
			nuevo->sig = listaEnlazada;
			listaEnlazada = nuevo;
		}
		else{
			indice = listaEnlazada;
			while(indice != NULL || indice->dato < nuevo->dato){
				anterior = indice;
				indice = indice->sig;
			}
			nuevo->sig = indice;
			anterior->sig = nuevo;
		}
	}
	else{
		printf("\n\nError: fallo en la reserva del nuevo nodo.\n\n");
		free(nuevo);
		nuevo = NULL;
	}
	
	printf("\n\nValor del nodo a insertar en el inicio: ");
	scanf("%d", &numNuevo);
	nuevo = malloc(sizeof(nodo));
	if(nuevo != NULL){
		nuevo->dato = numNuevo;
		nuevo->sig = listaEnlazada;
		listaEnlazada = nuevo;
	}
	else{
		printf("\n\nError: fallo en la reserva del nuevo nodo.\n\n");
		free(nuevo);
		nuevo = NULL;
	}
	
	printf("\n\nValor del nodo a insertar en el final: ");
	scanf("%d", &numNuevo);
	nuevo = malloc(sizeof(nodo));
	if(nuevo != NULL){
		nuevo->dato = numNuevo;
		nuevo->sig = NULL;
		if(listaEnlazada == NULL)
			listaEnlazada = nuevo;
		else{
			indice = listaEnlazada;
			while(indice->sig != NULL){
				indice = indice-> sig;
			}
			indice->sig = nuevo;
		}
	}
	else{
		printf("\n\nError: fallo en la reserva del nuevo nodo.\n\n");
		free(nuevo);
		nuevo = NULL;
	}
	
	printf("\n\nRecorrido de la lista\n");
	indice = listaEnlazada;
	while(indice != NULL){
		printf("%d, ", indice->dato);
		indice = indice->sig;
	}
	
	//5. Eliminación del primer nodo de la lista, del último y el de una posición arbitraria, recorrido y liberación de la lista
	if(listaEnlazada != NULL){
		aBorrar = listaEnlazada;
		listaEnlazada = listaEnlazada->sig;
		free(aBorrar);
	}
	
	if(listaEnlazada != NULL){
		aBorrar = listaEnlazada;
		anterior = NULL;
		while(aBorrar->sig != NULL){
			anterior = aBorrar;
			aBorrar = aBorrar->sig;
		}
		if(anterior == NULL)
			listaEnlazada = NULL;
		else
			anterior->sig = NULL;
		free(aBorrar);
	}
	
	printf("\n\nValor del nodo a borrar: ");
	scanf("%d", &numNuevo);
	if(listaEnlazada != NULL){
		aBorrar = listaEnlazada;
		anterior = NULL;
		while(aBorrar != NULL || aBorrar->dato == numNuevo){
			anterior = aBorrar;
			aBorrar = aBorrar->sig;
		}
		if(aBorrar != NULL){
			if(anterior == NULL){
				listaEnlazada = aBorrar->sig;
			}
			else{
				anterior->sig = aBorrar->sig;
			}
			free(aBorrar);
		}
		else
			printf("\n\nEl valor no corresponde con el dato de ningún nodo.\n\n");
	}
	
	printf("\n\nRecorrido de la lista\n");
	indice = listaEnlazada;
	while(indice != NULL){
		printf("%d, ", indice->dato);
		indice = indice->sig;
	}
	
	indice = listaEnlazada;
	while(indice != NULL){
		aBorrar = indice;
		indice = indice->sig;
		free(aBorrar);
	}
	listaEnlazada = NULL;
}