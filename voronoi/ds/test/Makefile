#all:
#	g++ -ggdb node.cpp line.cpp fire.cpp mnline.cpp test.cpp -o test.out -lm

#SRC = $(shell ls *.cpp)
TEST_SRC = $(shell ls ../*.cpp)
TEST_OBJ = $(TEST_SRC:.cpp=.o)
EXE = test.out

CC = gcc
CXX = g++
CFLAGS = -Wall -ggdb 
LDFLAGS = -lm -lgtest

.PHONY: all clean compile
all:main

main: compile #$(OBJ)
	$(CXX) $(CFLAGS) test.cpp $(TEST_OBJ) -o $(EXE) $(LDFLAGS)
	#$(CXX) $(CFLAGS) $(OBJ) -o $(EXE) $(LDFLAGS)

compile: $(TEST_SRC)
	@for go in $(TEST_SRC:.cpp=); \
	do \
	$(CXX) $(CFLAGS) -c $$go.cpp -o $$go.o ; \
	echo "compile $$go.cpp to $$go.o" ; \
	done ;\

clean:
	rm $(EXE) $(OBJ)
