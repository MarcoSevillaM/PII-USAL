//Marco Sevilla Martín 
//Grupo PB4 Programación II
//id00780760@usal.es


#include "vectorAux.h"

int cargarValoresAleatorios(int *vector, size_t tam, int rangoInf, int rangoSup)
{
	if(vector == NULL) return -1;
	else if(rangoInf >=rangoSup) return -2;
	else
	{
		int i;
		//Rellenar con valores desde rangoinf a rangosup
		for(i=0;i<tam;i++)
		{
			do{
				vector[i] = random() % rangoSup;
			}while(vector[i]<rangoInf);
		}
		return 0;
	}
}

int cargarValoresTeclado(int *vector, size_t tam)
{
	int i;
	if(vector == NULL) return -1;
	else
	{
		printf("Inicie el vector con los valores deseados:\n");
		for(i=0;i<tam;i++)
		{
			printf("Valor (%d): ", i+1);
			scanf("%d", &vector[i]);
		}
		puts("\n\n");
		return 0;
	}
}

int mostrarValores(int *vector, size_t tam)
{
	int i;
	if(vector == NULL) return -1;
	else
	{
		printf("El vector contiene los siguientes valores:  ");
		for(i=0;i<tam;i++)
		{
			printf("%d ", vector[i]);
		}
		puts("\n\n");
		return 0;
	}
}