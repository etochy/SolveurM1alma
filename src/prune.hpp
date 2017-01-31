#ifndef PRUNE_HPP_
#define PRUNE_HPP_

#include <stdlib.h>
#include <time.h> 

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

class Prune{
public:
	Prune();
	virtual ~Prune();

	virtual void run(int node, std::vector<char> solution);
	void printResult();

private:
	
};

#endif