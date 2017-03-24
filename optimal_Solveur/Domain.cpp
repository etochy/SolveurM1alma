//
//  Domain.cpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 17/02/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#include "Domain.hpp"

Domain::Domain() {
    
}

Domain::~Domain() {
    
}

void Domain::add(int element) {
    if (!contains(element)) {
        integerSet.push_back(element);
        sort();
    }
}

void Domain::copy(Domain domain) {
    //integerSet.clear();
    integerSet = domain.getIntegerSet();
}

void Domain::replace(int element) {
    integerSet.clear();
    integerSet.push_back(element);
}

bool Domain::suppress(int element) {
    
    bool ret = false;
    
    int el;
    for (vector<int>::iterator it = integerSet.begin(); it != integerSet.end();) {
        el = *it;
        if (el == element) {
            it = integerSet.erase(it);
            ret = true;
        }
        else {
           ++it;
        }
    }
    
    return ret;
    
    /* Suppression sans iterator
    for (int i = 0; i < integerSet.size(); ++i) {
        if (integerSet[i] == element) {
            integerSet[i] = back();
        }
    }
    pop_back();
    sort();
    */
}

int Domain::pop() {
    int ret = front();
    suppress(ret);
    return ret;
}

int Domain::pop_back() {
    int ret = back();
    suppress(ret);
    return ret;
}

int Domain::front() {
    return integerSet.front();
}

int Domain::back() {
    return integerSet.back();
}

int Domain::size() {
    return integerSet.size();
}

vector<int> Domain::getIntegerSet() {
    return integerSet;
}

void Domain::sort() {
    std::sort(integerSet.begin(), integerSet.end());
}

bool Domain::contains(int element){
    for (int i = 0; i < integerSet.size(); ++i) {
        if (integerSet[i] == element) {
            return true;
        }
    }
    return false;
}

void Domain::push(int element) {
    integerSet.push_back(element);
}

void Domain::print() {
    cout << "{";
    for (int i = 0; i < integerSet.size(); ++i) {
        cout << integerSet[i];
    }
    cout << "}";
}

