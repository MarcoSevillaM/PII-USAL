#Marco Sevilla Martín
#id00780760@usal.es
#Programa realizado para practicas de Programacion II PB4 de 1 Ingeniería informática.

programa: main.o estudiante.o mostrarUnRegistro.o cargarUnRegistroAleatorio.o
	gcc -o programa main.o estudiante.o mostrarUnRegistro.o cargarUnRegistroAleatorio.o 

main.o: main.c estudiante.h
	gcc -c main.c


estudiante.o: estudiante.c estudiante.h
	gcc -c estudiante.c 

mostrarUnRegistro.o: mostrarUnRegistro.c estudiante.h
	gcc -c mostrarUnRegistro.c

cargarUnRegistroAleatorio.o: cargarUnRegistroAleatorio.c estudiante.h
	gcc -c cargarUnRegistroAleatorio.c

clean: 
	rm -f *.o