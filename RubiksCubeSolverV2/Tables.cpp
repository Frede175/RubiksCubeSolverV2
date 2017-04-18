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
		table[i] = 255;
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

			bool add = true;

			if (table[hash] < depth) {
				add = false;
			}


			if (add) {
				if (table[hash] > depth) {
					table[hash] = depth;
					tableIndex++;
					if (tableIndex % 200000 == 0) std::cout << "Pops: " << pops << "	, Depth: " << unsigned(depth) << "	, Nodes in queue: " << nodesInQueue << "	table Index: " << tableIndex << "/" << tableLength << "\n";
				}
				
				
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
	int count = 1; /* total hashed */
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
		table[a] = 0;
		instack[a] = 255;
	}

	int depth = 0;
	while (count < tableLength) {
		if (count >= 42577913 && (tableID == 1 || tableID == 2)) break;
		/* if stack is empty, go up a level */
		if (stack.empty()) {
			stack.push(start);
			depth++;
			std::cout << "Depth: " << depth << "\n";
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

			//if (hash == 17846338 || hash == 20623 || hash == 20399) {
			//	std::cout << "Hash: " << hash << ", Depth: " << (current.depth + 1) << ", table: " << unsigned(table[hash]) << "\n";
			//	if (instack[hash] <= current.depth + 1) std::cout << "Continue \n";
			//}
			
			//if (instack[hash] <= current.depth + 1) continue;
			//instack[hash] = current.depth + 1;
			
			if (hash & 1 ? \
				((instack[(hash - 1) / 2] >> 4) <= (current.depth + 1)) : \
				((instack[hash / 2] & 15) <= (current.depth + 1))) {
				continue;
			}
			// add to instack 
			if (hash & 1) {
				instack[(hash - 1) / 2] &= 15;
				instack[(hash - 1) / 2] |= (current.depth + 1) << 4;
			} else {
				instack[hash / 2] &= 15 << 4;
				instack[hash / 2] |= (current.depth + 1);
			}
			
			
			if (current.depth + 1 == depth) {
				/*if (table[hash] > (current.depth + 1)) {
					table[hash] = (current.depth + 1);
					count++;
				}*/
				

				
				if (hash & 1) {
					if (!(table[(hash - 1) / 2] >> 4)) {
						table[(hash - 1) / 2] |= (current.depth + 1) << 4;
						count++;
					} else {
						// A duplicate, skip
					}
				} else {
					if (!(table[hash / 2] & 15)) {
						table[hash / 2] |= current.depth + 1;
						count++;
					} else {
						// a duplicate 
					}
				}
				
			} else {
				unsigned char d = current.depth + (unsigned char)1;
				/* Add to real stack */
				stack.push({ turned, availableMoves[i], d });
			}

			
		}

	}
	
	if (tableID != 0) {
		hash = getIndex(&Cube(solvedCube_T), tableID);
		if (hash & 1) {
			/* zero out upper bits */
			table[(hash - 1) / 2] &= 15;
		} else {
			/* zero out lower bits */
			table[hash / 2] &= (15 << 4);
		}
	} else table[getIndex(&Cube(solvedCube_T), tableID)] = 0;
	





	free(instack);
	while (!stack.empty()) {
		stack.pop();
	}
	fprintf(stderr, "\n");




	return true;
	
}


int getIndex(Cube * cube, unsigned char tableID) {
	switch (tableID) {
	case 0:
		return cube->getCornerIndex();
	case 1:
		return cube->getEdgeIndex(0);
	case 2:
		return cube->getEdgeIndex(1);
	default:
		return -1;
	}
}


