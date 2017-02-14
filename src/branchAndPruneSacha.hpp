#ifndef BRANCHANDPRUNESACHA_HPP_
#define BRANCHANDPRUNESACHA_HPP_

#include <stdlib.h>
#include <time.h> 

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

#include "contraintes.hpp"
using namespace std;

class BranchAndPruneSacha{
public:
	BranchAndPruneSacha(int sizeQueenBoard);
	~BranchAndPruneSacha();

	void run(int node, std::vector<char> solution);
	void printResult();

private:
	int* mat;
	std::list<std::list<int> > domains;
};

#endif