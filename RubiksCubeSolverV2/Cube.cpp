#include "stdafx.h"
#include "Cube.h"

Cube::Cube(unsigned char cube[48]) {
	for (int i = 0; i < 48; i++) {
		this->cube[i] = cube[i];
	}
}

Cube::Cube(const unsigned char cube[48]) {
	for (int i = 0; i < 48; i++) {
		this->cube[i] = cube[i];
	}
}

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



void Cube::doMove(unsigned char move) {
	unsigned char temp;
	switch (move)
	{
	case 0: //F CHECKED
		//FACE
		temp = cube[16]; cube[16] = cube[21]; cube[21] = cube[23]; cube[23] = cube[18]; cube[18] = temp;
		temp = cube[17]; cube[17] = cube[19]; cube[19] = cube[22]; cube[22] = cube[20]; cube[20] = temp;
		//SIDES:
		temp = cube[5]; cube[5] = cube[15]; cube[15] = cube[42]; cube[42] = cube[24]; cube[24] = temp;
		temp = cube[6]; cube[6] = cube[12]; cube[12] = cube[41]; cube[41] = cube[27]; cube[27] = temp;
		temp = cube[7]; cube[7] = cube[10]; cube[10] = cube[40]; cube[40] = cube[29]; cube[29] = temp;
		break;
	case 1: //F2 CHECKED
		//FACE
		temp = cube[16]; cube[16] = cube[23]; cube[23] = temp; temp = cube[18]; cube[18] = cube[21]; cube[21] = temp;
		temp = cube[17]; cube[17] = cube[22]; cube[22] = temp; temp = cube[19]; cube[19] = cube[20]; cube[20] = temp;
		//SIDES:
		temp = cube[5]; cube[5] = cube[42]; cube[42] = temp; temp = cube[15]; cube[15] = cube[24]; cube[24] = temp;
		temp = cube[6]; cube[6] = cube[41]; cube[41] = temp; temp = cube[12]; cube[12] = cube[27]; cube[27] = temp;
		temp = cube[7]; cube[7] = cube[40]; cube[40] = temp; temp = cube[10]; cube[10] = cube[29]; cube[29] = temp;
		break;
	case 2: //F' CHECKED
		//FACE
		temp = cube[16]; cube[16] = cube[18]; cube[18] = cube[23]; cube[23] = cube[21]; cube[21] = temp;
		temp = cube[17]; cube[17] = cube[20]; cube[20] = cube[22]; cube[22] = cube[19]; cube[19] = temp;
		//SIDES:
		temp = cube[5]; cube[5] = cube[24]; cube[24] = cube[42]; cube[42] = cube[15]; cube[15] = temp;
		temp = cube[6]; cube[6] = cube[27]; cube[27] = cube[41]; cube[41] = cube[12]; cube[12] = temp;
		temp = cube[7]; cube[7] = cube[29]; cube[29] = cube[40]; cube[40] = cube[10]; cube[10] = temp;
		break;
	case 3: //B CHECKED
		//FACE
		temp = cube[32]; cube[32] = cube[37]; cube[37] = cube[39]; cube[39] = cube[34]; cube[34] = temp;
		temp = cube[33]; cube[33] = cube[35]; cube[35] = cube[38]; cube[38] = cube[36]; cube[36] = temp;
		//SIDES:
		temp = cube[0]; cube[0] = cube[26]; cube[26] = cube[47]; cube[47] = cube[13]; cube[13] = temp;
		temp = cube[1]; cube[1] = cube[28]; cube[28] = cube[46]; cube[46] = cube[11]; cube[11] = temp;
		temp = cube[2]; cube[2] = cube[31]; cube[31] = cube[45]; cube[45] = cube[8]; cube[8] = temp;
		break;
	case 4: //B2 CHECKED
		//FACE
		temp = cube[33]; cube[33] = cube[38]; cube[38] = temp; temp = cube[35]; cube[35] = cube[36]; cube[36] = temp;
		temp = cube[32]; cube[32] = cube[39]; cube[39] = temp; temp = cube[34]; cube[34] = cube[37]; cube[37] = temp;
		//SIDES:
		temp = cube[0]; cube[0] = cube[47]; cube[47] = temp; temp = cube[13]; cube[13] = cube[26]; cube[26] = temp;
		temp = cube[1]; cube[1] = cube[46]; cube[46] = temp; temp = cube[11]; cube[11] = cube[28]; cube[28] = temp;
		temp = cube[2]; cube[2] = cube[45]; cube[45] = temp; temp = cube[8]; cube[8] = cube[31]; cube[31] = temp;
		break;
	case 5: //B' CHECKED
		//FACE
		temp = cube[32]; cube[32] = cube[34]; cube[34] = cube[39]; cube[39] = cube[37]; cube[37] = temp;
		temp = cube[33]; cube[33] = cube[36]; cube[36] = cube[38]; cube[38] = cube[35]; cube[35] = temp;
		//SIDES:
		temp = cube[0]; cube[0] = cube[13]; cube[13] = cube[47]; cube[47] = cube[26]; cube[26] = temp;
		temp = cube[1]; cube[1] = cube[11]; cube[11] = cube[46]; cube[46] = cube[28]; cube[28] = temp;
		temp = cube[2]; cube[2] = cube[8]; cube[8] = cube[45]; cube[45] = cube[31]; cube[31] = temp;
		break;
	case 6: //L CHECKED
		//FACE
		temp = cube[8]; cube[8] = cube[13]; cube[13] = cube[15]; cube[15] = cube[10]; cube[10] = temp;
		temp = cube[9]; cube[9] = cube[11]; cube[11] = cube[14]; cube[14] = cube[12]; cube[12] = temp;
		//SIDES:
		temp = cube[0]; cube[0] = cube[39]; cube[39] = cube[40]; cube[40] = cube[16]; cube[16] = temp;
		temp = cube[3]; cube[3] = cube[36]; cube[36] = cube[43]; cube[43] = cube[19]; cube[19] = temp;
		temp = cube[5]; cube[5] = cube[34]; cube[34] = cube[45]; cube[45] = cube[21]; cube[21] = temp;
		break;
	case 7: //L2 CHECKED
		//FACE
		temp = cube[8]; cube[8] = cube[15]; cube[15] = temp; temp = cube[10]; cube[10] = cube[13]; cube[13] = temp;
		temp = cube[9]; cube[9] = cube[14]; cube[14] = temp; temp = cube[11]; cube[11] = cube[12]; cube[12] = temp;
		//SIDES:
		temp = cube[0]; cube[0] = cube[40]; cube[40] = temp; temp = cube[16]; cube[16] = cube[39]; cube[39] = temp;
		temp = cube[3]; cube[3] = cube[43]; cube[43] = temp; temp = cube[19]; cube[19] = cube[36]; cube[36] = temp;
		temp = cube[5]; cube[5] = cube[45]; cube[45] = temp; temp = cube[21]; cube[21] = cube[34]; cube[34] = temp;
		break;
	case 8: //L' CHECKED
		//FACE
		temp = cube[8]; cube[8] = cube[10]; cube[10] = cube[15]; cube[15] = cube[13]; cube[13] = temp;
		temp = cube[9]; cube[9] = cube[12]; cube[12] = cube[14]; cube[14] = cube[11]; cube[11] = temp;
		//SIDES:
		temp = cube[0]; cube[0] = cube[16]; cube[16] = cube[40]; cube[40] = cube[39]; cube[39] = temp;
		temp = cube[3]; cube[3] = cube[19]; cube[19] = cube[43]; cube[43] = cube[36]; cube[36] = temp;
		temp = cube[5]; cube[5] = cube[21]; cube[21] = cube[45]; cube[45] = cube[34]; cube[34] = temp;
		break;
	case 9: //R CHECKED
		//FACE
		temp = cube[24]; cube[24] = cube[29]; cube[29] = cube[31]; cube[31] = cube[26]; cube[26] = temp;
		temp = cube[25]; cube[25] = cube[27]; cube[27] = cube[30]; cube[30] = cube[28]; cube[28] = temp;
		//SIDES:
		temp = cube[18]; cube[18] = cube[42]; cube[42] = cube[37]; cube[37] = cube[2]; cube[2] = temp;
		temp = cube[20]; cube[20] = cube[44]; cube[44] = cube[35]; cube[35] = cube[4]; cube[4] = temp;
		temp = cube[23]; cube[23] = cube[47]; cube[47] = cube[32]; cube[32] = cube[7]; cube[7] = temp;
		break;
	case 10: //R2 CHECKED
		//FACE
		temp = cube[24]; cube[24] = cube[31]; cube[31] = temp; temp = cube[26]; cube[26] = cube[29]; cube[29] = temp;
		temp = cube[25]; cube[25] = cube[30]; cube[30] = temp; temp = cube[27]; cube[27] = cube[28]; cube[28] = temp;
		//SIDES:
		temp = cube[18]; cube[18] = cube[37]; cube[37] = temp; temp = cube[2]; cube[2] = cube[42]; cube[42] = temp;
		temp = cube[20]; cube[20] = cube[35]; cube[35] = temp; temp = cube[4]; cube[4] = cube[44]; cube[44] = temp;
		temp = cube[23]; cube[23] = cube[32]; cube[32] = temp; temp = cube[7]; cube[7] = cube[47]; cube[47] = temp;
		break;
	case 11: //R' CHECKED
		//FACE
		temp = cube[24]; cube[24] = cube[26]; cube[26] = cube[31]; cube[31] = cube[29]; cube[29] = temp;
		temp = cube[25]; cube[25] = cube[28]; cube[28] = cube[30]; cube[30] = cube[27]; cube[27] = temp;
		//SIDES:
		temp = cube[18]; cube[18] = cube[2]; cube[2] = cube[37]; cube[37] = cube[42]; cube[42] = temp;
		temp = cube[20]; cube[20] = cube[4]; cube[4] = cube[35]; cube[35] = cube[44]; cube[44] = temp;
		temp = cube[23]; cube[23] = cube[7]; cube[7] = cube[32]; cube[32] = cube[47]; cube[47] = temp;
		break;
	case 12: //U CHECKED
		//FACE
		temp = cube[0]; cube[0] = cube[5]; cube[5] = cube[7]; cube[7] = cube[2]; cube[2] = temp;
		temp = cube[1]; cube[1] = cube[3]; cube[3] = cube[6]; cube[6] = cube[4]; cube[4] = temp;
		//SIDES:
		temp = cube[8]; cube[8] = cube[16]; cube[16] = cube[24]; cube[24] = cube[32]; cube[32] = temp;
		temp = cube[9]; cube[9] = cube[17]; cube[17] = cube[25]; cube[25] = cube[33]; cube[33] = temp;
		temp = cube[10]; cube[10] = cube[18]; cube[18] = cube[26]; cube[26] = cube[34]; cube[34] = temp;
		break;
	case 13: //U2 CHECKED
		//FACE
		temp = cube[0]; cube[0] = cube[7]; cube[7] = temp; temp = cube[2]; cube[2] = cube[5]; cube[5] = temp;
		temp = cube[1]; cube[1] = cube[6]; cube[6] = temp; temp = cube[3]; cube[3] = cube[4]; cube[4] = temp;
		//SIDES:
		temp = cube[8]; cube[8] = cube[24]; cube[24] = temp; temp = cube[16]; cube[16] = cube[32]; cube[32] = temp;
		temp = cube[9]; cube[9] = cube[25]; cube[25] = temp; temp = cube[17]; cube[17] = cube[33]; cube[33] = temp;
		temp = cube[10]; cube[10] = cube[26]; cube[26] = temp; temp = cube[18]; cube[18] = cube[34]; cube[34] = temp;
		break;
	case 14: //U' CHECKED 
		 //FACE
		temp = cube[0]; cube[0] = cube[2]; cube[2] = cube[7]; cube[7] = cube[5]; cube[5] = temp;
		temp = cube[1]; cube[1] = cube[4]; cube[4] = cube[6]; cube[6] = cube[3]; cube[3] = temp;
		//SIDES:
		temp = cube[8]; cube[8] = cube[32]; cube[32] = cube[24]; cube[24] = cube[16]; cube[16] = temp;
		temp = cube[9]; cube[9] = cube[33]; cube[33] = cube[25]; cube[25] = cube[17]; cube[17] = temp;
		temp = cube[10]; cube[10] = cube[34]; cube[34] = cube[26]; cube[26] = cube[18]; cube[18] = temp;
		break;
	case 15: //D CHECKED
		//FACE
		temp = cube[40]; cube[40] = cube[45]; cube[45] = cube[47]; cube[47] = cube[42]; cube[42] = temp;
		temp = cube[41]; cube[41] = cube[43]; cube[43] = cube[46]; cube[46] = cube[44]; cube[44] = temp;
		//SIDES:
		temp = cube[13]; cube[13] = cube[37]; cube[37] = cube[29]; cube[29] = cube[21]; cube[21] = temp;
		temp = cube[14]; cube[14] = cube[38]; cube[38] = cube[30]; cube[30] = cube[22]; cube[22] = temp;
		temp = cube[15]; cube[15] = cube[39]; cube[39] = cube[31]; cube[31] = cube[23]; cube[23] = temp;
		break;
	case 16: //D2 CHECKED
			//FACE
		temp = cube[40]; cube[40] = cube[47]; cube[47] = temp; temp = cube[42]; cube[42] = cube[45]; cube[45] = temp;
		temp = cube[41]; cube[41] = cube[46]; cube[46] = temp; temp = cube[43]; cube[43] = cube[44]; cube[44] = temp;
		//SIDES:
		temp = cube[13]; cube[13] = cube[29]; cube[29] = temp; temp = cube[21]; cube[21] = cube[37]; cube[37] = temp;
		temp = cube[14]; cube[14] = cube[30]; cube[30] = temp; temp = cube[22]; cube[22] = cube[38]; cube[38] = temp;
		temp = cube[15]; cube[15] = cube[31]; cube[31] = temp; temp = cube[23]; cube[23] = cube[39]; cube[39] = temp;
		break;
	case 17: //D' CHECKED
		//FACE
		temp = cube[40]; cube[40] = cube[42]; cube[42] = cube[47]; cube[47] = cube[45]; cube[45] = temp;
		temp = cube[41]; cube[41] = cube[44]; cube[44] = cube[46]; cube[46] = cube[43]; cube[43] = temp;
		//SIDES:
		temp = cube[13]; cube[13] = cube[21]; cube[21] = cube[29]; cube[29] = cube[37]; cube[37] = temp;
		temp = cube[14]; cube[14] = cube[22]; cube[22] = cube[30]; cube[30] = cube[38]; cube[38] = temp;
		temp = cube[15]; cube[15] = cube[23]; cube[23] = cube[31]; cube[31] = cube[39]; cube[39] = temp;
		break;
	default:
		break;
	}

}

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

