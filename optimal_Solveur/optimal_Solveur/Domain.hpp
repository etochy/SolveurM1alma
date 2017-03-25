//
//  Domain.hpp
//  optimal_Solveur
//
//  Created by Sacha Loriot on 17/02/2017.
//  Copyright © 2017 Sacha Loriot. All rights reserved.
//

#ifndef Domain_hpp
#define Domain_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;
class Domain {
public:
    Domain();
    ~Domain();
    void add(int element); //Ajoute l'élément de façon ordonnée à l'integerSet.
    void copy(Domain domain); //Le domaine courant devient la copie du domaine en paramètre.
    void replace(int element); // Remplace les éléments dans integerSet par "element".
    
    bool contains(int element); // Renvoie vrai si integerSet contient l'élément passé en paramètre. Faux sinon.
    
    bool suppress(int element); // Supprime l'élément d'integerSet.
    int pop(); // Supprime et renvoie le premier élément d'integerSet.
    int pop_back(); // Supprime et renvoie le dernier élément d'integerSet.
    
    int front(); // Renvoie le premier élément d'integerSet.
    int back(); // Renvoie le dernier élément d'integerSet.
    
    int size(); // Renvoie la taille de integerSet.
    vector<int> getIntegerSet();
    
    void print();
    
    void sort(); // Réordonne l'integerSet
    
    void push(int element); // Ajoute un element sans condition dans integerSet.
private:
    vector<int> integerSet;
};
#endif /* Domain_hpp */
