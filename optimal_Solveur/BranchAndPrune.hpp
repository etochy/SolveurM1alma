#ifndef BranchAndPrune_hpp
#define BranchAndPrune_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Constraints.hpp"
#include "Queen.hpp"
#include "AllDifferent.hpp"
#include "SendMoreMoney.hpp"
#include "Domain.hpp"
#include "Node.hpp"

using namespace std;

class BranchAndPrune {
public:
    
    // Initialise les ensembles domaines et contraintes de notre problème (D et C)
    // et indique si le programme doit afficher toutes les solutions
    BranchAndPrune(Node DSet, vector<Constraints*> CSet, bool displayAllSolutions);
    ~BranchAndPrune();
    
    // Lance l'algorithme de Branch And Prune
    int run();
    
    // Affiche les résultats trouvés
    void printResult();
    
    // Détermine si un Noeud est une solution
    bool isSolution(Node node);
    
    // Effectue un simble backtracking sur un Noeud
    Node prune(Node e);
    
    // Effectue une contraction des domaines d'un Noeud
    // Puis une vérification de contraintes.
    Node forwardChecking(Node e);
    
private:
    
    // L'ensemble des Noeuds à traiter
    vector<Node> nodes;
    
    // Le premier ensemble de Domaines à étudier
    vector<Domain> domainSet;
    
    // L'ensemble des contraintes devant être respectées
    vector<Constraints*> constraintSet;
    
    // Les résultats de l'algorithme
    vector<Node> results;
    
    // Affiche toutes les solutions lorsque ce booléen est à Vrai
    // une seule sinon
    bool displayAllSolutions;
};

#endif /* BranchAndPrune_hpp */
