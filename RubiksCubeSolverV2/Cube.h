#pragma once
#ifndef Cube_H
#define Cube_H

class Cube {
	unsigned char cube[48];

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


};


#endif // !Cube_H
