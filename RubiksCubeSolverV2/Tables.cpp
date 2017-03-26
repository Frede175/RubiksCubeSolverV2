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
			if (table[index] == 255) {
				table[index] = element.depth;
				queue.push({ newCube, availableMoves[i], depth });
				nodesInQueue++;
				if (indexes % 200000 == 0) std::cout << "Pops: " << pops << "	, indexes: " << indexes << "	, Depth: " << unsigned(depth) << "	, Nodes in queue: " << nodesInQueue << "\n";
				indexes++;
			}
			
		}
		/*
		int index = element.cube.getCornerIndex();
		if (table[index] == 255) {
			if (indexes % 10000 == 0) std::cout << "Pops: " << pops << ", indexes: " << indexes << ", Depth: " << unsigned(depth) << ", Nodes in queue: " << nodesInQueue << "\n";
			indexes++;
			table[index] = element.depth;

		}*/
		queue.pop();
		nodesInQueue--;
		pops++;
	}
	std::cout << "Total nodes added: " << indexes << "\n";
	return true;
}

bool GenerateEdge1Table(unsigned char * table)
{
	std::queue<sdata> queue;
	int pops = 0;
	int nodesInQueue = 0;
	for (int i = 0; i < EDGE_TABLE_SIZE; i++) {
		table[i] = 255;
	}
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	int tableIndex = 1;

	table[start.cube.getEdgeIndex(0)] = 0;
	queue.push(start);
	nodesInQueue++;
	unsigned char depth = 0;
	while (tableIndex < EDGE_TABLE_SIZE) {

		if (queue.empty()) {
			std::cout << "Something went worng, Table Index: " << tableIndex << "/" << EDGE_TABLE_SIZE << "\n";

			return false;
		}

		//get the front elemnet and do every available move.
		sdata element = queue.front();
		const unsigned char * availableMoves = element.cube.getAvailableMoves(element.lastMove);
		unsigned char length = element.lastMove == 255 ? 18 : 15;
		depth = element.depth + 1;
		for (int i = 0; i < length; i++) {
			Cube newCube(element.cube);
			newCube.doMove(availableMoves[i]);
			int index = newCube.getEdgeIndex(0);

			if (table[index] == 255) {
				table[index] = element.depth;
				tableIndex++;
				if (tableIndex % 200000 == 0) std::cout << "Pops: " << pops << "	, Depth: " << unsigned(depth) << "	, Nodes in queue: " << nodesInQueue << "	table Index: " << tableIndex << "/" << EDGE_TABLE_SIZE << "\n";
				queue.push({ newCube, availableMoves[i], depth });
				nodesInQueue++;
				
			}

		}
		queue.pop();
		nodesInQueue--;
		pops++;
	}
	std::cout << "Table Index: " << tableIndex << "/" << EDGE_TABLE_SIZE << "\n";

	return true;
}


bool GenerateEdge2Table(unsigned char * table)
{
	std::queue<sdata> queue;
	int pops = 0;
	int nodesInQueue = 0;
	for (int i = 0; i < EDGE_TABLE_SIZE; i++) {
		table[i] = 255;
	}
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	int tableIndex = 1;

	table[start.cube.getEdgeIndex(1)] = 0;
	queue.push(start);
	nodesInQueue++;
	unsigned char depth = 0;
	while (tableIndex < EDGE_TABLE_SIZE) {

		if (queue.empty()) {

			std::cout << "Something went worng, Table Index: " << tableIndex << "/" << EDGE_TABLE_SIZE << "\n";
			
			return false;
		}

		//get the front elemnet and do every available move.
		sdata element = queue.front();
		const unsigned char * availableMoves = element.cube.getAvailableMoves(element.lastMove);
		unsigned char length = element.lastMove == 255 ? 18 : 15;

		depth = element.depth + 1;
		for (int i = 0; i < length; i++) {
			Cube newCube(element.cube);
			newCube.doMove(availableMoves[i]);
			int index = newCube.getEdgeIndex(1);

			if (table[index] == 255) {
				table[index] = element.depth;
				tableIndex++;
				if (tableIndex % 200000 == 0) std::cout << "Pops: " << pops << "	, Depth: " << unsigned(depth) << "	, Nodes in queue: " << nodesInQueue << "	table Index: " << tableIndex << "/" << EDGE_TABLE_SIZE << "\n";
				queue.push({ newCube, availableMoves[i], depth });
				nodesInQueue++;
			}
		}
		queue.pop();
		nodesInQueue--;
		pops++;
	}
	std::cout << "Table Index: " << tableIndex << "/" << EDGE_TABLE_SIZE << "\n";

	return true;
}