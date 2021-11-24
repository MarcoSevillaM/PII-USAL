#Marco Sevilla Martín
#marcosevillam@usal.es
#Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.

programa: main.o estudiante.o mostrarUnRegistro.o cargarUnRegistroAleatorio.o
	gcc -o programa 2.main.o 2.estudiante.o 2.mostrarUnRegistro.o 2.cargarUnRegistroAleatorio.o 

main.o: 2.main.c estudiante.h
	gcc -c 2.main.c


estudiante.o: 2.estudiante.c estudiante.h
	gcc -c 2.estudiante.c 

mostrarUnRegistro.o: 2.mostrarUnRegistro.c estudiante.h
	gcc -c 2.mostrarUnRegistro.c

cargarUnRegistroAleatorio.o: 2.cargarUnRegistroAleatorio.c estudiante.h
	gcc -c 2.cargarUnRegistroAleatorio.c

clear: 
	rm -f *.o