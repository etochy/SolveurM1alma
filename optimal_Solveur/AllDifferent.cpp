#include "AllDifferent.hpp"

AllDifferent::AllDifferent(vector<int> index):domainIndex(index){
    
}

/**
 * @brief Vérifie qu'un noeud respecte la contrainte "allDifferent".
 * @param e Le noeud à vérifier.
 * @return Vrai si le noeud respecte la contrainte, faux sinon.
 * @note Un domaine temporaire est utilisé pour contenir les différentes valeurs des domaines réduit à 1.
 **/
bool AllDifferent::check(Node e) {
    
    Domain tmpList;
    vector<Domain> domainStudy = e.getDomainList();
    
    for (int i : domainIndex) {
        if (domainStudy[i].size() == 1) {
            if (!(tmpList.contains(domainStudy[i].front()))) {
                tmpList.push(domainStudy[i].front());
            }
            else {
                return false;
            }
        }
    }
    
    
    return true;
}

/**
 * @brief Contracte les domaines d'un Noeud en fonction de la contrainte "allDifferent".
 * @param e Le pointeur vers le Noeud devant subir une contraction.
 **/
void AllDifferent::contract(Node* e) {
    
    bool modification = false;
    
    for (Domain d : e->getDomainList()) {
        if (d.size() == 1) {
            int valToSup = d.front();
            if (e->supElementFromEveryDomain(valToSup)) {
                modification = true;
            }
        }
    }
    
    // Tant qu'une modification est effectuée sur les domaines du Noeud
    // on relance une contraction
    if (modification) {
        contract(e);
    }
}
