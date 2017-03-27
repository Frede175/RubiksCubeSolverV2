#pragma once
#ifndef Solver_T
#define Solver_T
#include "Cube.h"
#include <queue>


const int maxSearchLength = 32;


struct qdata {
	Cube cube;
	unsigned char moves[maxSearchLength];
	unsigned char depth = 0;
	unsigned char index = 0;
};


class Solver {
public:
	
	Solver(unsigned char * edge1_table, unsigned char * edge2_table, unsigned char * corner_table);
	//Returns an array with the moves to solve the cube
	unsigned char * SolveCube(Cube cube);
private:
	int maxLength;
	Cube startCube;
	qdata currentSolution;
	bool hasSolution;

	int searched = 0;

	unsigned char * edge1_table;
	unsigned char * edge2_table;
	unsigned char * corner_table;



	void phase1Search(qdata cube);

	void phase2Start(qdata cube);
	void phase2Search(qdata cube);

	void treeSreach(qdata cube);

	void stack_solver(qdata cube);
};


#endif // !Solver_T
