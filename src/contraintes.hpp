#ifndef CONTRAINTES_HPP_
#define CONTRAINTES_HPP_

#include <stdlib.h>
#include <time.h> 

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

class Contraintes {
public:
	Contraintes();
	~Contraintes();
	
	bool verify(std::list<std::list<int> > domaines);

private:
	
};

#endif