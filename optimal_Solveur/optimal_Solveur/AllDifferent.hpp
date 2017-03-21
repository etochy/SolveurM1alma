//
//  AllDifferent.hpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 14/03/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#ifndef AllDifferent_hpp
#define AllDifferent_hpp

#include <stdio.h>
#include "Constraints.hpp"

class AllDifferent : public Constraints {
public:
    AllDifferent();
    bool check(Node e);
    void contract(Node* e);
private:
};

#endif /* AllDifferent_hpp */
