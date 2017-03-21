//
//  AllDifferent.cpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 14/03/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#include "AllDifferent.hpp"

AllDifferent::AllDifferent(){
    
}

bool AllDifferent::check(Node e) {
    
    vector<Domain> domainStudy = e.getDomainList();
    for (int i = 0; i < domainStudy.size(); ++i) {
        
        // On vérifie que le domaine soit bien réduit à 1 (et donc que la variable s'est vue assignée une valeur)
        if (domainStudy[i].size() == 1) {
            
            for (int y = i+1; y < domainStudy.size(); ++y) {
                // On vérifie qu'on ne soit pas "outOfBound"
                if (y < domainStudy.size()) {
                    // On vérifie que les domaines suivants sont différents (du moins pour les variables assignées)
                    if ( (domainStudy[y].size() == 1) && (domainStudy[y].contains(domainStudy[i].front())) ) {
                        return false;
                    }
                }
                
            }
        }
        
    }
    return true;
}

void AllDifferent::contract(Node* e) {
    
    // Pour chaque domaine du Noeud réduit à 1
    for (int i = 0; i < e->getDomainList().size(); ++i) {
        if (e->getDomainList()[i].size() == 1) {
            // On enlève de tous les autres la value
            int valToSup = e->getDomainList()[i].front();
            e->supElementFromEveryDomain(valToSup);
        }
    }
}