int GeneratePhase1CornerTable(unsigned char * table) {

	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	std::queue<sdata> stack;
	sdata current;
	int count = 1; 
	int popcount = 0; 
	int hash;
	int i;
	unsigned char *instack;
	Cube turned;

	instack = NEW_PHASE1_CORNER_TABLE;

	memset(table, 255, PHASE1_CORNER_SIZE);
	memset(instack, 255, PHASE1_CORNER_SIZE);

	int depth = 0;
	while (count < PHASE1_CORNER_SIZE) {
		if (stack.empty()) {
			stack.push(start);
			depth++;
			std::cout << "Depth: " << depth << "\n";
			memset(instack, 255, PHASE1_CORNER_SIZE);
		}
		current = stack.front();
		stack.pop();
		popcount++;
		if ((popcount & 0777777) == 0777777) {
			fprintf(stderr, "\r%d/%d hashed, on level:%d, total traversed:%d ", count, PHASE1_CORNER_SIZE, depth, popcount);
		}
		const unsigned char * availableMoves = current.cube.getAvailableMoves(current.lastMove);
		unsigned char length = current.lastMove == 255 ? 18 : 15;
		for (i = 0; i<length; i++) {
			turned = Cube(current.cube);
			turned.doMove(availableMoves[i]);

			hash = turned.getPhase1CornerIndex();		

			if (instack[hash] <= current.depth + 1) continue;
			instack[hash] = current.depth + 1;
			if (current.depth + 1 == depth) {
				if (table[hash] > (current.depth + 1)) {
					table[hash] = (current.depth + 1);
					count++;
				}
			} else {
				unsigned char d = current.depth + (unsigned char)1;
				stack.push({ turned, availableMoves[i], d });
			}
		}
	}

	table[0] = 0;
	free(instack);
	while (!stack.empty()) {
		stack.pop();
	}
	fprintf(stderr, "\n");
	return 1;
}

int GeneratePhase1EdgeTable(unsigned char * table) {
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	std::queue<sdata> stack;
	sdata current;
	int count = 1;
	int popcount = 0;
	int hash;
	int i;
	unsigned char *instack;
	Cube turned;

	instack = NEW_PHASE1_EDGE_TABLE;

	memset(table, 255, PHASE1_EDGE_SIZE);
	memset(instack, 255, PHASE1_EDGE_SIZE);

	int depth = 0;
	while (count < PHASE1_EDGE_SIZE) {


		if (stack.empty()) {
			stack.push(start);
			depth++;
			std::cout << "Depth: " << depth << "\n";
			memset(instack, 255, PHASE1_EDGE_SIZE);
		}
		current = stack.front();
		stack.pop();
		popcount++;
		if ((popcount & 0777777) == 0777777) {
			fprintf(stderr, "\r%d/%d hashed, on level:%d, total traversed:%d ", count, PHASE1_EDGE_SIZE, depth, popcount);
		}
		const unsigned char * availableMoves = current.cube.getAvailableMoves(current.lastMove);
		unsigned char length = current.lastMove == 255 ? 18 : 15;
		for (i = 0; i<length; i++) {
			turned = Cube(current.cube);
			turned.doMove(availableMoves[i]);

			hash = turned.getPhase1EdgeIndex();

			if (instack[hash] <= current.depth + 1) continue;
			instack[hash] = current.depth + 1;
			if (current.depth + 1 == depth) {
				if (table[hash] >(current.depth + 1)) {
					table[hash] = (current.depth + 1);
					count++;
				}
			} else {
				unsigned char d = current.depth + (unsigned char)1;
				stack.push({ turned, availableMoves[i], d });
			}
		}
	}

	table[0] = 0;
	free(instack);
	while (!stack.empty()) {
		stack.pop();
	}
	fprintf(stderr, "\n");
	return 1;
}

int GeneratePhase1UDSliceTable(unsigned char * table) {
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	std::queue<sdata> stack;
	sdata current;
	int count = 1;
	int popcount = 0;
	int hash;
	int i;
	unsigned char *instack;
	Cube turned;
	
	instack = NEW_PHASE1_UDSLICE_TABLE;

	memset(table, 255, PHASE1_UDSLICE_SIZE);
	memset(instack, 255, PHASE1_UDSLICE_SIZE);

	int depth = 0;
	while (count < PHASE1_UDSLICE_SIZE) {
		if (stack.empty()) {
			stack.push(start);
			depth++;
			std::cout << "Depth: " << depth << "\n";
			memset(instack, 255, PHASE1_UDSLICE_SIZE);
		}
		current = stack.front();
		stack.pop();
		popcount++;
		if ((popcount & 0777777) == 0777777) {
			fprintf(stderr, "\r%d/%d hashed, on level:%d, total traversed:%d ", count, PHASE1_UDSLICE_SIZE, depth, popcount);
		}
		const unsigned char * availableMoves = current.cube.getAvailableMoves(current.lastMove);
		unsigned char length = current.lastMove == 255 ? 18 : 15;
		for (i = 0; i<length; i++) {
			turned = Cube(current.cube);
			turned.doMove(availableMoves[i]);

			hash = turned.getPhase1UDSliceIndex();

			if (instack[hash] <= current.depth + 1) continue;
			instack[hash] = current.depth + 1;
			if (current.depth + 1 == depth) {
				if (table[hash] >(current.depth + 1)) {
					table[hash] = (current.depth + 1);
					count++;
				}
			} else {
				unsigned char d = current.depth + (unsigned char)1;
				stack.push({ turned, availableMoves[i], d });
			}
		}
	}

	table[0] = 0;
	free(instack);
	while (!stack.empty()) {
		stack.pop();
	}
	fprintf(stderr, "\n");
	return 1;
}

