#Marco Sevilla Martín 
#Grupo PB4 Programación II
#id00780760@usal.es



programa3: main.o recibirMatriz.o
	gcc -o programa3 main.o recibirMatriz.o

main.o: main.c recibirMatriz.h
	gcc -c main.c

recibirMatriz.o: recibirMatriz.c recibirMatriz.h
	gcc -c recibirMatriz.c

clean: 
	rm -f *.o