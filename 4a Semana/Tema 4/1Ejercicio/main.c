//
// main.c
// listasEnlazadas
//Ejercicio 1
//
// Created by Marco Sevilla Martín on 21/05/2020
//  Copyright (c) 2020 Marco Sevilla Martín. All rights reserved.
//marcosevillam@usal.es

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	typedef int tipoInfo;
	
	typedef struct tipoNodo{
		tipoInfo info;
		struct tipoNodo *sig;
	} tipoNodo;
	
	tipoInfo elem, i;
	tipoNodo * listaEnlazada, *nuevo, *borrar;
	listaEnlazada = nuevo =NULL;
	tipoNodo * indice=NULL;
	srandom(time(NULL));
//1. Creación listaEnlazada
	for(i=0;i<9;i++){
		nuevo = malloc(sizeof(tipoNodo));
		if(nuevo!= NULL){
			nuevo->info= 2*i + 1;
			nuevo->sig = NULL;
			if(listaEnlazada ==NULL)
				listaEnlazada= nuevo;
			else
				indice->sig= nuevo;
			indice = nuevo;
		}
		else{
			while (listaEnlazada != NULL){
				borrar= listaEnlazada;
				listaEnlazada = listaEnlazada->sig;
				free(borrar);
			}
			break;
		}
		
	}
	tipoInfo a,b;
	printf("\nPrimer recorrido:\n");
	indice = listaEnlazada;
	i=0;
	while(indice != NULL){
		printf("\nPosición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	puts("");
	
//3.Liberación y recorrido
	//3.1 Liberar
	printf("Liberación...");
	while (listaEnlazada!=NULL){
		borrar=listaEnlazada;
		listaEnlazada = listaEnlazada->sig;
		free(borrar);
	}
	printf("efectuada.");
	//3.2 Recorrido
	printf("\n\n\nSegundo recorrido:\n");
	indice = listaEnlazada;
	i=0;
	while(indice != NULL){
		printf("\nPosición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	if(listaEnlazada==NULL) printf("La lista no tiene nodos");
	puts("");
	
//4. Creación de nueva lista enlazada e insertación en una posición, al pricipio y al final.
	//4.1 Creación
	for(i=0;i<9;i++){
		nuevo = malloc(sizeof(tipoNodo));
		if(nuevo!= NULL){
			nuevo->info= 2*i + 1;
			nuevo->sig = NULL;
			if(listaEnlazada ==NULL)
				listaEnlazada= nuevo;
			else
				indice->sig= nuevo;
			indice = nuevo;
		}
		else{
			borrar = listaEnlazada;
			while (listaEnlazada != NULL){
				borrar= listaEnlazada;
				listaEnlazada = listaEnlazada->sig;
				free(borrar);
			}
			printf("Error en la reserva");
			break;
			exit (-1);
		}	
	}
	
	//4.2 Intertar en una posición arbitraria
	tipoNodo *anterior;
	nuevo = malloc(sizeof(tipoNodo));
	if(nuevo != NULL){
		nuevo ->info = random()%100;
		nuevo ->sig = NULL;
		if(listaEnlazada == NULL || listaEnlazada ->info > nuevo->info){
			nuevo->sig = listaEnlazada;
			listaEnlazada = nuevo;
		}
		else{
			anterior = NULL;
			indice = listaEnlazada;
			while(indice != NULL && indice->info < nuevo-> info){
				anterior = indice;
				indice = indice->sig;
			}
			nuevo->sig= indice;
			anterior->sig= nuevo;
		}
	}
	
	//4.3 Insertar al principio
	nuevo = malloc (sizeof (tipoNodo));
	if(nuevo != NULL){
		nuevo->info= 1000;
		nuevo->sig = listaEnlazada; 
		listaEnlazada = nuevo;
	}
	
	//4.4 Insertar al final
	nuevo = malloc(sizeof(tipoNodo));
	if(nuevo!= NULL){
		nuevo ->info = 25;
		nuevo ->sig= NULL;
		if(listaEnlazada ==NULL) listaEnlazada = nuevo;
		else{
			indice = listaEnlazada;
			while(indice->sig != NULL){
				indice = indice -> sig;
			}
			indice->sig = nuevo;
		}
	}
	printf("\nTercer recorrido:\n");
	indice = listaEnlazada;
	i=0;
	while(indice != NULL){
		printf("\nPosición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	puts("");
	
//5.Eliminar nodo al principio, al final y en una posición arbitraria.
	
	//5.1 Eliminal al principio
	borrar= listaEnlazada;
	listaEnlazada = borrar->sig;
	free(borrar);
	
	//5.2 Eliminar al final
	if(listaEnlazada != NULL){
		borrar = listaEnlazada;
		anterior= NULL;
		while(borrar->sig != NULL){
			anterior = borrar;
			borrar = borrar ->sig;
		}
		if(anterior == NULL) listaEnlazada = NULL;
		else anterior ->sig = NULL;
		free (borrar);
	}
	
	//5.3 Eliminar en una posición aleatoria
	//tipoInfo valor;
	//valor=9;
	if(listaEnlazada != NULL){
		anterior = NULL;
		borrar = listaEnlazada;
		while (borrar != NULL && borrar-> info != random()%10){
			anterior = borrar;
			borrar= borrar->sig;
		}
		if (borrar!= NULL){
			if(anterior ==NULL) listaEnlazada = borrar ->sig;
			else anterior->sig = borrar->sig;
			free(borrar);
		}
	}
	
	printf("\nCuarto recorrido:\n");
	indice = listaEnlazada;
	i=0;
	while(indice != NULL){
		printf("\nPosición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	puts("");
	
	//Liberación del programa
	printf("Liberación...");
	while (listaEnlazada!=NULL){
		borrar=listaEnlazada;
		listaEnlazada = listaEnlazada->sig;
		free(borrar);
	}
	printf("efectuada.");
	return 0;
}