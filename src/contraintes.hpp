#ifndef CONTRAINTES_HPP_
#define CONTRAINTES_HPP_

#include <iostream>
#include <list>
using namespace std;

class Contraintes {
	public:
		Contraintes(int boardsize);
		~Contraintes();
    bool verify(list<list<int>> domaines);

	private:
    int queensize;
};

#endif
