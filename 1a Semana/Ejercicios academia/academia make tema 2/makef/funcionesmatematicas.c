 #include "funciones.h"


int factorial(int num){

int i,resultado;

	for(i=2;i<=num;i++)
	resultado*=i;

	return resultado;

}


int esprimo(int num){

int i;

	for(i=2;i<num;i++){

		if(num%i==0)
		return 0;
	}

	return 1;
}

