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
    integerSet = domain.getIntegerSet();
}

void Domain::replace(int element) {
    integerSet.clear();
    integerSet.push_back(element);
}

bool Domain::suppress(int element) {
    
    bool found = false;
    int begin = 0;
    int end = integerSet.size() - 1;
    int mid = 0;
    
    while ( (!found) && (end - begin >= 0) ) {
        mid = begin + ceil((end - begin) / 2);
        if(element < integerSet[mid]) {
            end = mid - 1;
        }
        else if (element > integerSet[mid]) {
            begin = mid + 1;
        }
        else {
            found = true;
            integerSet.erase(integerSet.begin()+mid);
        }
    }
    
    return found;
    
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
    
    bool found = false;
    int begin = 0;
    int end = integerSet.size() - 1;
    int mid = 0;
    
    while ( (!found) && (end - begin >= 0) ) {
        mid = begin + ceil((end - begin) / 2);
        if(element < integerSet[mid]) {
            end = mid - 1;
        }
        else if (element > integerSet[mid]) {
            begin = mid + 1;
        }
        else {
            found = true;
        }
    }
    
    return found;
}

void Domain::push(int element) {
    integerSet.push_back(element);
    sort();
}

void Domain::print() {
    cout << "{";
    for (int i = 0; i < integerSet.size(); ++i) {
        cout << integerSet[i];
    }
    cout << "}";
}

