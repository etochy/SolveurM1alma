//
//  Queen.hpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 09/03/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#ifndef Queen_hpp
#define Queen_hpp

#include <stdio.h>
#include "Constraints.hpp"

class Queen : public Constraints {
    
public:
    Queen(int queenBoardSize);
    bool check(Node e);
    void contract(Node* e);
private:
    int boardSize;
};
#endif /* Queen_hpp */
