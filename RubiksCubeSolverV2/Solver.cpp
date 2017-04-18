#include "stdafx.h"
#include "Solver.h"



Solver::Solver(unsigned char * edge1_table, unsigned char * edge2_table, unsigned char * corner_table) {
	this->edge1_table = edge1_table;
	this->edge2_table = edge2_table;
	this->corner_table = corner_table;
}

Solver::Solver(unsigned char * phase1_corner_table, unsigned char * phase1_edge_table, unsigned char * phase1_UDSlice_table, unsigned char * phase1_FlipUDSlice_table, unsigned char * phase2_corner_table, unsigned char * phase2_edge_table, unsigned char * phase2_UDSlice_table) {
	this->phase1_corner_table = phase1_corner_table;
	this->phase1_edge_table = phase1_edge_table;
	this->phase1_UDSlice_table = phase1_UDSlice_table;
	this->phase1_FlipUDSlice_table = phase1_FlipUDSlice_table;
	this->phase2_corner_table = phase2_corner_table;
	this->phase2_edge_table = phase2_edge_table;
	this->phase2_UDSlice_table = phase2_UDSlice_table;
}

unsigned char * Solver::manualSolve(Cube cube) {
	Cube lastCube(cube);
	unsigned char solution[maxSearchLength + 2];
	unsigned char lastMove = 255;
	std::string input;

	const unsigned char * actions;
	int length = 18;
	int index = 1;
	int num;

	while (true) {
		system("cls");

		
		std::cout << "Is solved: " << (cube.isSolved() == true ? "True\n" : "False\n");
		std::cout << "Edge hash 1: " << /*TABLE_LOOKUP(edge1_table, cube.getEdgeIndex(0))*/ unsigned(edge1_table[cube.getEdgeIndex(0)]) << "\n";
		std::cout << "Edge hash 2: " << TABLE_LOOKUP(edge2_table, cube.getEdgeIndex(1)) << "\n";
		std::cout << "Corner hash: " << TABLE_LOOKUP(corner_table, cube.getCornerIndex()) << "\n";
		std::cout << "Go back: a \nStop: s\nAviable actions: \n";
		actions = cube.getAvailableMoves(lastMove);
		length = lastMove == 255 ? 18 : 15;

		for (int i = 0; i < length; i++) {
			std::cout << unsigned(actions[i]) << " ";
		}
		std::cout << "\nAction: \n";

		input = "";
		std::getline(std::cin, input);

		try {
			num = std::stoi(input);
			if (num >= 0 && num < 18) {
				lastCube = cube;
				lastMove = num;
				cube.doMove(num);
				solution[index] = num;
				index++;
			}
		} catch (std::invalid_argument e) {
			if (input == "a") {
				cube = lastCube;
				solution[index - 1] = 255;
				index--;
			}
			else if (input == "s") {
				break;
			}
		}


	}

	solution[0] = index - 1;


	return solution;
}

unsigned char * Solver::SolveCube(Cube cube)
{
	if (cube.isSolved()) return nullptr;

	maxLength = maxSearchLength;
	startCube = cube;
	hasSolution = false;

	unsigned char zero = 0;
	/*
	qdata data;
	data.cube = cube;
	data.depth = 0;
	data.index = 0;
	stack_solver(data);
	*/
	
	unsigned char temp, index;
	for (int depth = 0; depth <= 12; depth++) {
		if (hasSolution) break;
		qdata data;
		for (int i = 0; i < maxSearchLength + 1; i++) {
			data.moves[i] = 255;
		}


		



		data.cube = cube;
		data.depth = depth;
		data.index = 0;
		std::cout << "Depth: " << depth << "\n";

	/*	temp = TABLE_LOOKUP(corner_table, data.cube.getCornerIndex());
		//index = TABLE_LOOKUP(edge1_table, data.cube.getEdgeIndex(0));
		index = TABLE_LOOKUP(edge1_table, cube.getEdgeIndex(0));
		if (index > temp) temp = index;
		index = TABLE_LOOKUP(edge2_table, data.cube.getEdgeIndex(1));
		
		if (index > temp) temp = index;

		data.hash = temp; */


		phase1Search(data);

		

	}
	
	if (!hasSolution) return nullptr;
	unsigned char solution[maxSearchLength + 2];

	for (int i = 1; i < maxSearchLength + 2; i++) {
		std::cout << unsigned(currentSolution.moves[i - 1]) << " ";
		solution[i] = currentSolution.moves[i-1];
	}
	std::cout << "\n";
	solution[0] = currentSolution.index;
	return solution;
	
	
}

