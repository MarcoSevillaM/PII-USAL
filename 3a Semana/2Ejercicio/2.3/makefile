OBJS = main.o funciones.o
CC = gcc
#CTAGS = -c 
CTAGS = -c -g -DDEBUG

matrices : $(OBJS)
	$(CC) $(OBJS) -o matrices

main.o : main.c funciones.h  
	$(CC) $(CTAGS) main.c

funciones.o : funciones.c funciones.h
	$(CC) $(CTAGS) funciones.c
clear:
	rm -f *.o
	
