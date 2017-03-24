CXX=g++
CXXFLAGS=
SRC= main.cpp BranchAndPrune.cpp Constraints.cpp Node.cpp Domain.cpp AllDifferent.cpp Queen.cpp
OBJ= $(SRC:.cpp=.o)

all: branchAndPrune

branchAndPrune: $(OBJ)
	$(CXX) -o $@ $^ 

BranchAndPrune.o: BranchAndPrune.cpp Constraints.cpp Node.cpp Domain.cpp AllDifferent.cpp Queen.cpp
	$(CXX) -o $@ -c $<

Constraints.o: Constraints.cpp Node.cpp Domain.cpp
	$(CXX) -o $@ -c $<

Node.o: Node.cpp Domain.cpp
	$(CXX) -o $@ -c $<

Domain.o: Domain.cpp
	$(CXX) -o $@ -c $<

AllDifferent.o: AllDifferent.cpp Constraints.cpp
	$(CXX) -o $@ -c $<

Queen.o: Queen.cpp Constraints.cpp
	$(CXX) -o $@ -c $<

clean:
	rm -rf *.o