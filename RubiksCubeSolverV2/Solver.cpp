#include "stdafx.h"
#include "Solver.h"

Solver::Solver(unsigned char * edge1_table, unsigned char * edge2_table, unsigned char * corner_table) {
	this->edge1_table = edge1_table;
	this->edge2_table = edge2_table;
	this->corner_table = corner_table;
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
	
	for (int depth = 0; depth <= maxLength; depth++) {
		qdata data;
		data.cube = cube;
		data.depth = depth;
		data.index = 0;
		phase1Search(data);

		std::cout << "Depth: " << depth << "\n";

	}
	if (!hasSolution) return nullptr;
	unsigned char solution[maxSearchLength];

	for (int i = 0; i < maxSearchLength; i++) {
		solution[i] = 255;
	}

	for (int i = 0; i < currentSolution.index; i++) {
		solution[i] = currentSolution.moves[i];
	}

	return solution;
	
	
}

void Solver::phase1Search(qdata cube) {
	if (cube.depth == 0) {
		//std::cout << "0 \n";
		if (cube.cube.subgoal() && cube.cube.endsOnCurrectMove(cube.index == 0 ? 255 : cube.moves[cube.index - 1])) {
			phase2Start(cube);
		}
	} else if (cube.depth > 0) {
		searched++;
		if (searched % 200000 == 0) std::cout << "Searched: " << searched << " " << unsigned(cube.depth) << "\n";
		if (corner_table[cube.cube.getCornerIndex()] + 1<= cube.depth && edge1_table[cube.cube.getEdgeIndex(0)] + 1 <= cube.depth && edge2_table[cube.cube.getEdgeIndex(1)] + 1 <= cube.depth) {
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
		qdata newCube = cube;
		cube.depth = i;
		phase2Search(newCube);
	}
}

void Solver::phase2Search(qdata cube) {
	std::cout << "Phase 2 \n";
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
		if (searched % 10000 == 0) std::cout << "Searched: " << searched << " " << unsigned(cube.depth) << " phase 2" << "\n";
		if (corner_table[cube.cube.getCornerIndex()] + 1 <= cube.depth && edge1_table[cube.cube.getEdgeIndex(0)] + 1 <= cube.depth && edge2_table[cube.cube.getEdgeIndex(1)] + 1 <= cube.depth) {
			const unsigned char * availableMoves = cube.cube.getAvailableMovesInPhase2(cube.index == 0 ? 255 : cube.moves[cube.index - 1]);
			unsigned char length = cube.index == 0 ? 10 : cube.moves[cube.index - 1] > 10 ? 7 : 9;
			for (int i = 0; i < length; i++) {
				qdata newCube(cube);
				newCube.cube.doMove(availableMoves[i]);
				newCube.moves[cube.index] = availableMoves[i];
				newCube.index++;
				newCube.depth--;
				phase1Search(newCube);
			}
		}
	}
}

void Solver::treeSreach(qdata cube) {
	if (cube.depth == 0) {
		std::cout << "Depth: 0  \n";
		if (cube.cube.isSolved()) {
			currentSolution = cube;
			hasSolution = true;
			std::cout << "Solution \n";
			maxLength = cube.index - 1;
		}
	}
	else if (cube.depth > 0) {
		
		
		if (corner_table[cube.cube.getCornerIndex()] <= cube.depth && edge1_table[cube.cube.getEdgeIndex(0)] <= cube.depth && edge2_table[cube.cube.getEdgeIndex(1)] <= cube.depth) {
			searched++;
			if (searched % 200000 == 0) std::cout << "Searched: " << searched << " " << unsigned(cube.depth) << " phase 2" << "\n";
			const unsigned char * availableMoves = cube.cube.getAvailableMoves(cube.index == 0 ? 255 : cube.moves[cube.index - 1]);
			unsigned char length = cube.index == 0 ? 18 : 15;
			for (int i = 0; i < length; i++) {
				qdata newCube(cube);
				newCube.cube.doMove(availableMoves[i]);
				newCube.moves[cube.index] = availableMoves[i];
				newCube.index++;
				newCube.depth--;
				treeSreach(newCube);
			}
		}
	}
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

				int	heuristic = corner_table[cube.cube.getCornerIndex()];
				int temp = edge1_table[cube.cube.getEdgeIndex(0)];
				if (heuristic < temp) heuristic = temp;
				temp = edge2_table[cube.cube.getEdgeIndex(1)];
				if (heuristic < temp) heuristic = temp;

				if (heuristic + turnedCube.index > depth) {
					continue;
				}

				queue.push(turnedCube);

			}
		}
	}


}
