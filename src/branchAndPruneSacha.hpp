#ifndef BRANCHANDPRUNESACHA_HPP_
#define BRANCHANDPRUNESACHA_HPP_

#include <stdlib.h>
#include <time.h> 

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

class BranchAndPruneSacha{
public:
	BranchAndPruneSacha(int sizeQueenBoard);
	~BranchAndPruneSacha();

	void run(int node, std::vector<char> solution);
	void printResult();

private:
	
	std::vector<std::vector<char> > result;

	bool contains(char item, std::vector<char> &vector);
};

#endif