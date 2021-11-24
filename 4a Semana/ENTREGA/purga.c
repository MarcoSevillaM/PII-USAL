//
// main.c
// listasEnlazadas Entrega
//Ejercicio 2
// "Eliminar o purgar todos los valores repetidos"
//
// Created by Marco Sevilla Martín on 21/05/2020
//  Copyright (c) 2020 Marco Sevilla Martín. All rights reserved.
//marcosevillam@usal.es

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 30

int main (){
	typedef struct tipoNodo{
		int info;
		struct tipoNodo *sig;
	}tipoNodo;
	
	int i;
	tipoNodo *listaEnlazada, *indice, *nuevo, *borrar, *anterior;
	listaEnlazada= indice= nuevo= NULL;
	srandom(time(NULL));
	
	//Creación de la lista
	for(i=0;i<NUM;i++){
		nuevo= malloc(sizeof(tipoNodo));
		if(nuevo!=NULL){
			nuevo->info= random()%100;
			nuevo->sig=NULL;
			if(listaEnlazada==NULL){
				listaEnlazada= nuevo;
			}
			else{
				indice->sig=nuevo;
			}
			indice=nuevo;
		}
		else
			while(listaEnlazada!=NULL){
				borrar=listaEnlazada;
				listaEnlazada=listaEnlazada->sig;
				free(borrar);
			}
	}
	//Presentar la lista
	indice=listaEnlazada;
	i=1;
	printf("\tLista Enlazada:\n");
	while(indice!=NULL){
		printf("Elemento %d: %d\n", i++, indice->info);
		indice=indice->sig;
	}
	
	//Ordenar lista
	indice=listaEnlazada; 
	int guarda;
	for(i=0;i<NUM;i++){
		while(indice->sig!= NULL){
			if(indice->info > indice->sig->info){
			guarda = indice->info;
			indice->info= indice->sig->info;
			indice->sig->info=guarda;
			}
		indice=indice->sig;
		}
		indice=listaEnlazada;
	}
  //Lista ordenada
		printf("\n\tLista Ordenada:\n");
	indice=listaEnlazada;
	i=1;
	while(indice!=NULL){
		printf("Elemento %d: %d\n", i++, indice->info);
		indice=indice->sig;
	}
	
	//Purgar bien
	tipoNodo *aux;
	indice=listaEnlazada;
	borrar= NULL;
	while(indice!=NULL){
		anterior= indice;	
		aux=indice->sig;
		while(aux!=NULL){
			if(indice->info==aux->info){
				anterior->sig=aux->sig;	
				borrar=aux;
				free(borrar);
				aux = anterior->sig;
				
			}
			else{
				anterior = aux;
				aux=aux->sig;
			}
			
		}
		indice=indice->sig;
	}
	
		//Presentar la lista purgada
		indice=listaEnlazada;
		i=1;
		printf("\n\tLista Purgada:\n");
		while(indice!=NULL){
			printf("Elemento %d: %d\n", i++, indice->info);
			indice=indice->sig;
		}
		//Borrar
		indice=listaEnlazada;
		while(indice!=NULL){
			borrar=indice;
			indice=indice->sig;
			free(borrar);
		}
		listaEnlazada=NULL;
	return 0;
}







