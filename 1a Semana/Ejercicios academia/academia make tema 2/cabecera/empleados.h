#ifndef EMPLEADOS
#define EMPLEADOS

typedef struct empleado{
	int rango;
	char nombre[20];
	char apellido[20];
	int edad;
	int cuenta;
}Empleado;

void presentar_empleado(Empleado );


#endif