void Solver::phase1Search(qdata cube) {
	if (cube.depth == 0) {
		//std::cout << "0 \n";
		if (/*TABLE_LOOKUP(phase1_corner_table, cube.cube.getPhase1CornerIndex()) == 0 && TABLE_LOOKUP(phase1_edge_table, cube.cube.getPhase1EdgeIndex()) == 0 && TABLE_LOOKUP(phase1_UDSlice_table, cube.cube.getPhase1UDSliceIndex())*/cube.cube.subgoal()) {
			phase2Start(cube);
		}
	} else if (cube.depth > 0) {
		searched++;
		if (searched % 200000 == 0) std::cout << "Searched: " << searched << " " << unsigned(cube.depth) << "\n";
		if (TABLE_LOOKUP(phase1_corner_table, cube.cube.getPhase1CornerIndex()) <= cube.depth && TABLE_LOOKUP(phase1_edge_table, cube.cube.getPhase1EdgeIndex())  <= cube.depth && TABLE_LOOKUP(phase1_UDSlice_table, cube.cube.getPhase1UDSliceIndex())<= cube.depth, TABLE_LOOKUP(phase1_FlipUDSlice_table, cube.cube.getPhase1FlipUDSliceIndex()) <= cube.depth) {
			const unsigned char * availableMoves = cube.cube.getAvailableMoves(cube.index == 0 ? 255 : cube.moves[cube.index - 1]);
			unsigned char length = cube.index == 0 ? 18 : 15;
			for (int i = 0; i < length; i++) {
				qdata newCube(cube);
				newCube.cube.doMove(availableMoves[i]);
				newCube.moves[newCube.index] = availableMoves[i];
				newCube.index++;
				newCube.depth--;
				phase1Search(newCube);
			}
		}
	}
}

void Solver::phase2Start(qdata cube) {
	for (int i = 0; i < maxLength - cube.index; i++) {
		std::cout << "Phase 2 depth: " << i << "\n";
		qdata newCube = cube;
		cube.depth = i;
		phase2Search(newCube);
	}
}

void Solver::phase2Search(qdata cube) {
	//std::cout << "Phase 2 \n";
	if (cube.depth == 0) {
		//std::cout << "Phase 2 depth level 0 \n";
		if (cube.cube.isSolved()) {
			currentSolution = cube;
			hasSolution = true;
			std::cout << "Solution \n";
			maxLength = cube.index - 1;
		}
	}
	else if (cube.depth > 0) {
		searched++;
		if (searched % 200000 == 0) std::cout << "Searched: " << searched << " " << unsigned(cube.depth) << " phase 2" << "\n";
		if (TABLE_LOOKUP(phase2_corner_table, cube.cube.getPhase2CornerIndex()) <= cube.depth && TABLE_LOOKUP(phase2_edge_table, cube.cube.getPhase2EdgeIndex())  <= cube.depth && TABLE_LOOKUP(phase2_UDSlice_table, cube.cube.getPhase2UDSliceIndex() ) <= cube.depth) {
			const unsigned char * availableMoves = cube.cube.getAvailableMovesInPhase2(cube.index == 0 ? 255 : cube.moves[cube.index - 1]);
			unsigned char length = cube.index == 0 ? 10 : cube.moves[cube.index - 1] > 10 ? 7 : 9;

			//const unsigned char * availableMoves = cube.cube.getAvailableMoves(cube.index == 0 ? 255 : cube.moves[cube.index - 1]);
			//unsigned char length = cube.index == 0 ? 18 : 15;

			for (int i = 0; i < length; i++) {
				qdata newCube(cube);
				newCube.cube.doMove(availableMoves[i]);
				newCube.moves[cube.index] = availableMoves[i];
				newCube.index++;
				newCube.depth--;
				phase2Search(newCube);
			}
		}
	}
}

void Solver::phase3Start(qdata cube) {
	for (int i = 0; i < maxLength - cube.index; i++) {
		qdata newCube = cube;
		cube.depth = i;
		phase3Search(newCube);
	}
}


void Solver::phase3Search(qdata cube) {
	//std::cout << "Phase 2 \n";
	if (cube.depth == 0) {
		if (cube.cube.isSolved()) {
			currentSolution = cube;
			hasSolution = true;
			std::cout << "Solution \n";
			maxLength = cube.index - 1;
		}
	}
	else if (cube.depth > 0) {
		searched++;
		if (searched % 200000 == 0) std::cout << "Searched: " << searched << " " << unsigned(cube.depth) << " phase 3" << "\n";
		if (edge1_table[cube.cube.getEdgeIndex(0)] + 1 <= cube.depth && edge2_table[cube.cube.getEdgeIndex(1)] + 1 <= cube.depth && corner_table[cube.cube.getCornerIndex()] + 1 <= cube.depth) {
			//const unsigned char * availableMoves = cube.cube.getAvailableMovesInPhase2(cube.index == 0 ? 255 : cube.moves[cube.index - 1]);
			//unsigned char length = cube.index == 0 ? 10 : cube.moves[cube.index - 1] > 10 ? 7 : 9;

			const unsigned char * availableMoves = cube.cube.getAvailableMoves(cube.index == 0 ? 255 : cube.moves[cube.index - 1]);
			unsigned char length = cube.index == 0 ? 18 : 15;

			for (int i = 0; i < length; i++) {
				qdata newCube(cube);
				newCube.cube.doMove(availableMoves[i]);
				newCube.moves[cube.index] = availableMoves[i];
				newCube.index++;
				newCube.depth--;
				phase3Search(newCube);
			}
		}
	}
}

