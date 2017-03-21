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
    domainList.clear();
    domainList = node.getDomainList();
}

bool Node::isEmpty() {
    return domainList.empty();
}

bool Node::areAllVariablesAffected() {
    for (vector<Domain>::iterator it = domainList.begin(); it != domainList.end(); ++it) {
        if (it->size() != 1) {
            return false;
        }
    }
    return true;
}

vector<Domain>::iterator Node::getSmallerDomain() {
    vector<Domain>::iterator ret = domainList.begin();
    for (vector<Domain>::iterator it = domainList.begin(); it != domainList.end(); ++it) {
        if (!(ret->size() > 1) && it->size() > 1) {
            ret = it;
        }
        if ((it->size() < ret->size()) && it->size() > 1) {
            ret = it;
        }
    }
    
    if (!(ret->size() > 1)) {
        // Renvoyer un nullptr
    }
        
    return ret;
}

vector<Domain> Node::getDomainList() {
    return domainList;
}

void Node::supElementFromEveryDomain(int element) {
    for (vector<Domain>::iterator it = domainList.begin(); it != domainList.end(); ++it) {
        if (it->size() > 1) {
            it->suppress(element);
        }
    }
}

void Node::print() {
    cout << " Noeud : { ";
    for (int i = 0; i < domainList.size(); ++i) {
        domainList[i].print();
    }
    cout << " }" << endl;
}