int GeneratePhase1FlipUDSliceTable(unsigned char * table) {
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	std::queue<sdata> stack;
	sdata current;
	int count = 1;
	int popcount = 0;
	int hash;
	int i;
	unsigned char *instack;
	Cube turned;

	instack = NEW_PHASE1_FLIPUDSLICE_TABLE;

	
	memset(table, 255, PHASE1_FLIPUDSLICE_SIZE);
	memset(instack, 255, PHASE1_FLIPUDSLICE_SIZE);

	int depth = 0;
	while (count < PHASE1_FLIPUDSLICE_SIZE) {
		if (stack.empty()) {
			stack.push(start);
			depth++;
			std::cout << "Depth: " << depth << "\n";
			memset(instack, 255, PHASE1_FLIPUDSLICE_SIZE);
		}
		current = stack.front();
		stack.pop();
		popcount++;
		if ((popcount % 200000) == 0) {
			fprintf(stderr, "\r%d/%d hashed, on level:%d, total traversed:%d ", count, PHASE1_FLIPUDSLICE_SIZE, depth, popcount);
		}
		const unsigned char * availableMoves = current.cube.getAvailableMoves(current.lastMove);
		unsigned char length = current.lastMove == 255 ? 18 : 15;
		for (i = 0; i<length; i++) {
			turned = Cube(current.cube);
			turned.doMove(availableMoves[i]);

			hash = turned.getPhase1FlipUDSliceIndex();

			if (hash < 0 || hash > PHASE1_FLIPUDSLICE_SIZE - 1)
				std::cout << "Error. Hash has a value of: " << hash << "\n";


			if (instack[hash] <= current.depth + 1) continue;
			instack[hash] = current.depth + 1;
			if (current.depth + 1 == depth) {
				if (table[hash] >(current.depth + 1)) {
					table[hash] = (current.depth + 1);
					count++;
				}
			} else {
				unsigned char d = current.depth + (unsigned char)1;
				stack.push({ turned, availableMoves[i], d });
			}
		}
	}

	table[0] = 0;
	free(instack);
	while (!stack.empty()) {
		stack.pop();
	}
	fprintf(stderr, "\n");
	return 1;
}

int GeneratePhase2CornerTable(unsigned char * table) {
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	std::queue<sdata> stack;
	sdata current;
	int count = 1;
	int popcount = 0;
	int hash;
	int i;
	unsigned char *instack;
	Cube turned;

	instack = NEW_PHASE2_CORNER_TABLE;
	memset(table, 255, PHASE2_CORNER_SIZE);
	memset(instack, 255, PHASE2_CORNER_SIZE);

	int depth = 0;
	while (count < PHASE2_CORNER_SIZE) {
		if (stack.empty()) {
			stack.push(start);
			depth++;
			std::cout << "Depth: " << depth << "\n";
			memset(instack, 255, PHASE2_CORNER_SIZE);
		}
		current = stack.front();
		stack.pop();
		popcount++;
		if ((popcount & 0777777) == 0777777) {
			fprintf(stderr, "\r%d/%d hashed, on level:%d, total traversed:%d ", count, PHASE2_CORNER_SIZE, depth, popcount);
		}
		const unsigned char * availableMoves = current.cube.getAvailableMovesInPhase2(current.lastMove);
		unsigned char length = current.lastMove == 255 ? 10 : current.lastMove > 10 ? 7 : 9;
		for (i = 0; i<length; i++) {
			turned = Cube(current.cube);
			turned.doMove(availableMoves[i]);

			hash = turned.getPhase2CornerIndex();

			if (instack[hash] <= current.depth + 1) continue;
			instack[hash] = current.depth + 1;
			if (current.depth + 1 == depth) {
				if (table[hash] >(current.depth + 1)) {
					table[hash] = (current.depth + 1);
					count++;
				}
			} else {
				unsigned char d = current.depth + (unsigned char)1;
				stack.push({ turned, availableMoves[i], d });
			}
		}
	}

	table[0] = 0;
	free(instack);
	while (!stack.empty()) {
		stack.pop();
	}
	fprintf(stderr, "\n");
	return 1;
}

