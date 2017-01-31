#include "backtracking.hpp"

Backtracking::Backtracking(){
	int randNumber = 0;
	totalNode = 0;
	
	srand (time(NULL));

	/*
	nbMachine = 5;
	nbTask = 4;
	*/

	nbMachine = rand() % 10 + 5;
	nbTask = rand() % nbMachine; //The number of task must be lower than the number of machine

	std::cout << "Number of machine : " << nbMachine << " ; Number of task : " << nbTask << std::endl;
	
	affectOrder = new int[nbTask];
	mat = new int[nbMachine * nbTask];

	//Initialize the matrice

	/*
	for (int i = 0; i < (nbMachine * nbTask); ++i)
		mat[i] = 0;
	*/

	for (int i = 0; i < nbTask; ++i){
		for (int j = 0; j < nbMachine; ++j){
			randNumber = rand() % 10;

			if(randNumber <= 4)
				mat[nbMachine * i + j] = 0;
			else
				mat[nbMachine * i + j] = 1;
		}
	}

	/*
	mat[nbMachine * 0 + 1] = 1;
	mat[nbMachine * 0 + 2] = 1;
	mat[nbMachine * 0 + 3] = 1;
	mat[nbMachine * 0 + 4] = 1;

	mat[nbMachine * 1 + 1] = 1;
	mat[nbMachine * 1 + 2] = 1;

	mat[nbMachine * 2 + 0] = 1;
	mat[nbMachine * 2 + 1] = 1;
	mat[nbMachine * 2 + 2] = 1;
	mat[nbMachine * 2 + 3] = 1;

	mat[nbMachine * 3 + 1] = 1;
	mat[nbMachine * 3 + 2] = 1;
	*/

	//Define the affectation order

	std::cout << "Type the task assignment order : " << std::endl;

	for (int i = 0; i < nbTask; ++i){
		int task = 0;
		std::cout << "Task " << i + 1 << " : ";
		std::cin >> task;

		while(task < 0 || task >= nbTask){
			std::cout << "Error this task does not exist." << std::endl;
			std::cout << "Task " << i + 1 << " : ";
			std::cin >> task;
		}

		affectOrder[i] = task;
	}
}

Backtracking::~Backtracking(){
	delete mat;
}

void Backtracking::run(int node, std::vector<char> solution){
	if(node == nbTask){
		result.push_back(solution);
	}
	else{
		for (int i = 0; i < nbMachine; ++i)	{
			if(mat[nbMachine * affectOrder[node] + i] == 1 && !contains('A' + i, solution)){
				solution.push_back('A' + i);
				run(node + 1, solution);
				solution.pop_back();

				totalNode++;
			}
		}
	}
}

void Backtracking::printResult(){

	std::cout << "Writing result in \"out.txt\"..." << std::endl;

	std::ofstream file("out.txt", std::ios::out | std::ios::trunc);

	if(file){
		file << "----- MATRICE  -----" << std::endl;
		file << "********************" << std::endl;

		for (int i = 0; i < nbTask; ++i){
			for (int j = 0; j < nbMachine; ++j){
				file << "  " << mat[nbMachine * i + j];
			}

			file << std::endl;
		}

		file << "********************" << std::endl;
		file << std::endl;

		file << "----- RESULT -----" << std::endl;

		file << "Assignment order : ";
		for(int i = 0; i < nbTask; ++i)
			file << affectOrder[i] << " ";

		file << std::endl;
		file << "Number of solution : " << result.size() << std::endl;
		file << "Number of node : " << totalNode << std::endl << std::endl;

		for (int i = 0; i < result.size(); ++i){
			file << "Solution " << i + 1 << " : ";

			for (int j = 0; j < result[i].size(); ++j){
				file << result[i][j] << " ";
			}

			file << std::endl;
		}

		file.close();
    }
    else{
        std::cerr << "Error when open the file." << std::endl;
    }
}

bool Backtracking::contains(char item, std::vector<char> &vector){
	return std::find(vector.begin(), vector.end(), item) != vector.end();
}