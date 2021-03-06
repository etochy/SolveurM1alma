#include "BranchAndPrune.hpp"

/**
 * @brief Initialise une résolution de problèmes.
 * @param DSet Le premier Noeud à traiter (contient la liste de tous les domaines complets)
 * @param CSet La liste des contraintes devant être respectées par le solveur
 * @param everySolutions Détermine si toutes les solutions doivent être trouvées
 **/
BranchAndPrune::BranchAndPrune(Node DSet, vector<Constraints*> CSet, bool everySolutions):constraintSet(CSet), displayAllSolutions(everySolutions) {
    nodes.push_back(DSet);
}

BranchAndPrune::~BranchAndPrune() {
    
}

/**
 * @brief Lance la résolution du problème.
 * @note Reprise quasi identique de l'algorithme présenté dans le sujet de projet.
 **/
int BranchAndPrune::run() {
    
    Node currentNode;
    
    Node pruningResult;
    
    int smallerDomain = 0;
    
    while (!nodes.empty()) {
        
        // On étudie le premier élément de notre liste de Noeuds
        currentNode = *nodes.begin();
        
        // On le supprime de notre liste
        nodes.erase(nodes.begin());
        
        // On effectue notre opération de pruning en fonction de notre ensemble de contraintes
        pruningResult = forwardChecking(currentNode);
        
        if (!pruningResult.isEmpty()) {
            
            if (isSolution(pruningResult)) {
                results.push_back(pruningResult);
                if (!displayAllSolutions) {
                    return 0;
                }
            }
            else {
                
                // On récupère le plus petit domaine du résultat du pruning
                smallerDomain = pruningResult.getSmallerDomain();
                
                // Pour chacun des éléments dans le domaine "smallerDomain"
                for (int cp : pruningResult.getDomainList()[smallerDomain].getIntegerSet()) {
                    
                    pruningResult.replace(smallerDomain, cp);
                    
                    if (!forwardChecking(pruningResult).isEmpty()) {
                        nodes.push_back(pruningResult);
                    }
                }
            }
        }
        
    }
    
    return 0;
}

/**
 * @brief Vérifie qu'un Noeud respecte toutes les contraintes du problème.
 * @param e Le Noeud devant être vérifié.
 **/
Node BranchAndPrune::prune(Node e) {
    
    for (Constraints* c : constraintSet) {
        if (!(c->check(e))) {
            return Node();
        }
    }
    return e;
}

/**
 * @brief Réalise un "forward checking" sur un Noeud.
 * @param e Le Noeud devant subir le "forward checking".
 * @return Le Noeud contracté ou un Noeud vide si "e" ne respecte plus les contraintes.
 **/
Node BranchAndPrune::forwardChecking(Node e) {
    
    for (Constraints* c : constraintSet) {
        c->contract(&e);
    }
    
    // On vérifie qu'aucun domaines ne soient réduit à 0.
    for(Domain d : e.getDomainList()) {
        if (d.size() < 1) {
            return Node();
        }
    }
    return prune(e);
}

/**
 * @brief Vérifie si le Noeud passé en paramètre est une solution du problème.
 * @param node Le Noeud à vérifier.
 * @return Vrai si c'est une solution, faux sinon.
 **/
bool BranchAndPrune::isSolution(Node node) {
    
    // On vérifie que tous les domaines de "node" soient réduit à 1
    if(node.areAllVariablesAffected()) {
        return true;

    }
    else {
        return false;
    }
}

/**
 * @brief Affiche dans la console les résultats trouvés.
 **/
void BranchAndPrune::printResult() {
    if (results.size() > 0) {
        for (int i = 0; i < results.size(); ++i) {
            results[i].print();
        }
        cout<<"Total : "<<results.size()<<endl;
    }
    else {
        cout << "Pas de solutions trouvées pour le problème courant." << endl;
    }
}



