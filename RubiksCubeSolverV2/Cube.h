#pragma once
#ifndef Cube_H
#define Cube_H

#include "Helper.h"

class Cube {
public:
	unsigned char cube[48];

	/*
             00  01  02
			 03  UB  04
             05  06  07

08  09  10   16  17  18   24  25  26   32  33  34
11  LO  12   19  FW  20   27  RR  28   35  BY  36
13  14  15   21  22  23   29  30  31   37  38  39

			 40  41  42
			 43  DG  44
			 45  46  47
	*/
	Cube() {}
	Cube(unsigned char cube[48]);
	Cube(const unsigned char cube[48]);

	void doMove(unsigned char move);
	bool isSolved();

	/*
	 *	Is reached if:
	 *	All the corners are oriented
	 *	All the edges are oriented
	 *	All the middle layer edges are already in the middle layer
	 */
	bool subgoal();

	/*
	
		if white or yellow is facing front or back, corner orientation is: 0
		if white or yellow is facing left or right, corner orientation is: 1
		if white or yellow is facing up or down, corner orientation is:	   2
	
		Permutation.

		value range from 0 to 8! * 3^7 (88179840)
	*/
	int getCornerIndex();

	/*
		Index: 0 for first table.
			   1 for second table.

		
		value range from 0 to 42577920 

	*/
	int getEdgeIndex(int table);


	



	/*
		Return an array of available moves given a last move
	*/
	const unsigned char * getAvailableMoves(unsigned char lastMove);
	const unsigned char * getAvailableMovesInPhase2(unsigned char lastMove);

	bool endsOnCurrectMove(unsigned char lastMove);


private:
	unsigned char getCornerPos(unsigned char index);
	unsigned char getEdgePos(unsigned char index);

	static constexpr unsigned char cornerIndexs[8][3] = {
		{ 16, 10, 5 }, //UFL
		{ 18, 24, 7 }, //UFR
		{ 34, 8, 0 }, //UBL
		{ 32, 26, 2 }, //UBR
		{ 21, 15, 40 }, //DFL
		{ 23, 29, 42 }, //DFR
		{ 39, 13, 45 }, //DBL
		{ 37, 31, 47 } //DBR
	};


	//Front/back first. if not front/back then top/down first
	static constexpr unsigned char edgeIndexs[12][2] = {
		{ 6, 17 }, //UF
		{ 19, 12 }, //FL
		{ 41, 22 }, //DF
		{ 20, 27 }, //FR
		{ 35, 28 },//BR
		{ 1, 33 }, //UB  
		{ 36, 11 },//BL
		{ 46, 38 }, //DB
		{ 44, 30 }, //DR
		{ 4, 25 }, //UR
		{ 3, 9 }, //UL
		{ 43, 14 }, //DL
	};

	static constexpr unsigned char availableMoves[7][18] = {
		{ 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 0, 1, 2, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 0, 1, 2, 3, 4, 5, 9, 10, 11, 12, 13, 14, 15, 16, 17 },
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 13, 14, 15, 16, 17 },
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 16, 17 },
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 }
	};

	static constexpr unsigned char middelLayerEdges[4] = { 8,9,10,11 };


	static constexpr unsigned char currectEndMoves[8] = { 0,2,3,5,6,8,9,11 };


	static constexpr unsigned char availableMovesInPhase2[7][10] = {
		{ 15,16,17,1,4,7,10 },
		{ 12,13,14,1,4,7,10 },
		{ 12,13,14,15,16,17,4,7,10 },
		{ 12,13,14,15,16,17,1,7,10 },
		{ 12,13,14,15,16,17,1,4,10 },
		{ 12,13,14,15,16,17,1,4,7 },
		{ 12,13,14,15,16,17,1,4,7,10 },


	};

};


#endif // !Cube_H
