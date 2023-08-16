all: main.run

main.run: main.o myDeque.o 
	gcc -o main.run main.o myDeque.o

main.o:
	gcc -c -std=c99 main.c

myDeque.o:
	gcc -c -std=c99 myDeque.c

clean:
	rm *.run *.o

.PHONY: all clean