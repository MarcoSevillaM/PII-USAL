//
// main, nomrbe: unir.c
// listasEnlazadas Entrega
//Ejercicio 1
// "Fusionar dos listas enlazadas manteniendo el orden ascendente"
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
	tipoNodo * listaEnlazada1, * listaEnlazada2, *nuevo, *borrar, *anterior;
	listaEnlazada1 = listaEnlazada2 = nuevo =NULL;
	tipoNodo * indice=NULL;
	srandom(time(NULL));
	
//Creación listaEnlazada1
	for(i=0;i<10;i++){
		nuevo = malloc(sizeof(tipoNodo));
		if(nuevo!= NULL){
			nuevo->info= random()%100;
			nuevo->sig = NULL;
			if(listaEnlazada1 ==NULL)
				listaEnlazada1= nuevo;
			else
				indice->sig= nuevo;
			indice = nuevo;
		}
		else{
			while (listaEnlazada1 != NULL){
				borrar= listaEnlazada1;
				listaEnlazada1= listaEnlazada1->sig;
				free(borrar);
			}
			break;
		}
	}
	
//Creación listaEnlazada2
	nuevo=NULL;
	for(i=0;i<10;i++){
		nuevo = malloc(sizeof(tipoNodo));
		if(nuevo!= NULL){
			nuevo->info= random()%10;
			nuevo->sig = NULL;
			if(listaEnlazada2 ==NULL)
				listaEnlazada2 = nuevo;
			else
				indice->sig= nuevo;
			indice = nuevo;
		}
		else{
			while (listaEnlazada2 != NULL){
				borrar= listaEnlazada2;
				listaEnlazada2 = listaEnlazada2->sig;
				free(borrar);
			}
			break;
		}
	}
	
//Recorrido listaEnlazada1
	printf("\n\tRecorrido listaEnlazada1\n");
	indice = listaEnlazada1;
	i=1;
	while(indice != NULL){
		printf("Posición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	puts("");
	
//Recorrido listaEnlazada2
	printf("\n\tRecorrido listaEnlazada2\n");
	indice = listaEnlazada2;
	i=1;
	while(indice != NULL){
		printf("Posición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
//Ordenar listaEnlazada1
	tipoInfo var;
	indice=listaEnlazada1;
	for(i=0;i<9;i++){
		while(indice->sig!= NULL){
			if(indice->info > indice->sig->info){
			var = indice->info;
			indice->info= indice->sig->info;
			indice->sig->info=var;
			}
		indice=indice->sig;
		}
		indice=listaEnlazada1;
	}
//Ordenar listaEnlazada2
	indice=listaEnlazada2;
	for(i=0;i<9;i++){
		while(indice->sig!= NULL){
			if(indice->info > indice->sig->info){
			var = indice->info;
			indice->info= indice->sig->info;
			indice->sig->info=var;
			}
		indice=indice->sig;
		}
		indice=listaEnlazada2;
	}
//Recorrido listaEnlazada1 ordenado
	printf("\n\tRecorrido listaEnlazada1 ordenado\n");
	indice = listaEnlazada1;
	i=1;
	while(indice != NULL){
		printf("Posición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	puts("");
	
	
//Recorrido listaEnlazada2 ordenado
	printf("\n\tRecorrido listaEnlazada2 ordenado\n");
	indice = listaEnlazada2;
	i=1;
	while(indice != NULL){
		printf("Posición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	puts("");
	//Pasar listaEnlazada1 y listaEnlazada2 a listaResultado
	tipoNodo *listaResultado, *aux1, *aux2, *indiceresul;
	aux1=listaEnlazada1;
	aux2=listaEnlazada2;
	if(aux1->info > aux2->info){
		listaResultado=aux2;
		listaEnlazada2=aux2->sig;
		aux2=listaEnlazada2;
	}
	else{
		listaResultado=aux1;
		listaEnlazada1=aux1->sig;
		aux1=listaEnlazada1;
	}
	indiceresul=listaResultado;
	
	while(aux1!=NULL && aux2!=NULL){
		if(aux1->info > aux2->info){
			
			listaEnlazada2= aux2->sig;
			aux2->sig=NULL;
			indiceresul->sig=aux2;
			aux2= listaEnlazada2;
		}
		else{
			listaEnlazada1=aux1->sig;
			aux1->sig=NULL;
			indiceresul->sig=aux1;
			aux1= listaEnlazada1;
		}
		indiceresul=indiceresul->sig;
	}
	
	if(listaEnlazada1==NULL){
		indiceresul->sig=listaEnlazada2;
		listaEnlazada2=NULL;
	}
	else if(listaEnlazada2==NULL){
		indiceresul->sig=listaEnlazada1;
		listaEnlazada1=NULL;
	}
	//Otra manera
	
	/*tipoNodo *listaResultado, *aux;
	listaResultado=NULL;
	indice=listaResultado;
	while(listaEnlazada1!=NULL && listaEnlazada2!=NULL){
		if(listaEnlazada1->info < listaEnlazada2->info){
			aux=malloc(sizeof(tipoNodo));
			aux=listaEnlazada1;
			free(listaEnlazada1);
			listaEnlazada1=listaEnlazada1->sig;
			if(listaResultado==NULL){
				listaResultado=aux;
			}
			else{
				indice->sig=aux;;
			}
			indice = aux;
			indice->sig= NULL;	
		}
		else if (listaEnlazada1->info > listaEnlazada2->info){
			aux=malloc(sizeof(tipoNodo));
			aux=listaEnlazada2;
			free(listaEnlazada2);
			listaEnlazada2=listaEnlazada2->sig;
			if(listaResultado==NULL){
				listaResultado=aux;
			}
			else{
				indice->sig=aux;;
			}
			indice = aux;
			indice->sig= NULL;	
		}
	}
	if(listaEnlazada1==NULL){
		indice->sig=listaEnlazada2->sig;
	}
	else if(listaEnlazada2==NULL){
		indice->sig= listaEnlazada1->sig;
	}*/
	
	
//Recorrido listaResultado ordenado
	printf("\n\tRecorrido listaResultado ordenado\n");
	indice = listaResultado;
	i=1;
	while(indice != NULL){
		printf("Posición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	puts("");
	//Liberar listaResultado
	printf("Liberación de lista...");
	indice=listaResultado;
	while(indice!=NULL){
		borrar=indice;
		free(borrar);
	}
	free(listaResultado);
	listaResultado=NULL;
	printf("realizada.");
	
	
	
	
	return 0;
}

