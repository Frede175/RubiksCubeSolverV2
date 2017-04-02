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

bool GenerateTables(unsigned char * table, int tableLength, unsigned char tableID)
{
	/*
	std::queue<sdata> queue;
	int pops = 0;
	int nodesInQueue = 0;
	for (int i = 0; i < tableLength; i++) {
		table[i] = 0;
	}
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	int tableIndex = 1;

	queue.push(start);
	nodesInQueue++;
	unsigned char depth = 0;
	while (tableIndex < tableLength) {

		if (queue.empty()) {

			std::cout << "Something went worng, Table Index: " << tableIndex << "/" << tableLength << "\n";

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
			int hash = getIndex(&newCube, tableID);

			bool add = false;

			if (hash & 1) {
				if (!(table[(hash - 1) / 2] >> 4)) {
					table[(hash - 1) / 2] |= depth << 4;
					add = true;
				}
			} else {
				if (!(table[hash / 2] & 15)) {
					table[hash / 2] |= depth;
					add = true;
				}
			}


			if (add) {
				tableIndex++;
				if (tableIndex % 200000 == 0) std::cout << "Pops: " << pops << "	, Depth: " << unsigned(depth) << "	, Nodes in queue: " << nodesInQueue << "	table Index: " << tableIndex << "/" << tableLength << "\n";
				queue.push({ newCube, availableMoves[i], depth });
				nodesInQueue++;
			}
				

		}
		queue.pop();
		nodesInQueue--;
		pops++;
	}
	std::cout << "Table Index: " << tableIndex << "/" << tableLength << "\n";

	return true;
	*/
	
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};

	std::queue<sdata> stack;
	/*
	* qdata is a struct, holding cube string 'cube_data',
	* an int representing the turn that was made, 'turn',
	* and an int representing the distance, 'distance'
	*/
	sdata current;
	int count = 0; /* total hashed */
	int popcount = 0; /* total traversed */
	int hash;
	int i;
	unsigned char *instack;
//	int depth;
	Cube turned;

	/* Create a stack */

	/*
	* create a temporary table to keep track of the stack This holds the value
	* of each item that has been added to the stack, and its distance.  This
	* way, we know if we encounter the same node but at a further distance we
	* can throw it away.  This heuristic cuts down on processing time by quite
	* a bit, and is only as time intensive as the hashing algorithm, at the
	* expense of using more memory.
	*/
	
	if (tableID == 0) instack = NEW_CORNER_TABLE;
	else if (tableID == 1) instack = NEW_EGDE_TABLE;
	else if (tableID == 2) instack = NEW_EGDE_TABLE;

	for (int a = 0; a < tableLength; a++) {
		instack[a] = 255;
	}

	int depth = 0;
	while (count < tableLength) {
		/* if stack is empty, go up a level */
		if (stack.empty()) {
			stack.push(start);
			depth++;
			/* clear out instack table */
			for (int a = 0; a < tableLength; a++) {
				instack[a] = 255;
			}
		}

		/* Pop the first item off, put it in current */
		current = stack.front();
		stack.pop();
		popcount++;

		/* Print out status every 2^18 pops  (approx every 200k)*/
		if ((popcount & 0777777) == 0777777) {
			fprintf(stderr, "\r%d/%d hashed, on level:%d/11, total traversed:%d ", count, tableLength, depth, popcount);
		}
#ifdef PROFILE_MODE
		/* For profiling, so I don't have to wait an hour to gather data */
		if (count == 10000000) {
			return 0;
		}
#endif
		/* Not at the current depth, put all turns onto the stack */

		const unsigned char * availableMoves = current.cube.getAvailableMoves(current.lastMove);
		unsigned char length = current.lastMove == 255 ? 18 : 15;


		for (i = 0; i<length; i++) {
				

			turned = Cube(current.cube);
			turned.doMove(availableMoves[i]);

			/*
			* Check if turned is in instack and is greater than
			* or equal to the depth.  If so, skip
			*/
			hash = getIndex(&turned, tableID);
			if (hash & 1 ? \
				((instack[(hash - 1) / 2] >> 4) <= (current.depth+1)) : \
				((instack[hash / 2] & 15) <= (current.depth + 1))) {
				continue;
			}
			/* add to instack */
			if (hash & 1) {
				instack[(hash - 1) / 2] &= 15;
				instack[(hash - 1) / 2] |= (current.depth + 1) << 4;
			} else {
				instack[hash / 2] &= 15 << 4;
				instack[hash / 2] |= (current.depth + 1);
			}


			if (current.depth + 1 == depth) {

				if (hash & 1) {
					if (!(table[(hash - 1) / 2] >> 4)) {
						table[(hash - 1) / 2] |= (current.depth + 1) << 4;
						count++;
					} else {
						/* A duplicate, skip */
					}
				} else {
					if (!(table[hash / 2] & 15)) {
						table[hash / 2] |= current.depth + 1;
						count++;
					} else {
						/* a duplicate */
					}
				}

			} else {
				unsigned char d = current.depth + (unsigned char)1;
				/* Add to real stack */
				stack.push({ turned, availableMoves[i], d });
			}

			
		}

	}
	

	hash = getIndex(&Cube(solvedCube_T), tableID);
	if (hash & 1) {
		/* zero out upper bits */
		table[(hash - 1) / 2] &= 15;
	} else {
		/* zero out lower bits */
		table[hash / 2] &= (15 << 4);
	}





	free(instack);
	while (!stack.empty()) {
		stack.pop();
	}
	fprintf(stderr, "\n");




	return true;
	
}

int getIndex(Cube * cube, unsigned char tableID)
{
	switch (tableID)
	{
	case 0:
		return cube->getCornerIndex();
	case 1:
		return cube->getEdgeIndex(0);
	case 2:
		return cube->getEdgeIndex(1);
	default:
		return 255;
	}
}