void Solver::treeSreach(qdata cube) {
	unsigned char index, temp;
	//if (hasSolution) return;
	if (cube.depth == 0) {
		//std::cout << "Depth: 0  \n";
		if (cube.cube.isSolved()) {
			currentSolution = cube;
			hasSolution = true;
			std::cout << "Solution \n";
			maxLength = 0;
			std::cout << "Max: " << maxLength << ", Index: " << unsigned(cube.index) << "\n";
			for (int i = 0; i < cube.index; i++) {
				std::cout << unsigned(cube.moves[i]) << " ";
			}
			std::cout << "\n";
		}
	}
	else if (cube.depth > 0) {
		qdata cubes[18];
		
		
		searched++;
		if (searched % 200000 == 0) std::cout << "Searched: " << searched << " " << unsigned(cube.hash) << "\n";
		const unsigned char * availableMoves = cube.cube.getAvailableMoves(cube.index == 0 ? 255 : cube.moves[cube.index - 1]);
		unsigned char length = cube.index == 0 ? 18 : 15;
		for (int i = 0; i < length; i++) {

				

			qdata newCube(cube);
			newCube.cube.doMove(availableMoves[i]);
			newCube.moves[cube.index] = availableMoves[i];
			newCube.index++;
			newCube.depth--;

			temp = TABLE_LOOKUP(corner_table, newCube.cube.getCornerIndex());
			//index = TABLE_LOOKUP(edge1_table, newCube.cube.getEdgeIndex(0));
			index = TABLE_LOOKUP(edge1_table, newCube.cube.getEdgeIndex(0));

			if (index > temp) temp = index;
			index = TABLE_LOOKUP(edge2_table, newCube.cube.getEdgeIndex(1));
			
			if (index > temp) temp = index;
			newCube.hash = temp;
			if ( cube.depth >= temp) treeSreach(newCube);

			//cubes[i] = newCube;
		}

		//Sorting:
		/*
		quicksort(cubes, 0, length - 1);
		for (int i = 0; i < length; i++) {
			treeSreach(cubes[i]);
		}
	*/

		
	}
}


void Solver::quicksort(qdata * cubes, int low, int high) {
	if (low < high) {
		int p = partition(cubes, low, high);
		quicksort(cubes, low, p - 1);
		quicksort(cubes, p + 1, high);
	}
}

int Solver::partition(qdata * cubes, int low, int high) {
	qdata temp;
	int pivot = cubes[high].hash;
	int i = low - 1;
	for (int j = low; j < high - 1; j++) {
		if (cubes[j].hash <= pivot) {
			i++;
			temp = cubes[i];
			cubes[i] = cubes[j];
			cubes[j] = temp;
		}
	}
	i++;
	temp = cubes[i];
	cubes[i] = cubes[high];
	cubes[high] = temp;
	return i;

}



void Solver::stack_solver(qdata cube) {

	std::queue<qdata> queue;

	maxLength = maxSearchLength;
	int depth = -1;
	int popcount = 0;



	while (depth <= maxLength) {
		if (queue.empty()) {
			if (hasSolution) {
				break;
			}

			queue.push(cube);
			depth++;
			std::cout << "Depth: " << depth << "\n";
		}


		popcount++;

		if (popcount % 200000 == 0) std::cout << "popcount: " << popcount << " " << depth << "\n";


		qdata newCube = queue.front();
		queue.pop();

		if (newCube.index == depth) {
			if (newCube.cube.isSolved()) {
				if (!hasSolution) {
					hasSolution = true;
					currentSolution = newCube;
					std::cout << "Found one!";
				}

				std::cout << "Found!";
			}
		} else {
			const unsigned char * turns = newCube.cube.getAvailableMoves(cube.index == 0 ? 255 : cube.moves[cube.index - 1]);
			int length = cube.index == 255 ? 18 : 15;

			for (int i = 0; i < length; i++) {
				qdata turnedCube = newCube;
				turnedCube.cube.doMove(turns[i]);
				turnedCube.index++;

				int	heuristic = TABLE_LOOKUP(corner_table, cube.cube.getCornerIndex());
				int temp = TABLE_LOOKUP(edge1_table, cube.cube.getEdgeIndex(0));
				if (heuristic < temp) heuristic = temp;
				temp = TABLE_LOOKUP(edge2_table, cube.cube.getEdgeIndex(1));
				if (heuristic < temp) heuristic = temp;

				if (heuristic + turnedCube.index + 1 <= depth) {
					queue.push(turnedCube);
				}

				

			}
		}
	}


}
