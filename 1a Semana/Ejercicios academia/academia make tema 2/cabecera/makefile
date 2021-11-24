programa1: main.o empleados.o sueldo.o 
	gcc -o programa1 main.o empleados.o sueldo.o

main.o: main.c empleados.h sueldo.h
	gcc -c main.c
empleados.o: empleados.c empleados.h 
	gcc -c empleados.c
sueldo.o: sueldo.c sueldo.h empleados.h
	gcc -c sueldo.c 
