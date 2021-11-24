//Marco Sevilla Martín 
//Grupo PB4 Programación II
//id00780760@usal.es


#include "vectorDinamica.h"

int *creaVectorInt(size_t tam, int *codigoError)
{
	int *ptr;
	
	if(tam<=0)
	{
		*codigoError = -1;
		return NULL;
	}
	if( (ptr = (int *) malloc(tam*sizeof(int))) == NULL)
	{
		*codigoError = -2;
		return NULL;
	}
	else
	{
		*codigoError = 0;
		return ptr;
	}
}