CC = g++     # name of the compiler
CFLAGS = -O3 # optimization flags

program: samuel-test.o
	$(CC) $(CFLAGS) -o program samuel-test.o
    
#program: main.o  POP.o input.o 
#	$(CC) $(CFLAGS) -o program POP.o input.o main.o


samuel-test.o: samuel-test.cpp
	$(CC) $(CFLAGS) -c samuel-test.cpp

clean:
	rm -f *.o program*

debug:  
	g++ -ggdb -o program-debug samuel-test.cpp
