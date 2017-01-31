CXX=gcc
CXXFLAGS=-g -O2 -std=c++11

all: main

.PHONY: clean

clean:
	-rm *.o backtracking out.txt

main: main.cpp backtracking.o
	$(CXX) -o main backtracking.o

backtracking.o : backtracking.cpp backtracking.hpp prune.hpp
	$(CXX) -c backtracking.cpp