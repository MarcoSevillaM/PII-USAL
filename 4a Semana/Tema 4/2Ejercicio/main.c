//
// main.c
// listasEnlazadas
//Ejercicio 2
//
// Created by Marco Sevilla Martín on 23/05/2020
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
	
	tipoInfo elem, i, cont=0;
	tipoNodo * listaEnlazada, *nuevo, *borrar;
	listaEnlazada = nuevo =NULL;
	tipoNodo * indice=NULL;
	srandom(time(NULL));
	printf("\nIntroduce el número de nodos de la lista enlazada:");
	scanf("%d", &elem);
	
	for(i=0;i<elem;i++){
		if(elem<1) {printf("Número incorrecto"); break;}
		nuevo = malloc(sizeof(tipoNodo));
		if(nuevo!= NULL){
			nuevo->info= random()%10;
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
			break;
		}
	}
	
	//Presentación
	indice = listaEnlazada;
	i=0;
	while(indice != NULL){
		printf("\nPosición: %d -> contenido: %d\n", i++,indice->info);
		indice = indice->sig;
	}
	//Contar nº de nodos
	indice = listaEnlazada;
	cont=0;
	while(indice!=NULL){
		indice= indice->sig;
		cont++;
	}
	printf("\nHay %d nodos en la lista\n", cont);
	//Liberación
	if(listaEnlazada!=NULL){
		printf("\nLiberación...");
		while (listaEnlazada!=NULL){
			borrar=listaEnlazada;
			listaEnlazada = listaEnlazada->sig;
			free(borrar);
		}
	printf("efectuada.\n\n");
	}
	else
		printf("\nNo hay lista enlazada\n\n");
	
	return 0;
}