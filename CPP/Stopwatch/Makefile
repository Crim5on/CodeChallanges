all: main.o

main.o:
	g++ -o ./main.o -g -O2 -std=gnu++17 -static -lrt -Wl,--whole-archive -lpthread -Wl,--no-whole-archive  ./main.cpp

clean:
	@rm *.o