int GeneratePhase2EdgeTable(unsigned char * table) {
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	std::queue<sdata> stack;
	sdata current;
	int count = 1;
	int popcount = 0;
	int hash;
	int i;
	unsigned char *instack;
	Cube turned;

	instack = NEW_PHASE2_EDGE_TABLE;
	memset(table, 255, PHASE2_EDGE_SIZE);
	memset(instack, 255, PHASE2_EDGE_SIZE);

	int depth = 0;
	while (count < PHASE2_EDGE_SIZE) {
		if (stack.empty()) {
			stack.push(start);
			depth++;
			std::cout << "Depth: " << depth << "\n";
			memset(instack, 255, PHASE2_EDGE_SIZE);
		}
		current = stack.front();
		stack.pop();
		popcount++;
		if ((popcount & 0777777) == 0777777) {
			fprintf(stderr, "\r%d/%d hashed, on level:%d, total traversed:%d ", count, PHASE2_EDGE_SIZE, depth, popcount);
		}
		const unsigned char * availableMoves = current.cube.getAvailableMovesInPhase2(current.lastMove);
		unsigned char length = current.lastMove == 255 ? 10 : current.lastMove > 10 ? 7 : 9;
		for (i = 0; i<length; i++) {
			turned = Cube(current.cube);
			turned.doMove(availableMoves[i]);

			hash = turned.getPhase2EdgeIndex();

			if (instack[hash] <= current.depth + 1) continue;
			instack[hash] = current.depth + 1;
			if (current.depth + 1 == depth) {
				if (table[hash] >(current.depth + 1)) {
					table[hash] = (current.depth + 1);
					count++;
				}
			} else {
				unsigned char d = current.depth + (unsigned char)1;
				stack.push({ turned, availableMoves[i], d });
			}
		}
	}

	table[0] = 0;
	free(instack);
	while (!stack.empty()) {
		stack.pop();
	}
	fprintf(stderr, "\n");
	return 1;
}

int GeneratePhase2UDSliceTable(unsigned char * table) {
	sdata start = {
		Cube(solvedCube_T),
		255,
		0
	};
	std::queue<sdata> stack;
	sdata current;
	int count = 1;
	int popcount = 0;
	int hash;
	int i;
	unsigned char *instack;
	Cube turned;

	instack = NEW_PHASE2_UDSLICE_TABLE;

	memset(table, 255, PHASE2_UDSLICE_SIZE);
	memset(instack, 255, PHASE2_UDSLICE_SIZE);

	int depth = 0;
	while (count < PHASE2_UDSLICE_SIZE) {
		if (stack.empty()) {
			stack.push(start);
			depth++;
			std::cout << "Depth: " << depth << "\n";
			memset(instack, 255, PHASE2_UDSLICE_SIZE);
		}
		current = stack.front();
		stack.pop();
		popcount++;
		if ((popcount & 0777777) == 0777777) {
			fprintf(stderr, "\r%d/%d hashed, on level:%d, total traversed:%d ", count, PHASE2_UDSLICE_SIZE, depth, popcount);
		}
		const unsigned char * availableMoves = current.cube.getAvailableMovesInPhase2(current.lastMove);
		unsigned char length = current.lastMove == 255 ? 10 : current.lastMove > 10 ? 7 : 9;
		//const unsigned char * availableMoves = current.cube.getAvailableMoves(current.lastMove);
		//unsigned char length = current.lastMove == 255 ? 18 : 15;
		for (i = 0; i<length; i++) {
			turned = Cube(current.cube);
			turned.doMove(availableMoves[i]);

			hash = turned.getPhase2UDSliceIndex();

			if (instack[hash] <= current.depth + 1) continue;
			instack[hash] = current.depth + 1;
			if (current.depth + 1 == depth) {
				if (table[hash] >(current.depth + 1)) {
					table[hash] = (current.depth + 1);
					count++;
				}
			} else {
				unsigned char d = current.depth + (unsigned char)1;
				stack.push({ turned, availableMoves[i], d });
			}
		}
	}

	table[0] = 0;
	free(instack);
	while (!stack.empty()) {
		stack.pop();
	}
	fprintf(stderr, "\n");
	return 1;
}

