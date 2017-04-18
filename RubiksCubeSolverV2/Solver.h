#pragma once
#ifndef Solver_T
#define Solver_T
#include "Cube.h"
#include <queue>
#include <string>
#include <iostream>


//#define TABLE_LOOKUP(table, hash) (hash&1 ? \
        table[(hash-1)>>1] >> 4 : \
        table[hash/2] & 15)
#define TABLE_LOOKUP(table, hash) table[hash]

const int maxSearchLength = 32;


struct qdata {
	Cube cube;
	unsigned char moves[maxSearchLength+1];
	unsigned char depth = 0;
	unsigned char index = 0;
	unsigned char hash = 0;
};


class Solver {
public:
	
	Solver(unsigned char * edge1_table, unsigned char * edge2_table, unsigned char * corner_table);
	Solver(unsigned char * phase1_corner_table, unsigned char * phase1_edge_table, unsigned char * phase1_UDSlice_table, unsigned char * phase1_FlipUDSlice_table, unsigned char * phase2_corner_table, unsigned char * phase2_edge_table, unsigned char * phase2_UDSlice_table);
	unsigned char * manualSolve(Cube cube);
	//Returns an array with the moves to solve the cube
	unsigned char * SolveCube(Cube cube);
private:
	int maxLength;
	Cube startCube;
	qdata currentSolution;
	bool hasSolution;
	int solutionLength = 0;
	int searched = 0;

	unsigned char * edge1_table;
	unsigned char * edge2_table;
	unsigned char * corner_table;

	unsigned char * phase1_corner_table;
	unsigned char * phase1_edge_table;
	unsigned char * phase1_UDSlice_table;
	unsigned char * phase1_FlipUDSlice_table;
	unsigned char * phase2_corner_table;
	unsigned char * phase2_edge_table;
	unsigned char * phase2_UDSlice_table;



	void phase1Search(qdata cube);

	void phase2Start(qdata cube);
	void phase2Search(qdata cube);

	void phase3Start(qdata cube);

	void phase3Search(qdata cube);

	void treeSreach(qdata cube);

	void quicksort(qdata * cubes, int low, int high);

	int partition(qdata * cubes, int low, int high);

	void stack_solver(qdata cube);
};


#endif // !Solver_T
