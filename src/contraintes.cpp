#include "contraintes.hpp"

Contraintes::Contraintes(int boardsize) {
    queensize = boardsize;
}

Contraintes::~Contraintes() {
    
}

bool Contraintes::verify(list<list<int>> domaines) {
    
    list<list<int>>::iterator it = domaines.begin();
    int jcount = 0;
    int icount = 0;
    
    // Pour chaque lignes, on vérifie qu'il n'y ait pas deux domaines réduit à 1
    for (int i = 0; i < queensize; ++i) {
        for (int j = 0; j< queensize; ++j) {
            if ((it->size() == 1) && it->front() == 1) {
                ++jcount;
                cout<<"jcount : "<<jcount<<endl;
            }
            ++it;
        }
        if (jcount > 1) {
            cout<<"Verify : False (jcount)"<<endl;
            return false;
        }
        jcount = 0;
    }
    
    // Pour chaque colonnes, on vérifie qu'il n'y ait pas deux domaines réduit à 1.
    for (int colonnes = 0; colonnes < queensize; ++colonnes) {
        it = domaines.begin();
        for (int k = 0; k < colonnes; ++k) {
            ++it;
        }
        
        for (int i = 0; i < queensize - 1; ++i) {
            
            if ((it->size() == 1) && (it->front() == 1)) {
                ++icount;
                cout<<"icount : "<<icount<<endl;
            }
            
            for (int j = 0; j < queensize; ++j) {
                ++it;
            }
        }
        
        if (icount > 1) {
            cout<<"Verify : False (icount)"<<endl;
            return false;
        }
        
        icount = 0;
    }
    
    
    // Pour chaque diagonnales
        // TODO
    cout<<"Verify : True"<<endl;
	return true;
}
