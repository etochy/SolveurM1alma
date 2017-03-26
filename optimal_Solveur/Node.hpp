#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Domain.hpp"
#include <vector>

class Node {
public:
    
    Node();
    
    ~Node();
    
    // Ajoute un domaine à dans domainList
    void add(Domain domain);
    
    // Le Noeud courant devient une copie du Noeud passé en paramètre
    void copy(Node node);
    
    // Renvoie vrai si le Noeud est vide, faux sinon
    bool isEmpty();
    
    // Renvoie vrai si tous les domaines de domainList sont réduit à 1
    bool areAllVariablesAffected();
    
    // Renvoie l'indice du plus petit domaine de domainList
    int getSmallerDomain();
    
    // Getter pour domainList
    vector<Domain> getDomainList();
    
    // Supprime "element" des domaines (sauf ceux réduit à 1)
    bool supElementFromEveryDomain(int element);
    
    // Affiche dans la console la liste des Domaines
    void print();
    
    // Remplace les valeurs de domainList[domainNumber] par "element".
    void replace(int domainNumber, int element);
    
    // Supprime la valeur "element" du domaine indiqué par l'indice domainNumber (domaine[domainNumber])
    void suppress(int domainNumber, int element);
    
private:
    
    // La liste des domaines
    vector<Domain> domainList;
};
#endif /* Node_hpp */
