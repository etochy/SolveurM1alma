#ifndef Queen_hpp
#define Queen_hpp

#include <stdio.h>
#include "Constraints.hpp"

class Queen : public Constraints {
    
public:
    Queen(int queenBoardSize);
    bool check(Node e);
    void contract(Node* e);
private:
    
    // Taille du problème
    int boardSize;
};
#endif /* Queen_hpp */
