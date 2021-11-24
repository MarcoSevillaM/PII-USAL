//Marco Sevilla
#include <stdio.h>
#include <stdlib.h>
typedef struct nodos{
	int numero;
	struct nodos * continua;
}nodo;

nodo * crearNodo(int numero);
nodo *aniadeNodo(int n, nodo* lista);
void verlista(nodo *lista);
int cuentaelementos(nodo* lista);
int main (){
	nodo* lista=NULL;
	int num;
	lista=aniadeNodo(7, lista);
	lista=aniadeNodo(3, lista);
	lista=aniadeNodo(2, lista);
	lista=aniadeNodo(8, lista);
	verlista(lista);
	printf("\nEl numero de elementos es: %d\n",cuentaelementos(lista));	
}
nodo* crearNodo(int num){
	nodo *puntero=NULL;
	puntero= (nodo*)malloc(sizeof(nodo));
	if (puntero==NULL)
		exit(-1);
	puntero->numero=num;
	puntero->continua=NULL;
	return puntero;
}

nodo *aniadeNodo(int n, nodo* lista){
	nodo *aux=lista;
	if(aux==NULL){
		aux=crearNodo(n);
		return aux;
	}
	while(aux->continua!=NULL){
		aux=aux->continua;
	}
	aux->continua=crearNodo(n);
	return lista;
}

void verlista(nodo *lista){
	if(lista==NULL)
		printf("La lista esta vacía\n");
	else{
		while(lista->continua != NULL){
			printf("%d, ", lista->numero);
			lista=lista->continua;
		}
		printf("%d", lista->numero);
	}
}
int cuentaelementos(nodo* lista){
	int num=1;
	nodo* aux=lista;
	if(lista==NULL){
		printf("No hay elemetos en la lista");
		return 0;
	}
	else{
		while(aux->continua!=NULL){
			aux=aux->continua;
			num++;
		}
	}
	return num;
}

nodo* insertarnum (nodo* lista, int n, int posicion){
	
}

