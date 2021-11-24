#Marco Sevilla Martín 
#Grupo PB4 Programación II
#id00780760@usal.es


CC = gcc
OBJS = main.o vectorDinamica.o vectorAux.o

programa : $(OBJS) vectorDinamica.h vectorAux.h
	$(CC) $(OBJS) -o programa

main.o : main.c vectorDinamica.h vectorAux.h
	$(CC) -c main.c

vectorDinamica.o : vectorDinamica.c vectorDinamica.h
	$(CC) -c vectorDinamica.c

vectorAux.o : vectorAux.c vectorAux.h
	$(CC) -c vectorAux.c

clean :
	rm -f *.o