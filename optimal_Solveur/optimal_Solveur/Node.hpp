//
//  Node.hpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 17/02/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Domain.hpp"
#include <vector>

class Node {
public:
    Node();
    ~Node();
    
    void add(Domain domain); // Ajoute un domaine à nodeList.
    void copy(Node node); // Le Noeud courant devient une copie du Noeud passé en paramètre.
    
    bool isEmpty(); // Renvoie vrai si le Noeud est vide, faux sinon.
    bool areAllVariablesAffected(); // Renvoie vrai si tous les domaines de domainList sont réduit à 1.
    
    int getSmallerDomain(); // Renvoie l'indice du plus petit domaine de domainList.
    vector<Domain> getDomainList();
    
    bool supElementFromEveryDomain(int element); // Supprime l'element des domaines (sauf ceux réduit à 1).
    void print();
    
    void replace(int nombreDomaine, int element); // Remplace le domaine avec l'élément.
    void suppress(int domainNumber, int element);
    
private:
    vector<Domain> domainList;
};
#endif /* Node_hpp */
