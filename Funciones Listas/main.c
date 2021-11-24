//
//  main.c
//  listaEnlazadaSimple
// "Menú de listasEnlazadas"
//
// Created by Marco Sevilla Martín on 21/05/2020
//  Copyright (c) 2020 Marco Sevilla Martín. All rights reserved.
//marcosevillam@usal.es


#include <stdio.h>
#include <ctype.h>
#include "listaEnlazadaSimple.h"

int main(int argc, const char * argv[])
{
	char *menu ="Listas enlazadas:\n A) Crear lista aleatoria\n B) Añadir al principio\n C) Añadir al final\n D) Insertar en posición por índice\n E) Devolver valor en posición por índice\n F) Eliminar al principio\n G) Eliminar al final\n H) Eliminar en posición por índice\n I) Crear lista ordenada\n J) Mostrar lista\n K) Liberar listas\n L) Escribir la lista en fichero\n M) Presentar valores del fichero\n Q) Salir\n";
	
    //ListaEnlazada raizOrdenada;
	ListaEnlazada raiz, raizOrdenada;
	tipoNodoRef aux;
	tipoInfo indice,i,error;
    char opcion;
	tipoInfo temp=1234,
	temp2 = 4321;
	char nombreFichero[] = "fichero.txt";
	ListaEnlazada listaFichero=NULL;
    crearVacia(&raiz);
	crearVacia(&raizOrdenada);
	
    do {
        system("clear");
		printf("%s ",menu);
        printf("Introduce opción: ");
        scanf("%c%*c",&opcion);
		opcion = toupper(opcion);
		switch (opcion) {
			case 'A':
                printf("\nIntroduce el número de nodos: ");
                scanf("%d%*c", &i);
                printf("\nAhora la cargo con valores aleatorios: %d\n",
                       crearListaValoresAleatorios(&raiz, i));
                break;
			case 'B':
				printf("\n\nInsertando nodo comienzo: %d", insertarNodoComienzo(&raiz, &temp));
				break;
			case 'C':
				//printf("\n\nInsertando nodo final: %d", insertarDespuesDeNodo(&raiz, NULL, &temp2));
                //Comentar la linea anterior, y descomentar la siguiente en cuanto ya tenga implementada
                //la función inertarNodoFinal.
			printf("\n\nInsertando nodo final: %d", insertarNodoFinal(&raiz, &temp2));
				break;
			case 'D':
				printf("\nIntroduce una posición como entero: ");
                scanf("%d%*c", &indice);
                
                insertarNodoPosicionIndice(&raiz, indice, &temp2);//
                
                //En cuanto tenga implementada la función insertarNodoPosicionIndice debe
                //descomentar la línea anterior y comentar las restantes líneas de este case.
                //Utilizar comentarios adecuadamente para ir probando cada función según se van
                //implementando
                /*aux = raiz;
                i=0;
                while (aux != NULL && i++ < indice) {
                    aux = aux->sig;
                }
                if (aux != NULL) {
                    //printf("\n\nInsertando nodo antes: %d",insertarAntesDeNodo(&raiz, aux, &temp));
                    printf("\n\nInsertando nodo después: %d",insertarDespuesDeNodo(&raiz, aux, &temp2));
                }*/
                break;
            case 'E':
                printf("\nIntroduce una posición como entero: ");
                scanf("%d%*c", &indice);
                
                printf("\nEl valor almacendo en la posición %d es %d\n", indice,devolverInfoPosicionIndice(raiz, indice));
                break;
            case 'F':
				printf("\n\nEliminando nodo comienzo: %d", eliminarNodoComienzo(&raiz));
				break;
			case 'G':
				printf("\n\nEliminando nodo final: %d", eliminarNodoFinal(&raiz));
				break;
			case 'H':
                printf("\nIntroduce una posición como entero: ");
                scanf("%d%*c", &indice);
                printf("\n\nEliminando nodo: %d",eliminarNodoPosicionIndice(&raiz, indice));
                //                aux = raiz;
                //                i=0;
                //                while (aux != NULL && i++ < indice) {
                //                    aux = aux->sig;
                //                }
                //                if (aux != NULL)
                //                    printf("\n\Eliminando nodo: %d",eliminarNodo(&raiz, aux));
                break;

            case 'I':
                printf("\n\nCreando raizOrdenada...\n\n");
                while (!estaVacia(raiz)) {
                    insertarOrdenada(&raizOrdenada, &raiz->info);
                    eliminarNodoComienzo(&raiz);
                }
                printf("\n\nAhora raizOrdenada contiene los elementos ordenados. raiz está vacía.\n\n");
                break;
            case 'J':
                printf("Mostrando lista raiz: %d\n",mostrarListaEnlazada(raiz));
                printf("Mostrando lista raizOrdenada: %d\n",mostrarListaEnlazada(raizOrdenada));
                break;
            case 'Q':
				printf("\n\nSaliendo.\n\n");
            case 'K':
                printf("Liberación raiz: %d\n",liberarListaEnlazada(&raiz));
                printf("Liberación raizOrdenada: %d\n",liberarListaEnlazada(&raizOrdenada));
                break;
			case 'L':
				printf("\nContenido lista en un fichero...\n");
				error = guardarListaEnlazadaTexto(raiz, nombreFichero);
				if(error == -1)
					printf("\nError: Crear fichero.\n");
				else if(error==-2)
					printf("\nError: Lectura fichero.\n");
				else
					printf("\n Fichero transferido con éxito");
					printf("\nNumero de nodos: %d\n", error);
				break;
			case 'M':
			printf("\nPresentando contenido fichero\n");
			error = cargarListaEnlazadaTexto (&listaFichero, nombreFichero);
			if(error==-1)
				printf("\nError: Creación fichero.\n");
			else if(error==-2)
				printf("\nError: Lectura fichero.\n");
			else{
				printf("\nInformación pasada correctamente\n");
				printf("\nNúmero de nodos %d\n", error);
				printf("Mostrando lista raizListaDeFichero: %d\n", mostrarListaEnlazada(listaFichero));
			}
			break;
            default:
				printf("\n\nOpción incorrecta!\a\n\n");
				break;
		}
        printf("\nPulse enter...\n");
        getchar();
	} while ('Q' != opcion);
	printf("\n\nTerminación normal del programa.\n\n");
    return 0;
}

