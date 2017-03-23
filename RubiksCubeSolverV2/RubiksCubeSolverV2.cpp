// RubiksCubeSolverV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Helper.h"
#include "Cube.h"
#include "Tables.h"

int main()
{

	Cube cube(solvedCube_T);
	const unsigned char * a = cube.getAvailableMoves(255);
	for (int i = 0; i < 18; i++)
	{
		Cube newCube(cube);
		newCube.doMove(a[i]);
		if (newCube.getCornerIndex() > 88179840) {
			std::cout << newCube.getCornerIndex() << "\n";
		}
	}

	//unsigned char * table;
	//table = NEW_CORNER_TABLE;

	//GenerateCornerTable(table);	
}

