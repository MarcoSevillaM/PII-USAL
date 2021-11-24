//Programa alejandro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 5
typedef struct minodo
{
	int dato;
	struct minodo * sig;
}NODO;

NODO *aniadeNodo(int n,NODO *lista);
NODO * creaNodo(int n);
void visualizarLista(NODO * lista);
NODO * borrarNodoP(NODO * lista);
NODO * borrarNodoF(NODO * lista);
NODO * eliminarlista(NODO *lista);


int main (){
NODO * lista=NULL;
srand(time(NULL));
	lista=aniadeNodo(7,lista);
	lista=aniadeNodo(8,lista);
	lista=aniadeNodo(9,lista);
	visualizarLista(lista);
printf("\n------------------------------------\n");
	lista=eliminarlista(lista);

	visualizarLista(lista);



return 0;
}

NODO *aniadeNodo(int n,NODO * lista){
	
	NODO *aux=lista;
	
	if(aux==NULL){
	/*aux= (NODO *) malloc(sizeof(NODO));
	aux->dato=n;
	aux->sig=NULL;*/
	aux = creaNodo(n);
	return aux;
	}
	
	while(aux->sig != NULL){
	aux=aux->sig;	
	}
	aux->sig=creaNodo(n);
	
	return lista;
}

NODO * creaNodo(int n){
	NODO *ptr=NULL;
	ptr= (NODO *) malloc(sizeof(NODO));

	if(ptr==NULL){
	exit(-1);
	}
	ptr->dato=n;
	ptr->sig=NULL;

	return ptr;
}

void visualizarLista(NODO * lista){
 
if(lista==NULL){
	printf("La lista esta vacia\n");
}else{
	while(lista->sig!=NULL){
	printf(" %d ,",lista->dato);
	lista=lista->sig;
	}
	printf(" %d ,",lista->dato);
	}
}

NODO * borrarNodoP(NODO * lista){

	NODO * aux=lista;
	lista=lista->sig;
	free(aux);
	return lista;


}

NODO * borrarNodoF(NODO * lista){

	NODO * aux=lista;
	NODO * ant= lista;

	while(aux->sig!=NULL){
	ant=aux;
	aux=aux->sig;
	}
	ant->sig=NULL;
	free(aux);
	return lista;

}

NODO * eliminarlista(NODO *lista){
	
	NODO * aux=lista;
	while(aux->sig!=NULL){
	aux=aux->sig;
	free(lista);
	lista=aux;
	}
	free(lista);
	lista=NULL;
	return lista;
}

/*lista=NULL;
	if(lista->sig!=NULL){
	eliminarlista(lista->sig);
	free(lista);
	lista=NULL;
	}else{
	free(lista);
	lista=NULL;
	}*/





