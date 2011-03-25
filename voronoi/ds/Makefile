#all:
#	g++ -ggdb node.cpp line.cpp fire.cpp mnline.cpp test.cpp -o test.out -lm

SRC = $(shell ls *.cpp)
OBJ = $(SRC:.cpp=.o)
EXE = test.out

CC = gcc
CXX = g++
CFLAGS = -Wall -ggdb 
LDFLAGS = -lm

.PHONY: all clean compile
all:main

main: compile #$(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(EXE) $(LDFLAGS)

compile: $(SRC)
	@for go in $(SRC:.cpp=); \
	do \
	$(CXX) $(CFLAGS) -c $$go.cpp -o $$go.o ; \
	echo "compile $$go.cpp to $$go.o" ; \
	done ;\

clean:
	rm $(EXE) $(OBJ)
