#include "stdafx.h"
#include "Tables.h"

bool GenerateCornerTable(unsigned char * table) {

	std::queue<sdata> queue;
	int pops = 0;
	int nodesInQueue = 0;


	for (int i = 0; i < CORNER_TABLE_SIZE; i++) {
		table[i] = 255;
	}

	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};

	table[start.cube.getCornerIndex()] = 0;
	queue.push(start);
	nodesInQueue++;

	while (!queue.empty()) {
		//get the front elemnet and do every available move.
		sdata element = queue.front();
		const unsigned char * availableMoves = element.cube.getAvailableMoves(element.lastMove);
		unsigned char length = element.lastMove == 255 ? 18 : 15;
		unsigned char depth = element.depth + 1;
		for (int i = 0; i < length; i++) {
			Cube newCube = element.cube;
			newCube.doMove(availableMoves[i]);
			int index = newCube.getCornerIndex();
			if (table[index] == 255) {
				table[index] = depth;
				queue.push({ newCube, availableMoves[i], depth });
				nodesInQueue++;
			}
		}
		queue.pop();
		pops++;


		if (nodesInQueue % 200000 == 0) std::cout << "Pops: " << pops << ", in queue: " << nodesInQueue << "\n";
	}

	return false;
}

bool GenerateEdgeTable()
{
	return false;
}
