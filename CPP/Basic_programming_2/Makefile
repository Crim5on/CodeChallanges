all: main.o

main.o:
	@echo "Compiling program to be submitted .."
	@g++ -o ./main.o -g -O2 -std=gnu++17 -static -lrt -Wl,--whole-archive -lpthread -Wl,--no-whole-archive  ./main.cpp

profile:
	@echo "Compiling program to be profiled .."
	@g++ -pg -no-pie -fno-builtin main.cpp -o main.o
	@echo "-> run testcode now to collect profile data."
	@echo "Check if 'gmon.out' was generated."
	@echo "Open the profile information with gprof ''./main.o | less'"
	@echo "filter out library functions: 'gprof ./main.o | grep -v std | grep -v static | grep -v cxx'"
	@echo "For further information see: https://www.youtube.com/watch?v=re79V7hNiBY"


clean:
	@rm *.o