bool Cube::isSolved() {
	for (int i = 0; i < 48; i++) {
		if (cube[i] != solvedCube_T[i]) return false;
	}
	return true;
}

bool Cube::isSolvable() {

	//Must be even permutation
	int sum = 0;
	unsigned char arr[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	unsigned char arrC[8] = { 0,1,2,3,4,5,6,7 };
	for (int i = 0; i < 12; i++) {
		int num = getEdgePos(i);
		int pos = 0;
		while (num != arr[pos]) pos++;

		sum += pos;
		for (int j = pos; j < 12 - 1 - i; j++) {
			arr[j] = arr[j + 1];
		}
	}

	for (int i = 0; i < 8; i++) {
		int num = getCornerPos(i);
		int pos = 0;
		while (num != arrC[pos]) pos++;

		sum += pos;
		for (int j = pos; j < 8 - 1 - i; j++) {
			arrC[j] = arrC[j + 1];
		}
	}
	if (sum % 2 != 0) {
		std::cout << "Permutation is wrong! Sum: " << sum << "\n";
		return false;
	}

	sum = 0;
	unsigned char or [12];
	for (int i = 0; i < 12; i++) {
		if (cube[edgeIndexs[i][0]] == RubikColor_T::RED || cube[edgeIndexs[i][0]] == RubikColor_T::ORANGE ||
			((cube[edgeIndexs[i][0]] == RubikColor_T::WHITE || cube[edgeIndexs[i][0]] == RubikColor_T::YELLOW) &&
			(cube[edgeIndexs[i][1]] == RubikColor_T::BLUE || cube[edgeIndexs[i][1]] == RubikColor_T::GREEN)))
			sum += 1; else sum += 0;
	}
	if (sum % 2 != 0) {
		std::cout << "Edge OR is wrong! Sum: " << sum << "\n";
		return false;
	}

	sum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			if (cube[cornerIndexs[i][j]] == RubikColor_T::WHITE || cube[cornerIndexs[i][j]] == RubikColor_T::YELLOW) { //Changed ogange to yellow
				sum += j;
				break;
			}
		}
	}
	if (sum % 3 != 0) {
		std::cout << "Corner OR is wrong! Sum: " << sum << "\n";
		return false;
	}



	return true;
}


