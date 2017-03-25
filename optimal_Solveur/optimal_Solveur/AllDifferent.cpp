//
//  AllDifferent.cpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 14/03/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#include "AllDifferent.hpp"

AllDifferent::AllDifferent(vector<int> index):domainIndex(index){
    
}

bool AllDifferent::check(Node e) {
    
    Domain tmpList;
    vector<Domain> domainStudy = e.getDomainList();
    
    /*for (int i = 0; i < domainIndex.size(); ++i) {
        if (domainStudy[domainIndex[i]].size() == 1) {
            if (!(tmpList.contains(domainStudy[domainIndex[i]].front()))) {
                tmpList.push(domainStudy[i].front());
            }
            else {
                return false;
            }
        }
    }*/
    
    for (int i : domainIndex) {
        if (domainStudy[i].size() == 1) {
            if (!(tmpList.contains(domainStudy[i].front()))) {
                tmpList.push(domainStudy[i].front());
            }
            else {
                return false;
            }
        }
    }
    
    
    return true;
}

void AllDifferent::contract(Node* e) {
    
    bool modification = false;
    
    for (Domain d : e->getDomainList()) {
        if (d.size() == 1) {
            int valToSup = d.front();
            if (e->supElementFromEveryDomain(valToSup)) {
                modification = true;
            }
        }
    }
    
    if (modification) {
        contract(e);
    }
}
