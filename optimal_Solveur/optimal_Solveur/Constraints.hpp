//
//  Constraints.hpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 17/02/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#ifndef Constraints_hpp
#define Constraints_hpp

#include <stdio.h>
#include <vector>
#include "Domain.hpp"
#include <stdlib.h> 
#include "Node.hpp"

using namespace std;

class Constraints {
public:
    Constraints();
    ~Constraints();
    virtual bool check(Node e) = 0;
    virtual void contract(Node* e) = 0;
private:
    
};
#endif /* Constraints_hpp */
