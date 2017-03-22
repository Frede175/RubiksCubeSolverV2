#pragma once
#ifndef Cube_H
#define Cube_H

#include "Helper.h"

class Cube {
	unsigned char cube[48];

	const unsigned char cornerIndexs[8][3] = {
		{16, 10, 5}, //UFL
		{18, 24, 7}, //UFR
		{34, 8, 0}, //UBL
		{32, 26, 2}, //UBR
		{21, 15, 40}, //DFL
		{23, 29, 42}, //DFR
		{39, 13, 45}, //DBL
		{37, 31, 47} //DBR
	};

	/*
             00  01  02
			 03  U   04
             05  06  07

08  09  10   16  17  18   24  25  26   32  33  34
11  L   12   19  F   20   27  R   28   35  B   36
13  14  15   21  22  23   29  30  31   37  38  39

			 40  41  42
			 43  D   44
			 45  46  47
	*/

	Cube(unsigned char cube[54]);




	void doMove(unsigned char move);
	bool isSolved();


	/*
	
		if white or yellow is face front or back corner orientation is: 0
		if white or yellow is face left or right corner orientation is: 1
		if white or yellow is face up or down corner orientation is:	2
	
		This returns an index from all the corners between 0 and 3^(8-1) - 1
	*/
	int getCornerIndex();

	/*
		if ()

	*/
	int getEdgeIndex();

private:
	unsigned char getCornerPos(unsigned char index);


};


#endif // !Cube_H
