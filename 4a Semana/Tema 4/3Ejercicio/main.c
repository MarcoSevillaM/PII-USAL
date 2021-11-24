
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	
	typedef int tipoInfo;
	typedef struct tipoNodo{
		tipoInfo info;
		struct tipoNodo *sig;
	}tipoNodo;
	
	srandom(time(NULL));
	tipoNodo *listaEnlazada, *indice, *nuevo, *borrar, *anterior;
	listaEnlazada = indice = nuevo = NULL;
	tipoInfo i, elem;
	
	printf("\nElementos de la lista:\n");
	scanf("%d",&elem);
	//Creación de listaEnlazada
	for(i=0;i<elem; i++){
		nuevo= malloc(sizeof(tipoNodo));
		if(nuevo!= NULL){
			nuevo->info = random()%10;
			nuevo->sig= NULL;
			if(listaEnlazada==NULL) 
				listaEnlazada= nuevo;
			else indice->sig=nuevo;
			indice=nuevo;
		}
		else{
			while(listaEnlazada!= NULL){
				borrar = listaEnlazada;
				listaEnlazada= listaEnlazada->sig;
				free(borrar);
			}
			break;
		}
	}
	//Presentar
	indice= listaEnlazada;
	i=0;
	while(indice != NULL){
		printf("\nPosición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	
	
	//Insertar un valo en una posición elegida por el usuario
	tipoInfo posicion, cont=0;
	printf("\nIntroduce la posición donde desee introducir el valor:\n");
	scanf("%d",&posicion);
	
	nuevo= malloc(sizeof(tipoNodo));
	if(nuevo != NULL){
		nuevo->info= random()%10;
		nuevo->sig = NULL;
		if(listaEnlazada == NULL){
			nuevo->sig =listaEnlazada;
			listaEnlazada= nuevo;
		}
		else{
			indice = listaEnlazada;
			while (indice != NULL && posicion != cont){
				anterior = indice;
				indice = indice->sig;
				++cont;
			}
			nuevo->sig= indice;
			anterior->sig= nuevo;
		}
	}
	//Presentar nueva lista
	indice= listaEnlazada;
	i=0;
	while(indice != NULL){
		printf("\nPosición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	//Liberar lista
	borrar=listaEnlazada;
	while(listaEnlazada!=NULL){
		borrar=listaEnlazada;
		listaEnlazada=listaEnlazada->sig;
		free(borrar);
	}
	
	return 0;
}





