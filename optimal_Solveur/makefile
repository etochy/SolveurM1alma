CXX=g++
CXXFLAGS=-std=c++11
SRC= main.cpp BranchAndPrune.cpp Constraints.cpp Node.cpp Domain.cpp AllDifferent.cpp Queen.cpp
OBJ= $(SRC:.cpp=.o)

all: branchAndPrune

branchAndPrune: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

BranchAndPrune.o: BranchAndPrune.cpp Constraints.cpp Node.cpp Domain.cpp AllDifferent.cpp Queen.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Constraints.o: Constraints.cpp Node.cpp Domain.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Node.o: Node.cpp Domain.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Domain.o: Domain.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

AllDifferent.o: AllDifferent.cpp Constraints.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

Queen.o: Queen.cpp Constraints.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -rf *.o