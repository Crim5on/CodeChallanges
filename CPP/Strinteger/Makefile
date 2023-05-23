all: main.o

main.o:
	clang++ -std=c++17 -pthread -lm -ldl -O2 -Wall -Wextra -fsanitize=return main.cpp -o main.o

clean:
	@rm *.o *.out