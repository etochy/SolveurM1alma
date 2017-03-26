#include <iostream>
#include "BranchAndPrune.hpp"

int main(int argc, const char * argv[]) {
   
    
    string problemType;
    std::cout << "Entrez le problème que vous souhaitez résoudre :" << std::endl;
    std::cout << "- Queen" << std::endl;
    std::cout << "- SendMoreMoney" << std::endl;
    std::cin >> problemType;
    
    if (problemType == "Queen") {
        
        string allSol;
        std::cout << "Souhaitez vous afficher toutes les solutions (1 ou *) :" << std::endl;
        std::cin >> allSol;
        
        // Construction des domaines pour le problème des reines__________________________
        Node domainSet;
        Domain queenDomain;
        int queenBoardSize; // Taille de la grille pour le problème des reines
        
        std::cout << "Entrez la taille pour le problème des reines :" << std::endl;
        std::cin >> queenBoardSize;
        
        // Construction d'un domaine type pour le problème des reines
        // Di = {0, 1, ..., n} (avec n = queenBoardSize)
        for (int i = 0; i < queenBoardSize; ++i) {
            queenDomain.add(i);
        }
        
        // Construction d'un noeud contenant n domaines type (cf. Di)
        for (int i = 0; i < queenBoardSize; ++i) {
            Domain cp = queenDomain;
            domainSet.add(cp);
        }
        
        // Ajout des différentes contraintes pour le problème des reines
        vector<Constraints*> cons;
        Constraints *verifDiagonale = new Queen(queenBoardSize);
        
        vector<int> index;
        for (int i = 0; i < queenBoardSize; ++i) {
            index.push_back(i);
        }
        Constraints *allDiff = new AllDifferent(index);
        
        cons.push_back(verifDiagonale);
        cons.push_back(allDiff);
        
        
        if (allSol == "1") {
            // Créer un objet de type BranchAndPrune et exécute l'algorithme
            BranchAndPrune bap(domainSet, cons, false);
            
            clock_t deb = clock();
            
            bap.run();
            
            clock_t fin = clock();
            
            bap.printResult();
            cout << (double)(fin-deb)/CLOCKS_PER_SEC<<endl;
        }
        
        else if (allSol == "*") {
            // Créer un objet de type BranchAndPrune et exécute l'algorithme
            BranchAndPrune bap(domainSet, cons, true);
            
            clock_t deb = clock();
            
            bap.run();
            
            clock_t fin = clock();
            
            bap.printResult();
            cout << (double)(fin-deb)/CLOCKS_PER_SEC<<endl;
        }
        
        
        
        
    }
    
    else if (problemType == "SendMoreMoney") {
        
        string allSol;
        std::cout << "Souhaitez vous afficher toutes les solutions (1 ou *) :" << std::endl;
        std::cin >> allSol;
        
        
        // _________________Construction des domaines pour le problème "SENDMOREMONEY" ___________________
        Node domainSet2;
        Domain smmDomain; // Domaine pour les variables "SEND MORE MONEY"
        Domain retDomain; // Domaine pour les variables de retenue
        
        // Construction d'un domaine type pour les variables {S, E, N, D, M, O, R, Y}
        for (int i=0; i <= 9; ++i) {
            smmDomain.add(i);
        }
        
        // Construcion d'un domaine pour les variables de retenues
        retDomain.add(0);
        retDomain.add(1);
        
        // Construction d'un noeud contenant 8 domaines de variables {S, E, N, D, M, O, R, Y}
        for (int i=0; i < 8; ++i) {
            domainSet2.add(smmDomain);
        }
        // On y ajoute 4 variables pour les retenues
        for (int i=0; i < 4; ++i) {
            domainSet2.add(retDomain);
        }
        
        // Ajout des différentes contraintes pour le problème SEND MORE MONEY
        vector<Constraints*> cons2;
        vector<int> index2;
        for (int i = 0; i < 8; ++i) {
            index2.push_back(i);
        }
        Constraints* allDiff2 = new AllDifferent(index2);
        Constraints* smmoney = new SendMoreMoney();
        
        cons2.push_back(allDiff2);
        cons2.push_back(smmoney);
        
        if (allSol == "1") {
            // Création d'un objet BranchAndPrune et exécution de l'algorithme
            BranchAndPrune bap2(domainSet2, cons2, false);
            
            clock_t deb = clock();
            bap2.run();
            clock_t fin = clock();
            
            bap2.printResult();
            cout << (double)(fin-deb)/CLOCKS_PER_SEC<<endl;

        }
        
        else if (allSol == "*") {
            // Création d'un objet BranchAndPrune et exécution de l'algorithme
            BranchAndPrune bap2(domainSet2, cons2, true);
            
            clock_t deb = clock();
            bap2.run();
            clock_t fin = clock();
            
            bap2.printResult();
            cout << (double)(fin-deb)/CLOCKS_PER_SEC<<endl;

        }
        
    }
    
    else {
        cout<<"Veuillez entrer un nom de problème valide"<<endl;
    }
}
