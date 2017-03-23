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
    
    Node eCopy;
    
    int cp = 0;
    
    int smallerDomain = 0;
    
    while (!nodes.empty()) {
        
        //cout << "Traitement d'un nouveaud noeud" << endl;
        
        // On étudie le premier élément de notre liste de Noeuds
        currentNode = *nodes.begin();
        // On le supprime de notre liste
        nodes.erase(nodes.begin());
        
        // On effectue notre opération de pruning en fonction de notre ensemble de contraintes
        pruningResult = prune(currentNode);
        
        //cout << "Résultat pruning";
        //pruningResult.print();
        
        if (!pruningResult.isEmpty()) {
            
            //cout << "Noeud en cours de traitement non vide" << endl;
            
            if (isSolution(pruningResult)) {
                //cout << "Ajout d'un noeud dans la liste des résultats ";
                //pruningResult.print();
                results.push_back(pruningResult);
            }
            else {
                // On récupère le plus petit domaine du résultat du pruning
                smallerDomain = pruningResult.getSmallerDomain();
                
                
                //cout << "Affichage du plus petit domaine";
                //pruningResult.getDomainList()[smallerDomain].print();
                //cout << "" << endl;
                
                // On copie le résultat du pruning précédent
                eCopy.copy(pruningResult);
                
                // Pour chacun des éléments dans le domaine "smallerDomain"
                for (int i = 0; i < pruningResult.getDomainList()[smallerDomain].size(); ++i) {
                    
                    //cout << "Assignation de : ";
                    //cout << pruningResult.getDomainList()[smallerDomain].getIntegerSet()[i] << endl;
                    
                    // On assigne l'élément v au domaine "smallerDomain" dans eCopy
                    cp = pruningResult.getDomainList()[smallerDomain].getIntegerSet()[i];
                    
                    //cout << "Affichage AVANT replace" << endl;
                    //eCopy.print();
                    
                    eCopy.replace(smallerDomain, cp);
                    
                    //cout << "Affichage après replace : " << endl;
                    //eCopy.print();
                    
                    // On ajoute eCopy à la liste des Noeuds
                    nodes.push_back(eCopy);
                }
            }
        }
        
    }
    
    return 0;
}

// Réalise un simple backtracking
Node BranchAndPrune::prune(Node e) {
    for (vector<Constraints*>::iterator it = constraintSet.begin(); it != constraintSet.end(); ++it) {
        if (!(*it)->check(e)) {
            return Node();
        }
    }
    return e;
}

Node BranchAndPrune::forwardChecking(Node e) {
    
    for (vector<Constraints*>::iterator it = constraintSet.begin(); it != constraintSet.end(); ++it) {
        (*it)->contract(&e);
    }
    return prune(e);
}

// Vérifie si le Noeud passé en paramètre est une solution
bool BranchAndPrune::isSolution(Node node) {
    
    //bool ret = true;
    
    // On vérifie que tous les domaines de node sont réduit à 1
    if(node.areAllVariablesAffected()) {
        
        // On vérifie que node respecte bien toutes les contraintes
        // Toutefois inutile puisque le noeud passé en paramètre est le résultat du pruning qui respectera
        // toujours ces contraintes.
       /* for (vector<Constraints*>::iterator it = constraintSet.begin(); it != constraintSet.end(); ++it) {
            if (!(*it)->check(node)) {
                ret = false;
            }
        }*/
        return true;

    }
    else {
        //ret = false;
        return false;
    }
    
    //return ret;
}

void BranchAndPrune::printResult() {
    if (results.size() > 0) {
        for (int i = 0; i < results.size(); ++i) {
            results[i].print();
        }
    }
    else {
        cout << "Pas de solutions trouvées pour le problème courant." << endl;
    }
}



