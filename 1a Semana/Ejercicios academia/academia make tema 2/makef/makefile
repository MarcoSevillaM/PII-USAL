#comentarios en makefile

programa: main.o funcionesmatematicas.o presentacion.o entrada.o
	gcc -o programa main.o funcionesmatematicas.o presentacion.o entrada.o

main.o: main.c funciones.h
	gcc -c main.c

presentacion.o: presentacion.c funciones.h
	gcc -c presentacion.c

entrada.o: entrada.c funciones.h
	gcc -c entrada.c

funcionesmatematicas.o: funcionesmatematicas.c funciones.h
	gcc -c funcionesmatematicas.c

clean: 
	rm -f *.o
