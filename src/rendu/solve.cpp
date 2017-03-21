//
//  solve.cpp
//  solveur
//
//  Created by Sacha Loriot on 16/02/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <list>
#include "branchAndPruneSacha.hpp"

int main(void) {
    cout<<"Bonjour, simple exec du solveur avec un petit run."<<endl;
    BranchAndPruneSacha baps = BranchAndPruneSacha(3);
    baps.run();
    return 0;
}
