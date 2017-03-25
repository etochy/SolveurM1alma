//
//  Queen.cpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 09/03/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#include "Queen.hpp"

Queen::Queen(int queenBoardSize) : boardSize(queenBoardSize) {
    
}

bool Queen::check(Node e) {
    
    vector<Domain> copyForChecking = e.getDomainList();
    int line = 0;
    int col = 0;
    
    for (int i = 0; i < copyForChecking.size(); ++i) {
        // On vérifie qu'une variable ait été assignée
        if (copyForChecking[i].size() == 1) {
            
            for (int j = i + 1; j < boardSize; j++) {
                // On vérifie pour une autre variable assignée.
                if ( (j < copyForChecking.size()) && (copyForChecking[j].size() == 1) ) {
                    line = i - j;
                    col = copyForChecking[i].front() - copyForChecking[j].front();
                    if (abs(line) == abs(col)) {
                        return false;
                    }
                }
            }
            
        }
    }
    
    
    return true;
}

void Queen::contract(Node* e) {
    
    vector<Domain> copyForContract = e->getDomainList();
    for (int i = 0; i < copyForContract.size(); ++i) {
        if (copyForContract[i].size() == 1) {
            int xi = copyForContract[i].front();
            for (int k = 0; k < copyForContract.size(); ++k) {
                if (k != i) {
                    int xj1 = xi - k + i;
                    int xj2 = xi + k - i;
                    copyForContract[k].suppress(xj1);
                    copyForContract[k].suppress(xj2);
                }
            }
            
        }
    }
}