bool Cube::subgoal()
{
	//checking corner orientation:
	for (int i = 0; i < 8; i++) {
		if (cube[cornerIndexs[i][0]] != RubikColor_T::WHITE && cube[cornerIndexs[i][0]] != RubikColor_T::YELLOW) return false;
	}

	//check edge orientation:
	for (int i = 0; i < 12; i++) {
		if (cube[edgeIndexs[i][0]] == RubikColor_T::RED || cube[edgeIndexs[i][0]] == RubikColor_T::ORANGE || ((cube[edgeIndexs[i][0]] == RubikColor_T::WHITE || cube[edgeIndexs[i][0]] == RubikColor_T::YELLOW) && (cube[edgeIndexs[i][1]] == RubikColor_T::BLUE || cube[edgeIndexs[i][1]] == RubikColor_T::GREEN))) return false;
	}

	//Checking if middel layer has all its edges.
	for (int i = 0; i < 4; i++) {
		if (getEdgePos(middelLayerEdges[i]) != middelLayerEdges[i]) return false;
	}

	return true;
}

int Cube::getCornerIndex()
{
	unsigned char pm[8] = {0,0,0,0,0,0,0,0};

	for (int i = 0; i < 8; i++) {
		pm[i] = getCornerPos(i);
		//std::cout << "permutation " << i << ":" << unsigned(pm[i]) << "\n";
	}


	int tp = 0;
	for (int i = 0; i < 8 - 1; i++) {
		tp *= (8 - i);
		for (int j = i + 1; j < 8; j++) {
			if (pm[i] > pm[j]) tp++;
			//if (pm[i] == pm[j]) std::cout << "Something went wrong (equal): " << unsigned(pm[i]) << "\n";
		}
	}
	//std::cout << "tp: " << tp << "\n";
	if (tp > 40320) {
		std::cout << "Something went wrong: " << tp << "\n";
	}


	unsigned char or [8] = {0,0,0,0,0,0,0,0};
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			if (cube[cornerIndexs[i][j]] == RubikColor_T::WHITE || cube[cornerIndexs[i][j]] == RubikColor_T::YELLOW) { //Changed ogange to yellow
				or[i] = j;
				break;
			}
		}
	}
	int to = 0;
	for (int i = 0; i < 8-1; i++) {
		to *= 3;
		to += or[i];
		
	}
	 
	//std::cout << "to: " << to << ", tp " << tp << " result: " << 2187 * tp + to;
	return 2187 * tp + to;
}

