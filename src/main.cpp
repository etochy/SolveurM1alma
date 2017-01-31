#include "backtracking.hpp"
#include "prune.hpp"

int main(void){
	std::vector<char> solution;

	Prune backtracking;
	backtracking = new Backtracking;
	backtracking.run(0, solution);
	backtracking.printResult();

	return 0;
}