#include <iostream> 

void BranchAndPrune (X, C, D){
	List<nodes> L; // list of nodes
	
	//begin
	L.push(D);
	while (L is not empty){
		E = L[0];
		L.delete[0];
		F = Prune(E,C);
		if (F.size() == 0)
			discard F; //oublié F
		else{
			if(F is a solution){
				process F; //Ajouter F dans la liste des solutions
			}
			else{
				x[i] ← variable with smallest domain in F
				let dx[i] be the domain of x[i] in F
			}
			for (each v in dx[i]) {
				G = F;
				set the domain of x i to {v} in G
				push G in L
			}
		}
	}
}

