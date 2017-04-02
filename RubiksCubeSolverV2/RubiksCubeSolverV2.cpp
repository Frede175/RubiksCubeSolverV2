// RubiksCubeSolverV2.cpp : Defines the entry point for the console application.
//




#include "stdafx.h"
#include "Helper.h"
#include "Cube.h"
#include "Tables.h"
#include "Solver.h"
#include "Camera.h"
#include <thread>    
//https://www.youtube.com/watch?v=7SM5OD2pZKY c++ opencv instalation

int main()
{


	//Camera test:
	//Camera camera(0);

	//camera.calibrate();

//	std::cout << "Donme";
	//camera.loop();
	//std::thread camThread(&Camera::loop, &camera);

//	camThread.join();


	/*


	unsigned char c[48] = {
		RubikColor_T::ORANGE, RubikColor_T::BLUE, RubikColor_T::BLUE, RubikColor_T::RED, RubikColor_T::BLUE, RubikColor_T::GREEN, RubikColor_T::YELLOW, RubikColor_T::GREEN,
		RubikColor_T::BLUE, RubikColor_T::YELLOW, RubikColor_T::YELLOW, RubikColor_T::BLUE, RubikColor_T::WHITE,RubikColor_T::GREEN,RubikColor_T::YELLOW,RubikColor_T::	YELLOW,
		RubikColor_T::RED, RubikColor_T::ORANGE, RubikColor_T::WHITE, RubikColor_T::RED, RubikColor_T::WHITE, RubikColor_T::ORANGE, RubikColor_T::WHITE,RubikColor_T::ORANGE,
		RubikColor_T::ORANGE, RubikColor_T::YELLOW, RubikColor_T::WHITE, RubikColor_T::ORANGE, RubikColor_T::WHITE, RubikColor_T::YELLOW, RubikColor_T::GREEN, RubikColor_T::YELLOW,
		RubikColor_T::RED, RubikColor_T::RED, RubikColor_T::WHITE, RubikColor_T::GREEN, RubikColor_T::ORANGE, RubikColor_T::RED, RubikColor_T::ORANGE, RubikColor_T::RED,
		RubikColor_T::GREEN, RubikColor_T::BLUE, RubikColor_T::BLUE, RubikColor_T::GREEN, RubikColor_T::RED, RubikColor_T::WHITE, RubikColor_T::GREEN, RubikColor_T::BLUE
	};
	//Cube cube(solvedCube_T);
	
	*/
	//cube.doMove(12);
	//std::cout << "Index: " << cube.getEdgeIndex(0) << " index: " << cube.getEdgeIndex(1) << "\n";
	/*
	//Cube cube(solvedCube_T);
	const unsigned char * a = cube.getAvailableMoves(255);
	for (int i = 0; i < 18; i++)
	{
		Cube newCube(cube);
		newCube.doMove(a[i]);
		if (newCube.getCornerIndex() > 88179840) {
			std::cout << newCube.getCornerIndex() << "\n";
		}
	}
	*/

	/*
	unsigned char * table;
	table = NEW_CORNER_TABLE;

	GenerateCornerTable(table);


	FILE * file = fopen("output.txt", "w+");
	int bytes_written = fwrite(table, sizeof(unsigned char), CORNER_TABLE_SIZE, file);
	fclose(file);
	free(table);

	*/
	
	unsigned char * edge1_table;
	edge1_table = NEW_EGDE_TABLE;
	unsigned char * edge2_table;
	edge2_table = NEW_EGDE_TABLE;

	unsigned char * corner_table;
	corner_table = NEW_CORNER_TABLE;
	
	/*
	FILE * file = fopen("edge1_table.txt", "r+");
	int bytes_read = fread(edge1_table, sizeof(unsigned char), EDGE_TABLE_SIZE, file);
	fclose(file);
	file = fopen("edge2_table.txt", "r+");
	bytes_read = fread(edge2_table, sizeof(unsigned char), EDGE_TABLE_SIZE, file);
	fclose(file);
	file = fopen("corner_table.txt", "r+");
	bytes_read = fread(corner_table, sizeof(unsigned char), CORNER_TABLE_SIZE, file);
	fclose(file);




	Cube cube(solvedCube_T);

	cube.doMove(16);
	cube.doMove(10);
	cube.doMove(14);
	cube.doMove(17);
	cube.doMove(7);
	cube.doMove(17);
	cube.doMove(6);
	cube.doMove(5);
	cube.doMove(16);
	cube.doMove(5);
	cube.doMove(1);
	cube.doMove(17);
	cube.doMove(8);
	cube.doMove(12);
	cube.doMove(8);
	cube.doMove(16);
	cube.doMove(5);
	cube.doMove(2);
	cube.doMove(10);
	cube.doMove(16);
	cube.doMove(3);
	cube.doMove(9);
	cube.doMove(17);
	cube.doMove(12);
	cube.doMove(10);


	int	heuristic = corner_table[cube.getCornerIndex()];
	int temp = edge1_table[cube.getEdgeIndex(0)];
	if (heuristic < temp) heuristic = temp;
	temp = edge2_table[cube.getEdgeIndex(1)];
	if (heuristic < temp) heuristic = temp;
	std::cout << "Heuristic: " << heuristic << "\n";

	
	Solver solver(edge1_table, edge2_table, corner_table);
	unsigned char * solution = solver.SolveCube(cube);

	if (solution != nullptr) {
		for (int i = 0; i < 32; i++) {
			if (solution[i] != 255) {
				std::cout << unsigned(solution[i]) << " ";
			}
		}
	}
	
	
	*/

	/*
	int index1 = 0, index2 = 0;

	for (int i = 0; i < EDGE_TABLE_SIZE; i++) {
		if (edge1_table[i] != 255) index1++;
		if (edge2_table[i] != 255) index2++;
	}
	std::cout << "Edge table Index1: " << index1 << "	Index2: " << index2 << "\n";

	index1 = 0;

	for (int i = 0; i < CORNER_TABLE_SIZE; i++) {
		if (corner_table[i] != 255) index1++;
	}
	std::cout << "Corner table Index: " << index1 << "\n";

	free(edge1_table);
	free(edge2_table);
	free(corner_table);
	*/
	/*
	GenerateTables(corner_table, CORNER_TABLE_SIZE, 0);
	FILE * file = fopen("corner_table.txt", "w+");
	int bytes_written = fwrite(corner_table, sizeof(unsigned char), CORNER_TABLE_SIZE, file);
	fclose(file);
	free(corner_table);
	
	*/
	GenerateTables(edge1_table, EDGE_TABLE_SIZE, 1);
	FILE * file = fopen("edge1_table.txt", "w+");
	int bytes_written = fwrite(edge1_table, sizeof(unsigned char), EDGE_TABLE_SIZE, file);
	fclose(file);
	free(edge1_table);
	
	GenerateTables(edge2_table, EDGE_TABLE_SIZE, 2);
	file = fopen("edge2_table.txt", "w+");
	bytes_written = fwrite(edge2_table, sizeof(unsigned char), EDGE_TABLE_SIZE, file);
	fclose(file);
	free(edge2_table);

	std::cout << "Done";
	
	/*file = fopen("outputCorner.txt", "w+");
	bytes_written = fwrite(cornerTable, sizeof(unsigned char), CORNER_TABLE_SIZE, file);
	fclose(file);
	free(cornerTable);*/
	
	/*
	for (int move = 0; move < 18; move++) {

		std::cout << "Move: " << move << "\n";
		Cube cube(solvedCube_T);
		cube.doMove(move);
		//std::cout << "EdgeIndex 1: " << cube.getEdgeIndex(0) << "EdgeIndex 2: " << cube.getEdgeIndex(1) << "\n";

		for (int i = 0; i < 8; i++) {
			std::cout << "Pos: " << unsigned(cube.getCornerPos(i)) << "\n"; //<< " : " << unsigned(cube.cube[cube.edgeIndexs[i][0]]) << "\n";
																		  //std::cout << "Pos: " << unsigned(cube.getEdgePos(i)); //<< " : " << unsigned(cube.cube[cube.edgeIndexs[i][1]]) << "\n";
																		  //	std::cout << "Pos: " << unsigned(cube.cornerIndexs[i][2]) << " : " << unsigned(cube.cube[cube.cornerIndexs[i][2]]) << "\n";

		}

		std::cout << "\n \n";
	}
	*/

	/*
	for (int move = 0; move < 18; move++) {

		std::cout << "Move: " << move << "\n";
		Cube cube(solvedCube_T);
		cube.doMove(move);
		//std::cout << "EdgeIndex 1: " << cube.getEdgeIndex(0) << "EdgeIndex 2: " << cube.getEdgeIndex(1) << "\n";

		for (int i = 0; i < 12; i++) {
			std::cout << "Pos: " << unsigned(cube.getEdgePos(i)) << "\n"; //<< " : " << unsigned(cube.cube[cube.edgeIndexs[i][0]]) << "\n";
																		  //std::cout << "Pos: " << unsigned(cube.getEdgePos(i)); //<< " : " << unsigned(cube.cube[cube.edgeIndexs[i][1]]) << "\n";
																		  //	std::cout << "Pos: " << unsigned(cube.cornerIndexs[i][2]) << " : " << unsigned(cube.cube[cube.cornerIndexs[i][2]]) << "\n";

		}

		std::cout << "\n \n";
	}
	*/
	
}

