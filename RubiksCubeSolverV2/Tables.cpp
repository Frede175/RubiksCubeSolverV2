#include "stdafx.h"
#include "Tables.h"

bool GenerateCornerTable(unsigned char * table) {

	std::queue<sdata> queue;
	int pops = 0;
	int indexes = 0;
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
	unsigned char depth = 0;
	while (indexes < CORNER_TABLE_SIZE) {
		if (queue.empty()) {
			std::cout << "Something went wrong";
			break;
		}
		//get the front elemnet and do every available move.
		sdata element = queue.front();
		const unsigned char * availableMoves = element.cube.getAvailableMoves(element.lastMove);
		unsigned char length = element.lastMove == 255 ? 18 : 15;
		depth = element.depth + 1;
		for (int i = 0; i < length; i++) {
			Cube newCube(element.cube);
			newCube.doMove(availableMoves[i]);
			int index = newCube.getCornerIndex();
			if (table[index] == 255 || table[index] > depth) {
				queue.push({ newCube, availableMoves[i], depth });
				nodesInQueue++;
			}
			
		}
		int index = element.cube.getCornerIndex();
		if (table[index] == 255) {
			if (indexes % 10000 == 0) std::cout << "Pops: " << pops << ", indexes: " << indexes << ", Depth: " << unsigned(depth) << ", Nodes in queue: " << nodesInQueue << "\n";
			indexes++;
			table[index] = element.depth;
		}
		queue.pop();
		nodesInQueue--;
		pops++;
	}
	std::cout << "Total nodes added: " << indexes << "\n";
	return true;
}

bool GenerateEdgeTable()
{
	return false;
}
