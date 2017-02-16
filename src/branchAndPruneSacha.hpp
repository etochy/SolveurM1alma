#ifndef BRANCHANDPRUNESACHA_HPP_
#define BRANCHANDPRUNESACHA_HPP_

#include <iostream>
#include <list>
#include "contraintes.hpp"


class BranchAndPruneSacha{
public:
	BranchAndPruneSacha(int sizeQueenBoard);
	~BranchAndPruneSacha();
	int run();
    bool isValid(list<list<int>> domainsSet);
    list<list<int>> prune(list<list<int>> domains, list<Contraintes> c);

private:
	int* mat;
    list<int> variables;
	list<list<int>> domains;
    list<Contraintes> constraints;
    list<int> result;
};

#endif
