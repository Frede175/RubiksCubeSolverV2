// RubiksCubeSolverV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Helper.h"
#include "Cube.h"

int main()
{
	Cube cube(solvedCube_T);
	std::cout << unsigned(cube.getCornerIndex());
    return 0;
}

