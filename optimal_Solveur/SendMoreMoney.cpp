#include "SendMoreMoney.hpp"

SendMoreMoney::SendMoreMoney() {
    
}

/**
 * @brief Vérifie qu'un noeud respecte les équations du problème "Send More Money".
 * @param e Le noeud dont les domaines doivent être vérifiés.
 * @return Vrai si le noeud respecte la contrainte, faux sinon.
 * @note Ici, on attend que tous les domaines soient réduit à 1 pour ensuite vérifier que les équations soient respectées.
 **/
bool SendMoreMoney::check(Node e) {
    
    vector<Domain> copyForCheck = e.getDomainList();
    if (e.areAllVariablesAffected()) {
        cout<<"All variables affected !"<<endl;
        if ( copyForCheck[8].front() != floor((copyForCheck[3].front() + copyForCheck[1].front())/10) ) {
            return false;
        }
        
        if ( copyForCheck[7].front() != (copyForCheck[3].front() + copyForCheck[1].front())%10 ) {
            return false;
        }
        
        if ( copyForCheck[9].front() != floor((copyForCheck[2].front() + copyForCheck[6].front() + copyForCheck[8].front())/10) ) {
            return false;
        }
        
        if ( copyForCheck[1].front() != (copyForCheck[2].front() + copyForCheck[6].front() + copyForCheck[8].front())%10 ) {
            return false;
        }
        
        if ( copyForCheck[10].front() != floor((copyForCheck[1].front() + copyForCheck[5].front() + copyForCheck[9].front())/10) ) {
            return false;
        }
        
        if ( copyForCheck[2].front() != (copyForCheck[1].front() + copyForCheck[5].front() + copyForCheck[9].front())%10 ) {
            return false;
        }
        
        if ( copyForCheck[11].front() != floor((copyForCheck[0].front() + copyForCheck[4].front() + copyForCheck[10].front())/10) ) {
            return false;
        }
        
        if ( copyForCheck[5].front() != (copyForCheck[0].front() + copyForCheck[4].front() + copyForCheck[10].front())%10 ) {
            return false;
        }
        
        if (copyForCheck[4].front() != copyForCheck[11].front()) {
            return false;
        }
        
    }
    return true;
}

// Ici devrait figurer une contraction à l'aide d'inéquations
void SendMoreMoney::contract(Node* e) {
    
}