int Cube::getEdgeIndex(int table)
{
	unsigned char iv[6] = { 0,0,0,0,0,0 };
	unsigned char arr[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	/*

	unsigned char lookingFor[6] = { 0,0,0,0,0,0 };
	unsigned char pm[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	unsigned char iv[6] = { 0,0,0,0,0,0 };
	int index = 0;
	for (int i = 0; i < 12; i++) {
		pm[i] = getEdgePos(i);
		if (pm[i] >= 6 * table && pm[i] < 6 * (table + 1)) {
			lookingFor[index] = i;
			index++;
		}
	}
	if (table == 1) {
		for (int i = 0; i < 6; i++) {
			for (int j = lookingFor[i] + 1; j < 12; j++) {
				if (pm[lookingFor[i]] > pm[j]) iv[i]++;
			}
		}
	} else {
		for (int i = 0; i < 6; i++) {
			for (int j = lookingFor[i] - 1; j >= 0; j--) {
				if (pm[lookingFor[i]] < pm[j]) iv[i]++;
			}
		}
	}
	*/

	for (int i = 0; i < 6; i++) {
		int num = getEdgePos(i + 6 * table);
		int pos = 0;
		while (num != arr[pos]) pos++;
		
		iv[i] = pos;
		for (int j = pos; j < 12 - 1 - i; j++) {
			arr[j] = arr[j + 1];
		}
	}
	/*
	int tp = 0;
	tp = (39916800 * iv[0] +
		   3628800 * iv[1] +
		    362880 * iv[2] +
		     40320 * iv[3] +
		      5040 * iv[4] +
		       720 * iv[5]) / 720;

	
	//if (table == 0) std::cout << "tp: " << tp << "\n";
	if (tp > 665279 || tp < 0) {
		std::cout << "Something went wrong (tp): " << tp << "\n";
	}

	*/
	unsigned char or [6];
	for (int i = 6 * table; i < 6 * (table + 1); i++) {
		if (cube[edgeIndexs[i][0]] == RubikColor_T::RED || cube[edgeIndexs[i][0]] == RubikColor_T::ORANGE || 
			((cube[edgeIndexs[i][0]] == RubikColor_T::WHITE || cube[edgeIndexs[i][0]] == RubikColor_T::YELLOW) && 
			(cube[edgeIndexs[i][1]] == RubikColor_T::BLUE || cube[edgeIndexs[i][1]] == RubikColor_T::GREEN)))
				or [i - 6 * table] = 1; else or [i - 6 * table] = 0;
		/*
		if (i < 12 - 4) {
			if (cube[edgeIndexs[i][0]] == RubikColor_T::RED || cube[edgeIndexs[i][0]] == RubikColor_T::ORANGE || ((cube[edgeIndexs[i][0]] == RubikColor_T::WHITE || cube[edgeIndexs[i][0]] == RubikColor_T::YELLOW) && (cube[edgeIndexs[i][1]] == RubikColor_T::BLUE || cube[edgeIndexs[i][1]] == RubikColor_T::GREEN))) or[i - 6 * table] = 1; else or[i - 6 * table] = 0;
		} else {
			if (cube[edgeIndexs[i][0]] == RubikColor_T::RED || cube[edgeIndexs[i][0]] == RubikColor_T::ORANGE || ((cube[edgeIndexs[i][0]] == RubikColor_T::WHITE || cube[edgeIndexs[i][0]] == RubikColor_T::YELLOW) && (cube[edgeIndexs[i][1]] == RubikColor_T::BLUE || cube[edgeIndexs[i][1]] == RubikColor_T::GREEN))) or [i - 6 * table] = 1; else or [i - 6 * table] = 0;
		}
		*/
	}
	/*
	int to =
		or [5] * 32 +
		or [4] * 16 +
		or [3] * 8 +
		or [2] * 4 +
		or [1] * 2 +
		or [0];

	for (int i = 0; i < 6; i++) {
		to *= 2;
		to += or [i];
	}
	*/
	/*
	//std::cout << "to: " << to << "\n";
	if (to > 64 || to < 0) {
		std::cout << "Something went wrong (to): " << to << "\n";
	}

	
	for (int i = 6 * table; i <  6 * (table + 1); i++) {
		std::cout << unsigned(or [i - 6 * table]) << " " << unsigned(edgeIndexs[i][0]) << " " << unsigned(cube[edgeIndexs[i][0]]) << " " << i << " " << table <<"\n";
	}
	*/
	int index = (iv[0] + or [0] * 12) * 1774080 +
		(iv[1] + or [1] * 11) * 80640 +
		(iv[2] + or [2] * 10) * 4032 +
		(iv[3] + or [3] * 9) * 224 +
		(iv[4] + or [4] * 8) * 14 +
		(iv[5] + or [5] * 7);


	if (index >= 42577920) {
		fprintf(stderr, "\nWARNING: HASH RETURNED %d\n", index);
		index = *((int *)0x0); /* sigsev */
	}


	//std::cout << "Index (" << table << "): " << (64 * tp + to) << "\n";
	return index;
}

unsigned char Cube::getPhase1Heuristic(unsigned char * cornerTable, unsigned char * edgeTable, unsigned char * UDSliceTable) {
	return 0;
}

unsigned char Cube::getPhase2Heuristic(unsigned char * cornerTable, unsigned char * edgeTable, unsigned char * UDSliceTable) {
	return 0;
}



const unsigned char * Cube::getAvailableMoves(unsigned char lastMove)  {
	switch (lastMove)
	{
	case 0:
	case 1:
	case 2:
		return availableMoves[0];
	case 3:
	case 4:
	case 5:
		return availableMoves[1];
	case 6:
	case 7:
	case 8:
		return availableMoves[2];
	case 9:
	case 10:
	case 11:
		return availableMoves[3];
	case 12:
	case 13:
	case 14:
		return availableMoves[4];
	case 15:
	case 16:
	case 17:
		return availableMoves[5];
	case 255:
		return availableMoves[6];
	}

	return nullptr;
}

const unsigned char * Cube::getAvailableMovesInPhase2(unsigned char lastMove)
{

	switch (lastMove)
	{
	case 12:
	case 13:
	case 14:
		return availableMovesInPhase2[0];
	case 15:
	case 16:
	case 17:
		return availableMovesInPhase2[1];
	case 1:
		return availableMovesInPhase2[2];
	case 4:
		return availableMovesInPhase2[3];
	case 7:
		return availableMovesInPhase2[4];
	case 10:
		return availableMovesInPhase2[5];
	case 255:
		return availableMovesInPhase2[6];
	}


	return nullptr;
}

bool Cube::endsOnCurrectMove(unsigned char lastMove)
{
	for (int i = 0; i < 8; i++) {
		if (lastMove == currectEndMoves[i]) return true;
	}
	return lastMove == 255;
}

int Cube::getPhase1CornerIndex() {

	int index = 0;
	int or = 0;
	for (int i = 0; i < 7; i++) {
		or = 0;
		for (int j = 0; j < 3; j++) {
			if (cube[cornerIndexs[i][j]] == RubikColor_T::WHITE || cube[cornerIndexs[i][j]] == RubikColor_T::YELLOW) { //Changed ogange to yellow
				or = j;
				break;
			}
		}
		index = 3 * index + or ;
	}
	return index;
}

int Cube::getPhase1EdgeIndex() {
	int index = 0, or ;
	for (int i = 0; i < 11; i++) {
		if (cube[edgeIndexs[i][0]] == RubikColor_T::RED || cube[edgeIndexs[i][0]] == RubikColor_T::ORANGE ||
			((cube[edgeIndexs[i][0]] == RubikColor_T::WHITE || cube[edgeIndexs[i][0]] == RubikColor_T::YELLOW) &&
			(cube[edgeIndexs[i][1]] == RubikColor_T::BLUE || cube[edgeIndexs[i][1]] == RubikColor_T::GREEN))) {
			or = 1;
		} else {
			or = 0;
		}
		index = index * 2 + or ;
	}
	return index;
}

int Cube::getPhase1UDSliceIndex() {
	bool occupied[12];

	for (int i = 0; i < 12; i++) occupied[i] = false;
	for (int i = 0; i < 12; i++) if (getEdgePos(i) >= 8) occupied[i] = true;
	
	int k = 3, index = 0, n = 11;
	while (k >= 0) {
		if (occupied[n]) k--;
		else index = index + Helper::C(n, k);
		n--;
	}
	return index;
}

int Cube::getPhase1FlipUDSliceIndex() {

	int edge = getPhase1EdgeIndex();
	int ud = getPhase1UDSliceIndex();

	if (ud >= 495) {
		std::cout << "Error in ud: " << ud << "\n";
		return 0;
	}
		

	if (edge >= 2048) {
		std::cout << "Error in edge: " << edge << "\n";
		return 0;
	}
		

	return edge * 495 + ud;
}

int Cube::getPhase2CornerIndex() {
	unsigned char pm[8] = { 0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 8; i++) {
		pm[i] = getCornerPos(i);
	}


	int tp = 0;
	for (int i = 0; i < 8 - 1; i++) {
		tp *= (8 - i);
		for (int j = i + 1; j < 8; j++) {
			if (pm[i] > pm[j]) tp++;
		}
	}
	return tp;
}

int Cube::getPhase2EdgeIndex() {
	/*
	int i, j, index = 0, s;

	for (i = 8; i > 0; i--) {
		s = 0;
		for (j = i - 1; j >= 0; j--) {
			if (getEdgePos(j) > getEdgePos(i)) s++;
		}
		index = (index + s)*i;
	}
	return index;
	*/

	unsigned char pm[8] = { 0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 8; i++) {
		pm[i] = getEdgePos(i);
	}


	int tp = 0;
	for (int i = 0; i < 8 - 1; i++) {
		tp *= (8 - i);
		for (int j = i + 1; j < 8; j++) {
			if (pm[i] > pm[j]) tp++;
		}
	}
	return tp;
}

int Cube::getPhase2UDSliceIndex() {

	int j = 0, k, s, x = 0, e;
	unsigned char arr[4] = {0,0,0,0};


	for (int i = 0; i < 12; i++) {
		e = getEdgePos(i);
		if (e >= 8) {
			arr[j] = e;
			j++;
		}
	}

	for (j = 3; j >= 1; j--) {
		s = 0;
		for (k = j - 1; k >= 0; k--) {
			if (arr[k] > arr[j]) s++;
		}
		x = (x + s)*j;
	}
	return x;
}



unsigned char Cube::getCornerPos(unsigned char index)
{

	if ((cube[cornerIndexs[index][0]] == RubikColor_T::WHITE || cube[cornerIndexs[index][0]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][0]] == RubikColor_T::BLUE) &&
		(cube[cornerIndexs[index][1]] == RubikColor_T::WHITE || cube[cornerIndexs[index][1]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][1]] == RubikColor_T::BLUE) &&
		(cube[cornerIndexs[index][2]] == RubikColor_T::WHITE || cube[cornerIndexs[index][2]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][2]] == RubikColor_T::BLUE)) return 0;
	else if ((cube[cornerIndexs[index][0]] == RubikColor_T::WHITE || cube[cornerIndexs[index][0]] == RubikColor_T::RED || cube[cornerIndexs[index][0]] == RubikColor_T::BLUE) &&
		(cube[cornerIndexs[index][1]] == RubikColor_T::WHITE || cube[cornerIndexs[index][1]] == RubikColor_T::RED || cube[cornerIndexs[index][1]] == RubikColor_T::BLUE) &&
		(cube[cornerIndexs[index][2]] == RubikColor_T::WHITE || cube[cornerIndexs[index][2]] == RubikColor_T::RED || cube[cornerIndexs[index][2]] == RubikColor_T::BLUE)) return 1;
	else if ((cube[cornerIndexs[index][0]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][0]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][0]] == RubikColor_T::BLUE) &&
		(cube[cornerIndexs[index][1]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][1]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][1]] == RubikColor_T::BLUE) &&
		(cube[cornerIndexs[index][2]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][2]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][2]] == RubikColor_T::BLUE)) return 2;
	else if ((cube[cornerIndexs[index][0]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][0]] == RubikColor_T::RED || cube[cornerIndexs[index][0]] == RubikColor_T::BLUE) &&
		(cube[cornerIndexs[index][1]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][1]] == RubikColor_T::RED || cube[cornerIndexs[index][1]] == RubikColor_T::BLUE) &&
		(cube[cornerIndexs[index][2]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][2]] == RubikColor_T::RED || cube[cornerIndexs[index][2]] == RubikColor_T::BLUE)) return 3;
	else if ((cube[cornerIndexs[index][0]] == RubikColor_T::WHITE || cube[cornerIndexs[index][0]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[cornerIndexs[index][1]] == RubikColor_T::WHITE || cube[cornerIndexs[index][1]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][1]] == RubikColor_T::GREEN) &&
		(cube[cornerIndexs[index][2]] == RubikColor_T::WHITE || cube[cornerIndexs[index][2]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][2]] == RubikColor_T::GREEN)) return 4;
	else if ((cube[cornerIndexs[index][0]] == RubikColor_T::WHITE || cube[cornerIndexs[index][0]] == RubikColor_T::RED || cube[cornerIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[cornerIndexs[index][1]] == RubikColor_T::WHITE || cube[cornerIndexs[index][1]] == RubikColor_T::RED || cube[cornerIndexs[index][1]] == RubikColor_T::GREEN) &&
		(cube[cornerIndexs[index][2]] == RubikColor_T::WHITE || cube[cornerIndexs[index][2]] == RubikColor_T::RED || cube[cornerIndexs[index][2]] == RubikColor_T::GREEN)) return 5;
	else if ((cube[cornerIndexs[index][0]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][0]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[cornerIndexs[index][1]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][1]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][1]] == RubikColor_T::GREEN) &&
		(cube[cornerIndexs[index][2]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][2]] == RubikColor_T::ORANGE || cube[cornerIndexs[index][2]] == RubikColor_T::GREEN)) return 6;
	else if ((cube[cornerIndexs[index][0]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][0]] == RubikColor_T::RED || cube[cornerIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[cornerIndexs[index][1]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][1]] == RubikColor_T::RED || cube[cornerIndexs[index][1]] == RubikColor_T::GREEN) &&
		(cube[cornerIndexs[index][2]] == RubikColor_T::YELLOW || cube[cornerIndexs[index][2]] == RubikColor_T::RED || cube[cornerIndexs[index][2]] == RubikColor_T::GREEN)) return 7;


	return -1;
}

