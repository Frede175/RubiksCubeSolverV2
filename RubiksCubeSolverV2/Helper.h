#pragma once
#ifndef Helper_T
#define Helper_T

static const char * moves[18] = {"L", "R", "U", "D", "F", "B", "L2", "R2", "U2", "D2", "F2", "B2", "L'", "R'", "U'", "D'", "F'", "B'" };


namespace Helper {
	void doMove(unsigned char * cube[], char * move);
};


#endif // !Helper_T
