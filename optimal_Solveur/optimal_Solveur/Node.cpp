//
//  Node.cpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 17/02/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#include "Node.hpp"

Node::Node() {
    
}

Node::~Node() {
    
}

void Node::add(Domain domain) {
    domainList.push_back(domain);
}

void Node::copy(Node node) {
    domainList = node.getDomainList();
}

bool Node::isEmpty() {
    return domainList.empty();
}

bool Node::areAllVariablesAffected() {

    for (Domain d : domainList) {
        if (d.size() != 1) {
            return false;
        }
    }
    return true;
}

int Node::getSmallerDomain() {
    
    int res = 0;
    for (int i = 0; i < domainList.size(); ++i) {
        if( !(domainList[res].size() > 1) &&  domainList[i].size() > 1) {
            res = i;
        }
        
        if ( (domainList[i].size() < domainList[res].size()) && domainList[i].size() > 1) {
            res = i;
        }
    }
    return res;
}

vector<Domain> Node::getDomainList() {
    return domainList;
}

bool Node::supElementFromEveryDomain(int element) {
    
    bool ret = false;
    
    for (vector<Domain>::iterator it = domainList.begin(); it != domainList.end(); ++it) {
        if (it->size() > 1) {
            if (it->suppress(element)) {
                ret = true;
            }
        }
    }
    
    /*for (Domain d : domainList) {
        if (d.size() > 1) {
            if (d.suppress(element)) {
                ret = true;
            }
        }
    }*/
    
    return ret;
}

void Node::replace(int domainNumber, int element) {
    domainList[domainNumber].replace(element);
}

void Node::suppress(int domainNumber, int element) {
    domainList[domainNumber].suppress(element);
}

void Node::print() {
    cout << " Noeud : { ";
    for (int i = 0; i < domainList.size(); ++i) {
        domainList[i].print();
    }
    cout << " }" << endl;
}
