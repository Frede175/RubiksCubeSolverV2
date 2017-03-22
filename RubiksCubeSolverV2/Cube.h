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

	Cube(unsigned char cube[54]);
	Cube(const unsigned char cube[54]);

	void doMove(unsigned char move);
	bool isSolved();

	/*
	
		if white or yellow is facing front or back, corner orientation is: 0
		if white or yellow is facing left or right, corner orientation is: 1
		if white or yellow is facing up or down, corner orientation is:	   2
	
		Permutation.

		value range from 0 to 44069760
	*/
	long int getCornerIndex();

	/*
		if 
		value range from 0 to 490258137600
	*/
	int getEdgeIndex();

private:
	unsigned char getCornerPos(unsigned char index);
	unsigned char getEdgePos(unsigned char index);

	const unsigned char cornerIndexs[8][3] = {
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
	const unsigned char edgeIndexs[12][2] = {
		{ 17, 6 }, //White or yellow 
		{ 19, 12 }, //White or yellow
		{ 22, 41 }, //White or yellow
		{ 20, 27 }, //White or yellow
		{ 35, 28 }, //White or yellow
		{ 33, 1 }, //White or yellow
		{ 36, 11 }, //White or yellow
		{ 38, 46 }, //White or yellow
		{ 44, 30 }, //Blue or green
		{ 4, 25 }, //Blue or green
		{ 3, 9 }, //Blue or green
		{ 43, 14 }  //Blue or green
	};

};


#endif // !Cube_H
