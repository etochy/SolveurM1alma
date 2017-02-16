#ifndef CONTRAINTES_HPP_
#define CONTRAINTES_HPP_

#include <iostream>
#include <list>
using namespace std;

class Contraintes {
	public:
		Contraintes();
		~Contraintes();
    bool verify(list<list<int>> domaines);

	private:
	
};

#endif