unsigned char Cube::getEdgePos(unsigned char index)
{
	/*
	if ((cube[edgeIndexs[index][0]] == RubikColor_T::WHITE || cube[edgeIndexs[index][0]] == RubikColor_T::BLUE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::WHITE || cube[edgeIndexs[index][1]] == RubikColor_T::BLUE)) return 0;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::WHITE || cube[edgeIndexs[index][0]] == RubikColor_T::ORANGE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::WHITE || cube[edgeIndexs[index][1]] == RubikColor_T::ORANGE)) return 1;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::WHITE || cube[edgeIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::WHITE || cube[edgeIndexs[index][1]] == RubikColor_T::GREEN)) return 2;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::WHITE || cube[edgeIndexs[index][0]] == RubikColor_T::RED) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::WHITE || cube[edgeIndexs[index][1]] == RubikColor_T::RED)) return 3;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::BLUE || cube[edgeIndexs[index][0]] == RubikColor_T::ORANGE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::BLUE || cube[edgeIndexs[index][1]] == RubikColor_T::ORANGE)) return 4;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::RED || cube[edgeIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::RED || cube[edgeIndexs[index][1]] == RubikColor_T::GREEN)) return 5;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][0]] == RubikColor_T::BLUE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][1]] == RubikColor_T::BLUE)) return 6;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][0]] == RubikColor_T::ORANGE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][1]] == RubikColor_T::ORANGE)) return 7;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][1]] == RubikColor_T::GREEN)) return 8;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][0]] == RubikColor_T::RED) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][1]] == RubikColor_T::RED)) return 9;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::BLUE || cube[edgeIndexs[index][0]] == RubikColor_T::RED) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::BLUE || cube[edgeIndexs[index][1]] == RubikColor_T::RED)) return 10;
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::GREEN || cube[edgeIndexs[index][0]] == RubikColor_T::ORANGE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::GREEN || cube[edgeIndexs[index][1]] == RubikColor_T::ORANGE)) return 11;
	*/

	if ((cube[edgeIndexs[index][0]] == RubikColor_T::BLUE || cube[edgeIndexs[index][0]] == RubikColor_T::RED) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::BLUE || cube[edgeIndexs[index][1]] == RubikColor_T::RED)) return 0; //UR
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::WHITE || cube[edgeIndexs[index][0]] == RubikColor_T::BLUE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::WHITE || cube[edgeIndexs[index][1]] == RubikColor_T::BLUE)) return 1; //UF
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::BLUE || cube[edgeIndexs[index][0]] == RubikColor_T::ORANGE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::BLUE || cube[edgeIndexs[index][1]] == RubikColor_T::ORANGE)) return 2; //UL
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][0]] == RubikColor_T::BLUE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][1]] == RubikColor_T::BLUE)) return 3; //UB
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::RED || cube[edgeIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::RED || cube[edgeIndexs[index][1]] == RubikColor_T::GREEN)) return 4; //DR
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::WHITE || cube[edgeIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::WHITE || cube[edgeIndexs[index][1]] == RubikColor_T::GREEN)) return 5; //DF
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::GREEN || cube[edgeIndexs[index][0]] == RubikColor_T::ORANGE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::GREEN || cube[edgeIndexs[index][1]] == RubikColor_T::ORANGE)) return 6; //DL
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][0]] == RubikColor_T::GREEN) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][1]] == RubikColor_T::GREEN)) return 7; //DB
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::WHITE || cube[edgeIndexs[index][0]] == RubikColor_T::RED) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::WHITE || cube[edgeIndexs[index][1]] == RubikColor_T::RED)) return 8; //FR
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::WHITE || cube[edgeIndexs[index][0]] == RubikColor_T::ORANGE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::WHITE || cube[edgeIndexs[index][1]] == RubikColor_T::ORANGE)) return 9; //FL
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][0]] == RubikColor_T::ORANGE) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][1]] == RubikColor_T::ORANGE)) return 10; //BL
	else if ((cube[edgeIndexs[index][0]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][0]] == RubikColor_T::RED) &&
		(cube[edgeIndexs[index][1]] == RubikColor_T::YELLOW || cube[edgeIndexs[index][1]] == RubikColor_T::RED)) return 11; //BR
	
	
	
	

	return -1;
}