void loadTables(unsigned char * phase1_corner_table, unsigned char * phase1_edge_table, unsigned char * phase1_UDSlice_table, unsigned char * phase1_FlipUDSlice_table, unsigned char * phase2_corner_table, unsigned char * phase2_edge_table, unsigned char * phase2_UDSlice_table) {
	FILE * file = fopen("phase1_corner_table.txt", "r+");
	int bytes_read = fread(phase1_corner_table, sizeof(unsigned char), PHASE1_CORNER_SIZE, file);
	fclose(file);

	file = fopen("phase1_edge_table.txt", "r+");
	bytes_read = fread(phase1_edge_table, sizeof(unsigned char), PHASE1_EDGE_SIZE, file);
	fclose(file);

	file = fopen("phase1_UDSlice_table.txt", "r+");
	bytes_read = fread(phase1_UDSlice_table, sizeof(unsigned char), PHASE1_UDSLICE_SIZE, file);
	fclose(file);

	file = fopen("phase1_FlipUDSlice_table.txt", "r+");
	bytes_read = fread(phase1_FlipUDSlice_table, sizeof(unsigned char), PHASE1_FLIPUDSLICE_SIZE, file);
	fclose(file);

	file = fopen("phase2_corner_table.txt", "r+");
	bytes_read = fread(phase2_corner_table, sizeof(unsigned char), PHASE2_CORNER_SIZE, file);
	fclose(file);

	file = fopen("phase2_edge_table.txt", "r+");
	bytes_read = fread(phase2_edge_table, sizeof(unsigned char), PHASE2_EDGE_SIZE, file);
	fclose(file);

	file = fopen("phase2_UDSlice_table.txt", "r+");
	bytes_read = fread(phase2_UDSlice_table, sizeof(unsigned char), PHASE2_UDSLICE_SIZE, file);
	fclose(file);
}




void generateTables(unsigned char * phase1_corner_table, unsigned char * phase1_edge_table, unsigned char * phase1_UDSlice_table, unsigned char * phase1_FlipUDSlice_table, unsigned char * phase2_corner_table, unsigned char * phase2_edge_table, unsigned char * phase2_UDSlice_table) {
	GeneratePhase1CornerTable(phase1_corner_table);
	std::cout << "Table done! \n";
	FILE * file = fopen("phase1_corner_table.txt", "w+");
	int bytes_written = fwrite(phase1_corner_table, sizeof(unsigned char), PHASE1_CORNER_SIZE, file);
	fclose(file);
	free(phase1_corner_table);
	
	GeneratePhase1EdgeTable(phase1_edge_table);
	std::cout << "Table done! \n";
	file = fopen("phase1_edge_table.txt", "w+");
	bytes_written = fwrite(phase1_edge_table, sizeof(unsigned char), PHASE1_EDGE_SIZE, file);
	fclose(file);
	free(phase1_edge_table);
	
	GeneratePhase1UDSliceTable(phase1_UDSlice_table);
	std::cout << "Table done! \n";
	file = fopen("phase1_UDSlice_table.txt", "w+");
	bytes_written = fwrite(phase1_UDSlice_table, sizeof(unsigned char), PHASE1_UDSLICE_SIZE, file);
	fclose(file);
	free(phase1_UDSlice_table);

	GeneratePhase1FlipUDSliceTable(phase1_FlipUDSlice_table);
	std::cout << "Table done! \n";
	file = fopen("phase1_FlipUDSlice_table.txt", "w+");
	bytes_written = fwrite(phase1_FlipUDSlice_table, sizeof(unsigned char), PHASE1_FLIPUDSLICE_SIZE, file);
	fclose(file);
	free(phase1_FlipUDSlice_table);
	
	GeneratePhase2CornerTable(phase2_corner_table);
	std::cout << "Table done! \n";
	file = fopen("phase2_corner_table.txt", "w+");
	bytes_written = fwrite(phase2_corner_table, sizeof(unsigned char), PHASE2_CORNER_SIZE, file);
	fclose(file);
	free(phase2_corner_table);
	
	GeneratePhase2EdgeTable(phase2_edge_table);
	std::cout << "Table done! \n";
	file = fopen("phase2_edge_table.txt", "w+");
	bytes_written = fwrite(phase2_edge_table, sizeof(unsigned char), PHASE2_EDGE_SIZE, file);
	fclose(file);
	free(phase2_edge_table);
	
	GeneratePhase2UDSliceTable(phase2_UDSlice_table);
	std::cout << "Table done! \n";
	file = fopen("phase2_UDSlice_table.txt", "w+");
	bytes_written = fwrite(phase2_UDSlice_table, sizeof(unsigned char), PHASE2_UDSLICE_SIZE, file);
	fclose(file);
	free(phase2_UDSlice_table);
}


