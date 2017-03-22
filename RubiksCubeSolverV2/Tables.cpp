#include "stdafx.h"
#include "Tables.h"

bool GenerateCornerTable() {

	int c = 0;
	int len = 0;

	for (int i = 0; i < CORNER_TABLE_SIZE; i++) {
		cornerTable[i] = -1;
	}

	Cube cube(solvedCube_T);

	cornerTable[cube.getCornerIndex()];
	
	do {
		for (int i = 0; i < CORNER_TABLE_SIZE; i++) {
			if (cornerTable[i] == len) {

			}
		}


	} while (c > 0);


	


}

bool GenerateEdgeTable()
{
	return false;
}
