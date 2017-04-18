#pragma once
#ifndef Helper_T
#define Helper_T

static const char * moves[18] = {"L", "R", "U", "D", "F", "B", "L2", "R2", "U2", "D2", "F2", "B2", "L'", "R'", "U'", "D'", "F'", "B'" };

typedef enum {
	GREEN = 0,
	YELLOW,
	BLUE,
	RED,
	WHITE,
	ORANGE
} RubikColor_T;


const unsigned char solvedCube_T[48] = {
	RubikColor_T::BLUE, RubikColor_T::BLUE, RubikColor_T::BLUE, RubikColor_T::BLUE, RubikColor_T::BLUE, RubikColor_T::BLUE, RubikColor_T::BLUE, RubikColor_T::BLUE,
	RubikColor_T::ORANGE, RubikColor_T::ORANGE, RubikColor_T::ORANGE, RubikColor_T::ORANGE, RubikColor_T::ORANGE, RubikColor_T::ORANGE, RubikColor_T::ORANGE, RubikColor_T::ORANGE,
	RubikColor_T::WHITE, RubikColor_T::WHITE, RubikColor_T::WHITE, RubikColor_T::WHITE, RubikColor_T::WHITE, RubikColor_T::WHITE, RubikColor_T::WHITE, RubikColor_T::WHITE,
	RubikColor_T::RED, RubikColor_T::RED, RubikColor_T::RED, RubikColor_T::RED, RubikColor_T::RED, RubikColor_T::RED, RubikColor_T::RED, RubikColor_T::RED,
	RubikColor_T::YELLOW, RubikColor_T::YELLOW, RubikColor_T::YELLOW, RubikColor_T::YELLOW, RubikColor_T::YELLOW, RubikColor_T::YELLOW, RubikColor_T::YELLOW, RubikColor_T::YELLOW,
	RubikColor_T::GREEN, RubikColor_T::GREEN, RubikColor_T::GREEN, RubikColor_T::GREEN, RubikColor_T::GREEN, RubikColor_T::GREEN, RubikColor_T::GREEN, RubikColor_T::GREEN
};



namespace Helper {
	int factorial(int x, int result = 1);

	int C(int n, int k);
};




#endif // !Helper_T
