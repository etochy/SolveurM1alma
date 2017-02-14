#include "branchAndPruneSacha.hpp"

BranchAndPruneSacha::BranchAndPruneSacha(int sizeQueenBoard){
	// Initialisation d'une matrice pour le problème des reines
		// Nous avons donc sizeQueenBoard * sizeQueenBoard variables
	mat = new int[sizeQueenBoard * sizeQueenBoard];

	// ( On ajoute toutes ces variables à l'ensemble X (ou X est l'ensemble des variables). )
	list<int> variables; // Ensemble X

	// Les valeurs possibles de ces variables sont 0 ou 1. Donc Di = {0,1} (i allant de 1 au nombre de variables).
		// Donc on ajoute Di  à D.

	list<int> di;
	di.push_back(0);
	di.push_back(1);

	for (int i = 0; i < variables.size(); ++i)
	{
		domains.push_back(di);
	}

	// On créer un ensemble de contraintes qu'on remplira plus tard...

	list<Contraintes> contraintes;

}

void BranchAndPruneSacha::run(){
	list<list<list<int> > > nodes;

	nodes.push_back(domains);

	while(!nodes.empty()) {
		list<list<int> > e = nodes.front();
		nodes.pop_front();
		list<list<int> > f = prune(e, contraintes);

		if (f.empty()) {
			// ici techniquement, on fait rien
			// Pas de solutions possible
		}
		else {
			if (isValid(f))
			{
				/* code */
			}
		}
	}
}

bool isValid(list<list<int> > ensDom) {
	// TODO

	// On verifie que pour tout les elem de ensDOm
	for (/* tout element de ensdom */){
		if (ensDOm[element i].size() != 1){
			return false;
		}
	}
	return true;
}