//
//  main.cpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 17/02/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#include <iostream>
#include "BranchAndPrune.hpp"

int main(int argc, const char * argv[]) {
    
    // Construction des domaines pour le problème des reines__________________________
    Node domainSet;
    Domain queenDomain;
    int queenBoardSize = 0;

    std::cout << "taille" << std::endl;
    std::cin >> queenBoardSize;

     // Taille de la grille pour le problème des reines
    
    // Construction d'un domaine type pour le problème des reines
    // Di = {0, 1, ..., n} (avec n = queenBoardSize)
    for (int i = 0; i < queenBoardSize; ++i) {
        queenDomain.add(i);
    }
    
    // Construction d'un noeud contenant n domaines type (cf. Di)
    for (int i = 0; i < queenBoardSize; ++i) {
        Domain cp = queenDomain;
        domainSet.add(cp);
    }
    
    // Ajout des différentes contraintes pour le problème des reines
    vector<Constraints*> cons;
    Constraints *verifDiagonale = new Queen(queenBoardSize);
    
    vector<int> index;
    for (int i = 0; i < queenBoardSize; ++i) {
        index.push_back(i);
    }
    Constraints *allDiff = new AllDifferent(index);
    cons.push_back(allDiff);
    cons.push_back(verifDiagonale);
    
    
    
    // Créer un objet de type BranchAndPrune et exécute l'algorithme
    BranchAndPrune bap(domainSet, cons);
    
    clock_t deb = clock();
    
    bap.run();
    
    clock_t fin = clock();
    cout << (double)(fin-deb)/CLOCKS_PER_SEC<<endl;
    
    bap.printResult();
}
