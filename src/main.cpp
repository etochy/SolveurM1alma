#include "backtracking.hpp"

int main(void){
	std::vector<char> solution;

	Backtracking backtracking;
	backtracking.run(0, solution);
	backtracking.printResult();

	return 0;
}