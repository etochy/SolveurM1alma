#ifndef SendMoreMoney_hpp
#define SendMoreMoney_hpp

#include <stdio.h>
#include "Constraints.hpp"
#include <math.h>

class SendMoreMoney : public Constraints {
    
public:
    SendMoreMoney();
    bool check(Node e);
    void contract(Node* e);
private:
};
#endif /* SendMoreMoney_hpp */
