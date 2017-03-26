#ifndef AllDifferent_hpp
#define AllDifferent_hpp

#include <stdio.h>
#include "Constraints.hpp"

class AllDifferent : public Constraints {
public:
    AllDifferent(vector<int> index);
    bool check(Node e);
    void contract(Node* e);
private:
    
    // Liste d'index représentant les domaines
    // sur lequel la contrainte AllDifferent doit être appliquée.
    vector<int> domainIndex;
};

#endif /* AllDifferent_hpp */
