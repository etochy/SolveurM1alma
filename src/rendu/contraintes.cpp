#include "contraintes.hpp"

Contraintes::Contraintes(int boardsize) {
    queensize = boardsize;
}

Contraintes::~Contraintes() {
    
}

// Simple vérification pour le jeu des reines
// Renvoie vrai si l'ensemble des domaines est "correct" et donc traitable
// Faux sinon
bool Contraintes::verify(list<list<int>> domaines) {
    
    cout<<"Vérification d'un domaine en cours"<<endl;
    
    list<list<int>>::iterator it = domaines.begin();
    int lineCount = 0;
    int nbQueenLigne = 0;
    
    for (int i = 0; i < domaines.size(); ++i) {
        
        cout<<"Domaine en cours de traitement : {";
        for (list<int>::iterator list = it->begin(); list != it->end(); ++list) {
            cout<<*list;
        }
        cout<<"}"<<endl;
        
        if ((it->size() == 1 ) && (it->front() == 1)) {
            ++nbQueenLigne;
        }
        
        if (nbQueenLigne > 1) {
            cout<<"Elimination d'un noeud"<<endl;
            return false;
        }
        
        // Signifie que l'on change de ligne
        // On réinitialise alors le compteur de reines
        if (lineCount == queensize - 1) {
            lineCount = 0;
            nbQueenLigne = 0;
        }
        ++it;
    }
    
    return true;
}
