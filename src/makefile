CXX=g++
CXXFLAGS=-std=c++11 -stdlib=libc++

all: branchAndPruneSacha

.PHONY: clean

branchAndPruneSacha: solve.o branchAndPruneSacha.o contraintes.o
	$(CXX) $(CXXFLAGS) -o branchAndPruneSacha solve.o branchAndPruneSacha.o contraintes.o

solve.o: solve.cpp branchAndPruneSacha.o contraintes.o
	$(CXX) $(CXXFLAGS) -c -o solve.o solve.cpp

branchAndPruneSacha.o: branchAndPruneSacha.cpp contraintes.cpp
	$(CXX) $(CXXFLAGS) -c -o branchAndPruneSacha.o branchAndPruneSacha.cpp

contraintes.o: contraintes.cpp
	$(CXX) $(CXXFLAGS) -c -o contraintes.o contraintes.cpp
	
clean:
	-rm *.o branchAndPruneSacha out.txt
