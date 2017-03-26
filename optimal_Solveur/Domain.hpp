#ifndef Domain_hpp
#define Domain_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
class Domain {
public:
    
    Domain();
    
    ~Domain();
    
    //Ajoute l'élément de façon ordonnée à integerSet (liste des valeurs du domaine)
    void add(int element);
    
    //Le domaine courant devient la copie du domaine en paramètre.
    void copy(Domain domain);
    
    // Remplace les éléments contenus integerSet par "element".
    void replace(int element);
    
    // Renvoie vrai si integerSet contient l'élément passé en paramètre
    // Faux sinon
    bool contains(int element);
    
    // Supprime "element" de integerSet
    bool suppress(int element);
    
    // Supprime et renvoie le premier élément d'integerSet
    int pop();
    
    // Supprime et renvoie le dernier élément d'integerSet
    int pop_back();
    
    // Renvoie le premier élément d'integerSet
    int front();
    
    // Renvoie le dernier élément d'integerSet
    int back();
    
    // Renvoie la taille de integerSet
    int size();
    
    // Getter pour integerSet
    vector<int> getIntegerSet();
    
    // Affiche dans la console la liste des valeurs contenues dans integerSet
    void print();
    
    // Ordonne integerSet (ordre croissant)
    void sort();
    
    // Ajoute un element sans conditions dans integerSet
    void push(int element);
    
private:
    
    // Représente la liste des valeurs d'un domaine
    vector<int> integerSet;
};
#endif /* Domain_hpp */
