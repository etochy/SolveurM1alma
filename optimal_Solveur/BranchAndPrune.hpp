//
//  BranchAndPrune.hpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 17/02/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#ifndef BranchAndPrune_hpp
#define BranchAndPrune_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Constraints.hpp"
#include "Queen.hpp"
#include "AllDifferent.hpp"
#include "Domain.hpp"
#include "Node.hpp"

using namespace std;

class BranchAndPrune {
public:
    
    // Initialise les ensembles domaines et contraintes de notre problème (D et C).
    BranchAndPrune(Node DSet, vector<Constraints*> CSet);
    ~BranchAndPrune();
    int run();
    void printResult();
    bool isSolution(Node node);
    Node prune(Node e);
    Node forwardChecking(Node e);
    
private:
    vector<Node> nodes;
    vector<Domain> domainSet;
    vector<Constraints*> constraintSet;
    vector<Node> results;
};

#endif /* BranchAndPrune_hpp */
