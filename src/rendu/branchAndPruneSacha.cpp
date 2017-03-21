#include "branchAndPruneSacha.hpp"

BranchAndPruneSacha::BranchAndPruneSacha(int sizeQueenBoard){
	// Initialisation d'une matrice pour le problème des reines
		// Nous avons donc sizeQueenBoard * sizeQueenBoard variables
	mat = new int[sizeQueenBoard * sizeQueenBoard];

	// ( On ajoute toutes ces variables à l'ensemble X (ou X est l'ensemble des variables). )
	variables = {}; // Ensemble X

	// Les valeurs possibles de ces variables sont 0 ou 1. Donc Di = {0,1} (i allant de 1 au nombre de variables).
		// Donc on ajoute Di  à D.

	list<int> di{0,1};
	for (int i = 0; i < sizeQueenBoard * sizeQueenBoard; ++i)
	{
        cout<<"Filling domains with basic di domain"<<endl;
		domains.push_back(di);
	}

	// On créer un ensemble de contraintes
	constraints = {};
    Contraintes queen(sizeQueenBoard);
    constraints.push_back(queen);

}

BranchAndPruneSacha::~BranchAndPruneSacha() {
    
}

int BranchAndPruneSacha::run(){
    cout<<"Execution du run !"<<endl;
	list<list<list<int>>> nodes{};

	nodes.push_back(domains);

	while(!nodes.empty()) {
        //cout<<"Passage dans la jolie boucle TQ"<<endl;
		list<list<int>> e = nodes.front();
		nodes.pop_front();
		list<list<int>> f = prune(e, constraints); //prune doit renvoyer un ens. vide si simple backtracking

		if (f.empty()) {
			// F n'est pas solution
            cout<<"Discarding f"<<endl;
		}
		else {
            // Si F est une solution, on l'ajoute à notre liste résultat puis on s'arrête.
			if (isValid(f))
			{
                for (list<list<int>>::iterator it = f.begin(); it != f.end(); ++it) {
                    result.push_back(it->front());
                    cout<<it->front();
                }
                cout<<"/"<<endl;
                return 0;
			}
            else {
                list<int> smallerDomain = *f.begin(); // Dxi
                int count = 0; // simple compteur pour déterminer la position de xi
                int xi = 0; //position de xi dans F
                
                // On cherche la variable (xi) avec le plus petit domaine (Dxi) dans F.
                for (list<list<int>>::iterator it = f.begin(); it != f.end(); ++it) {
                    if (smallerDomain.size() == 1) {
                        smallerDomain.clear();
                        smallerDomain.assign(it->begin(), it->end());
                    }
                    if (it->size() < smallerDomain.size()) {
                        smallerDomain.clear();
                        smallerDomain.assign(it->begin(), it->end());
                        xi = count;
                    }
                    ++count;
                }
                
                if (smallerDomain.size() > 1) {
                    // Pour chaque valeur "a" dans smallerDomain (Dxi)
                    for (list<int>::iterator it = smallerDomain.begin(); it != smallerDomain.end(); ++it) {
                        
                        // Une copie G de F est faite
                        list<list<int>> g;
                        g.assign(f.begin(), f.end());
                        
                        count = 0;
                        // On assigne à xi "a" dans G. Dxi est donc réduit à "a".
                        for (list<list<int>>::iterator itg = g.begin(); itg != g.end(); ++itg) {
                            if (count == xi) {
                                itg->clear();
                                itg->push_back(*it);
                                cout<<"replacing value in domain : "<<itg->front()<<endl;
                                
                            }
                            ++count;
                        }
                        
                        // G est ajouté à nodes.
                        nodes.push_back(g);
                    }
                }
            }
		}
	}
    
    return -1;
}

bool BranchAndPruneSacha::isValid(list<list<int>> ensDom) {

	// On verifie que pour tout les éléments de ensDOm, seule une valeur réside dans ceux-ci.
    for (list<list<int>>::iterator it = ensDom.begin(); it != ensDom.end(); ++it){
		if (it->size() != 1){
			return false;
		}
	}
	// Ensuite on vérifie bien que l'ensemble des valeurs forme bien une affectation satisfiable.
		// TODO
	return true;
}

list<list<int>> BranchAndPruneSacha::prune(list<list<int>> domains, list<Contraintes> cons) {
    for (list<Contraintes>::iterator it = cons.begin(); it != cons.end(); ++it) {
        if (!it->verify(domains)) {
            cout<<"Delete Node"<<endl;
            return {};
        }
    }
    return domains;
}
