// Sergio Sanchez Garcia

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

typedef struct tipoNodo{
	int info;
	struct tipoNodo *sig;
} tipoNodo;

int main(void){
	tipoNodo *listaEnlazada1, *listaEnlazada2, *listaResultado;
	tipoNodo *indice, *nuevo, *anterior, *aBorrar, *aux;
	int i;
	
	srandom(time(NULL));
	listaEnlazada1 = listaEnlazada2 = listaResultado = NULL;
	
	//Creación de las listas
	for(i=0;i<TAM;i++){
		nuevo = malloc(sizeof(tipoNodo));
		if(nuevo != NULL){
			nuevo->info = random()%100;
			nuevo->sig = NULL;
			if(listaEnlazada1 == NULL || listaEnlazada1->info > nuevo->info){
				nuevo->sig = listaEnlazada1;
				listaEnlazada1 = nuevo;
			}
			else{
				indice = listaEnlazada1;
				anterior = NULL;
				while(indice != NULL && indice->info < nuevo->info){
					anterior = indice;
					indice = indice->sig;
				}
				nuevo->sig = indice;
				anterior->sig = nuevo;
			}
		}
		else{
			printf("\n\nError: lista 1 no creada.\n\n");
			while(listaEnlazada1 != NULL){
				aBorrar = listaEnlazada1;
				listaEnlazada1 = listaEnlazada1->sig;
				free(aBorrar);
			}
			break;
		}
	}
	
	for(i=0;i<TAM;i++){
		nuevo = malloc(sizeof(tipoNodo));
		if(nuevo != NULL){
			nuevo->info = rand()%100;
			nuevo->sig = NULL;
			if(listaEnlazada2 == NULL || listaEnlazada2->info > nuevo->info){
				nuevo->sig = listaEnlazada2;
				listaEnlazada2 = nuevo;
			}
			else{
				indice = listaEnlazada2;
				anterior = NULL;
				while(indice != NULL && indice->info < nuevo->info){
					anterior = indice;
					indice = indice->sig;
				}
				nuevo->sig = indice;
				anterior->sig = nuevo;
			}
		}
		else{
			printf("\n\nError: lista 2 no creada.\n\n");
			while(listaEnlazada2 != NULL){
				aBorrar = listaEnlazada2;
				listaEnlazada2 = listaEnlazada2->sig;
				free(aBorrar);
			}
			break;
		}
	}
	
	//Visualización de las listas
	printf("\n\n----------Lista 1----------\n");
	indice = listaEnlazada1;
	i = 1;
	while(indice != NULL){
		printf("Posición %d: %d\n", i++, indice->info);
		indice = indice->sig;
	}
	
	printf("\n\n----------Lista 2----------\n");
	indice = listaEnlazada2;
	i = 1;
	while(indice != NULL){
		printf("Posición %d: %d\n", i++, indice->info);
		indice = indice->sig;
	}
	
	//Fusión de las listas
	while(listaEnlazada1 != NULL && listaEnlazada2 != NULL){
		if(listaEnlazada1->info < listaEnlazada2->info){
			aux = listaEnlazada1;
			listaEnlazada1 = listaEnlazada1->sig;
			if(listaResultado == NULL){
				listaResultado = aux;
			}
			else{
				indice = listaResultado;
				while(indice->sig != NULL){
					indice = indice->sig;
				}
				indice->sig = aux;
			}
			aux->sig = NULL;
		}	
		else{
			aux = listaEnlazada2;
			listaEnlazada2 = listaEnlazada2->sig;
			if(listaResultado == NULL){
				listaResultado = aux;
			}
			else{
				indice = listaResultado;
				while(indice->sig != NULL){
					indice = indice->sig;
				}
				indice->sig = aux;
			}
			aux->sig = NULL;
		}		
	}
	if(listaEnlazada1 == NULL){
		indice = listaResultado;
		while(indice->sig != NULL){
			indice = indice->sig;
		}
		indice->sig = listaEnlazada2;
	}
	else{
		indice = listaResultado;
		while(indice->sig != NULL){
			indice = indice->sig;
		}
		indice->sig = listaEnlazada1;
	}
	
	//Visualización de la listaResultado
	printf("\n\n----------Lista Resultado----------\n");
	indice = listaResultado;
	i = 1;
	while(indice != NULL){
		printf("Posición %d: %d\n", i++, indice->info);
		indice = indice->sig;
	}
	
	//Liberación final
	printf("\n\nLiberación de la memoria reservada...");
	while(listaResultado != NULL){
		aBorrar = listaResultado;
		listaResultado = listaResultado->sig;
		free(aBorrar);
	}
	printf("finalizada.\n\n");
}