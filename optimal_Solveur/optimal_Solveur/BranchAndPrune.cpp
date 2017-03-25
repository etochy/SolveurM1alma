//
//  BranchAndPrune.cpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 17/02/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#include "BranchAndPrune.hpp"

BranchAndPrune::BranchAndPrune(Node DSet, vector<Constraints*> CSet):constraintSet(CSet) {
    nodes.push_back(DSet);
}

BranchAndPrune::~BranchAndPrune() {
    
}

int BranchAndPrune::run() {
    
    Node currentNode;
    
    Node pruningResult;
    
    int smallerDomain = 0;
    
    while (!nodes.empty()) {
        
        // On étudie le premier élément de notre liste de Noeuds
        currentNode = *nodes.begin();
        
        // On le supprime de notre liste
        nodes.erase(nodes.begin());
        
        // On effectue notre opération de pruning en fonction de notre ensemble de contraintes
        pruningResult = forwardChecking(currentNode);
        
        if (!pruningResult.isEmpty()) {
            
            if (isSolution(pruningResult)) {
                results.push_back(pruningResult);
            }
            else {
                
                // On récupère le plus petit domaine du résultat du pruning
                smallerDomain = pruningResult.getSmallerDomain();
                
                // Pour chacun des éléments dans le domaine "smallerDomain"
                for (int cp : pruningResult.getDomainList()[smallerDomain].getIntegerSet()) {
                    
                    // On assigne l'élément v au domaine "smallerDomain" dans eCopy
                    pruningResult.replace(smallerDomain, cp);
                    
                    if (!forwardChecking(pruningResult).isEmpty()) {
                        // On ajoute eCopy à la liste des Noeuds
                        nodes.push_back(pruningResult);
                    }
                }
            }
        }
        
    }
    
    return 0;
}

// Réalise un simple backtracking
Node BranchAndPrune::prune(Node e) {
    
    for (Constraints* c : constraintSet) {
        if (!(c->check(e))) {
            return Node();
        }
    }
    return e;
}

// Réalise un forward Check
Node BranchAndPrune::forwardChecking(Node e) {
    
    for (Constraints* c : constraintSet) {
        c->contract(&e);
    }
    
    for(Domain d : e.getDomainList()) {
        if (d.size() < 1) {
            return Node();
        }
    }
    return prune(e);
}

// Vérifie si le Noeud passé en paramètre est une solution
bool BranchAndPrune::isSolution(Node node) {
    
    // On vérifie que tous les domaines de node sont réduit à 1
    if(node.areAllVariablesAffected()) {
        return true;

    }
    else {
        return false;
    }
}

void BranchAndPrune::printResult() {
    if (results.size() > 0) {
        for (int i = 0; i < results.size(); ++i) {
            results[i].print();
        }
        cout<<"Total : "<<results.size()<<endl;
    }
    else {
        cout << "Pas de solutions trouvées pour le problème courant." << endl;
    }
}



