#include "empleados.h"
#include "sueldo.h"
#include <stdio.h>


int main(){

Empleado e={3,"Alberto","Perez Gomez",27,0};

presentar_empleado(e);
pagar_empleado(&e);

return 0;
}
