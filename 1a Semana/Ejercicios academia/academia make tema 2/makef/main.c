#include "funciones.h"



int main(){

int a=escanear_entero();

if(esprimo(a)){
presentar("El numero introducido es primo\n");
}else{
presentar("El numero introducido no es primo\n");
}

return 0;
}
