#include "sueldo.h"
#include <stdio.h>
#include "empleados.h"
void pagar_empleado(Empleado *e){
int sueldo;

if(e->rango < 5){sueldo=1500;}else{sueldo=2000;}

e->cuenta+=sueldo;
printf("Se le ha pagado a %s %s %d $ \n",e->nombre,e->apellido,sueldo);

}
