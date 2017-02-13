#ifndef BACKTRACKING_HPP_
#define BACKTRACKING_HPP_

#include <stdlib.h>
#include <time.h> 

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

class Backtracking{
public:
	Backtracking();
	~Backtracking();

	void run(int node, std::vector<char> solution);
	void printResult();

private:
	int nbMachine;
	int nbTask;
	int totalNode;
	int * mat;
	int * affectOrder;
	std::vector<std::vector<char> > result;

	bool contains(char item, std::vector<char> &vector);
};

#endif