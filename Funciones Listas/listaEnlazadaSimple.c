//
//  listaEnlazadaSimple.c
//  listaEnlazadaSimple
// "Funciones de listas enlazadas"
//
// Created by Marco Sevilla Martín on 25/05/2020
//  Copyright (c) 2020 Marco Sevilla Martín. All rights reserved.
//marcosevillam@usal.es

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazadaSimple.h"

int crearVacia(ListaEnlazadaRef raiz)
{
	*raiz=NULL;
	return 0;
}

int estaVacia(ListaEnlazada raiz)
{
	return (raiz==NULL);
}

tipoNodoRef creaNodo(tipoInfoRef info) {
	tipoNodoRef nuevo;
	if(NULL==(nuevo=malloc(sizeof(tipoNodo)))){
#ifdef DEBUG
		fprintf (stderr, "Error: no reserva memoria!\n");
#endif
	}
	else{
		nuevo->info = *info;
		nuevo->sig = NULL;
	}
	return nuevo;
}

int insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef nuevo, aux;
	
	if(NULL==(nuevo = creaNodo(info)))
		return -1;
	else{
		if(estaVacia(*raiz))
			*raiz=nuevo;
		else if(pos == NULL){ //Si la posición introducida no es válida se introduce al final
			aux = *raiz;
			while (aux->sig != NULL)
				aux = aux->sig;
			aux->sig = nuevo;
		}
		else {
			aux = *raiz;
			while(aux != NULL && aux != pos)
				aux = aux->sig;
			if( aux != NULL){
				nuevo->sig = pos->sig;
				pos->sig = nuevo;
			}
			else{
				free (nuevo);
#ifdef DEBUG
				fprintf(stderr, "Error: %p posición inexistente \n", pos);
#endif
				return -2;
			}
		}
		return 0;	
	}
}

int insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef nuevo, ant;
	if(NULL == (nuevo= creaNodo(info)))
		return -1;
	else{
		if(estaVacia(*raiz) || pos == NULL || pos== *raiz){
			nuevo->sig = *raiz;
			*raiz = nuevo;
		}
		else{
			ant = *raiz;
			while (ant != NULL && ant->sig != pos)
				ant = ant->sig;
			if (ant != NULL){
				nuevo->sig = pos;
				ant->sig = nuevo;
			}
			else{
				free (nuevo);
#ifdef DEBUF
				fprintf(stderr, "Error: %p posición inexistente\n", pos);
#endif
				return -2;
			}
		}
		return 0;
	}
}

int insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	return insertarAntesDeNodo(raiz, *raiz, info);
}

int insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	return insertarDespuesDeNodo (raiz, NULL, info);
}

int insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info)
{
	tipoNodoRef nuevo, aux;
	tipoInfo cont=0, i=0;
	if(*raiz==NULL || indice<0)
		return 2;
	if(indice==0){
		insertarNodoComienzo(raiz, info);
		return 0;
	}
	if(NULL == (nuevo=creaNodo(info)))
		return -1;
	else{
		aux= *raiz;
		while(aux!=NULL){
			aux= aux->sig;
			cont++;
		}
		if(indice==cont){
			insertarNodoFinal(raiz, info);
			return 0;
		}
		aux= *raiz;
		for(i=0; i<indice-1; i++){
			aux= aux->sig;
		}
		nuevo->sig=aux->sig;
		aux->sig=nuevo;
	}
	return 0;
}
int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos)
{
	tipoNodoRef ant;
	if(estaVacia(*raiz))
		return -1;
	else if(pos == NULL)
		return -2;
	else if (pos == *raiz){
		*raiz = (*raiz)->sig;
		free(pos);
		return 0;
	}
	else{
		ant= *raiz;
		while (ant != NULL && ant->sig != pos)
			ant = ant->sig;
		if(ant != NULL){
			ant->sig = pos->sig;
			free(pos);
			return 0;
		}
		else
			return -3;
	}
}

int eliminarNodoComienzo(ListaEnlazadaRef raiz)
{
	tipoNodoRef borrar;
	if(estaVacia(*raiz)){
		return -1;
	}
	else{
		borrar = *raiz;
		*raiz= (*raiz)->sig;
		free(borrar);
		return 0;
	}
}

int eliminarNodoFinal(ListaEnlazadaRef raiz)
{
	tipoNodoRef ant, indice, borrar;;
	if(estaVacia(*raiz))
		return -1;
	else{
		borrar= *raiz;
		ant = NULL;
		while (borrar->sig != NULL){
			ant= borrar;
			borrar= borrar->sig;
		}
		if(ant ==NULL){
			free(borrar);
			*raiz=NULL;
		}
		else{
			free(borrar);
			ant->sig = NULL;
		}
	}
	return 0;
}

int eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice)
{
	tipoNodo *borrar, *aux, *ant;
	tipoInfo cont=0,i;
	if(*raiz == NULL || indice<0)
		return -1;
	else{
		if(indice==0){
			eliminarNodoComienzo(raiz);
			return 0;
		}
		aux= *raiz;
		while(aux!= NULL){
			aux= aux->sig;
			cont++;
		}
		if(cont==indice){
			eliminarNodoFinal(raiz);
			return 0;
		}
		if(indice>cont)
			return -1;
		aux=*raiz;
		for(i=0; i<indice-1; i++){
			aux= aux->sig;
		}
		borrar= aux->sig;
		aux->sig= borrar->sig;
		borrar->sig=NULL;
		free(borrar);
		return 0;
	}
}

int liberarListaEnlazada(ListaEnlazadaRef raiz)
{
	tipoNodoRef borrar, aux;
	if(estaVacia(*raiz))
		return -1;
	else{
		aux=*raiz;
		while(aux!=NULL){
			borrar = aux;
			aux = aux->sig;
			free(borrar);
		}
		*raiz= NULL;
		return 0;
	}
}

tipoInfo devolverInfoPosicionIndice(ListaEnlazada raiz, int indice)
{
	tipoInfo valor, i, nodos=0;
	tipoNodoRef aux;
	if(raiz == NULL || indice <0)
		return -1;
	aux= raiz;
	while( aux!= NULL){
		if(indice==nodos && aux!= NULL)
			return aux->info;
		aux = aux->sig;
		nodos++;
	}
	return -2;
}

int insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	tipoNodoRef aux;
	if(estaVacia(*raiz) || (*raiz)->info > *info)
		return insertarNodoComienzo (raiz, info);
	else{
		aux = *raiz;
		while(aux->sig != NULL && aux->sig->info < *info)
			aux = aux->sig;
		return insertarDespuesDeNodo (raiz, aux, info);
	}
}

int mostrarListaEnlazada(ListaEnlazada raiz)
{
	tipoNodoRef aImprimir;
	int res = 0,i = 0;
	
	printf("\n\n");
	printf("%-14s%-10s\n","  Posición", "Valor");
	printf("%-14s%-10s\n","  ==========", "======");


	aImprimir = raiz;
	while (aImprimir != NULL) {
		printf("\t%3d)\t%7d\n",i++, aImprimir->info);
		aImprimir = aImprimir->sig;
	}
	return res;
}

int crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos)
{
	int i;
	tipoInfo temp;
	if (estaVacia(*raiz)) {
		srandom(time(NULL));
		for (i = 0; i < numNodos; i++) {
            temp = random()%100;
            insertarDespuesDeNodo(raiz, NULL, &temp);
            //insertarAntesDeNodo(raiz, NULL, &temp);
            //insertarNodoFinal(raiz, &temp);
			//insertarNodoComienzo(raiz, &temp);
		}
		return 0;
	}
	return -1;
}

void presentarAlReves(ListaEnlazada raiz){
	if(raiz != NULL){
		presentarAlReves(raiz->sig);
		printf("\t%d\t", raiz->info);
	}
}


//Ejercicios ficheros

int guardarListaEnlazadaTexto(ListaEnlazada raiz, char *nombreFichero){
	FILE *fp;
	ListaEnlazada aux;
	tipoInfo numNodos;
	numNodos = 0;
	if(raiz == NULL){
#ifdef DEBUG
		fprintf(stderr, "\nError: la lista esta vacia.\n");
#endif
		return -2;
	}
	if(NULL == (fp = fopen(nombreFichero, "w"))){
#ifdef DEBUG
		fprintf(stderr, "\nError: creación del fichero.\n");
#endif
		return -1;
	}
	
	aux=raiz;
	while(aux != NULL){
		fprintf(fp, "%d ", aux->info);
		aux = aux->sig;
		numNodos++;
	}
	fclose(fp);
	return numNodos;
}


int cargarListaEnlazadaTexto(ListaEnlazadaRef raiz, char *nombreFichero){
	FILE *fp;
	tipoInfo elemento, numNodos;
	
	if(NULL == (fp = fopen(nombreFichero, "r"))){
#ifdef DEBUG
		fprintf(stderr, "\nError: la lista esta vacia.\n");
#endif
		return -1;
	}
	numNodos = 0;
	while(feof(fp) == 0){
		if(fscanf(fp, "%d ", &elemento) == EOF){
			fclose(fp);
			raiz = NULL;
#ifdef DEBUG
		fprintf(stderr, "\nError: creación del fichero.\n");
#endif
			return -2;
		}
		else{
			insertarOrdenada(raiz, &elemento);
			numNodos++;
		}
	}
	fclose(fp);
	
	return numNodos;
}
