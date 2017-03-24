// RubiksCubeSolverV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Helper.h"
#include "Cube.h"
#include "Tables.h"

int main()
{
	/*
	//Cube cube(solvedCube_T);
	const unsigned char * a = cube.getAvailableMoves(255);
	for (int i = 0; i < 18; i++)
	{
		Cube newCube(cube);
		newCube.doMove(a[i]);
		if (newCube.getCornerIndex() > 88179840) {
			std::cout << newCube.getCornerIndex() << "\n";
		}
	}
	*/
	/*
	unsigned char * table1;
	table1 = NEW_EGDE_TABLE;
	unsigned char * table2;
	table2 = NEW_EGDE_TABLE;

	GenerateEdgeTable(table1, table2);


	FILE * file = fopen("output1.txt", "w+");
	int bytes_written = fwrite(table1, sizeof(unsigned char), EDGE_TABLE_SIZE, file);
	fclose(file);
	free(table1);
	file = fopen("output2.txt", "w+");
	bytes_written = fwrite(table2, sizeof(unsigned char), EDGE_TABLE_SIZE, file);
	fclose(file);
	free(table2);
	*/

	
	Cube cube(solvedCube_T);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << unsigned(cube.edgeIndexs[i][j]) << "\n";
		}
	}

	
	for (int i = 0; i < 6; i++) {
		std::cout << "Pos: "  << unsigned(cube.edgeIndexs[i][0]) << " : " << unsigned(cube.cube[cube.edgeIndexs[i][0]]) << "\n";
		std::cout << "Pos: " << unsigned(cube.edgeIndexs[i][1]) << " : " << unsigned(cube.cube[cube.edgeIndexs[i][1]]) << "\n";
	//	std::cout << "Pos: " << unsigned(cube.cornerIndexs[i][2]) << " : " << unsigned(cube.cube[cube.cornerIndexs[i][2]]) << "\n";
		std::cout << "EdgeIndex 1: " << cube.getEdgeIndex(0) << "EdgeIndex 2: " << cube.getEdgeIndex(1) << "\n";
	}
}

