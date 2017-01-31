CXX=g++
CXXFLAGS=-g -O2 -std=c++11

all: backtracking

.PHONY: clean

clean:
	-rm *.o backtracking out.txt

backtracking: main.o backtracking.o
	$(CXX) -o backtracking main.o backtracking.o