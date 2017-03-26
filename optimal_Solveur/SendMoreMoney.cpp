#include "SendMoreMoney.hpp"

SendMoreMoney::SendMoreMoney() {
    
}

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
    //cout<<"Returning true"<<endl;
    return true;
}

void SendMoreMoney::contract(Node* e) {
    
}
