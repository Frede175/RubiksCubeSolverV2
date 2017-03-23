#pragma once
#ifndef Tables_H
#define Tables_H

#include "Cube.h"
#include <queue>

#define CORNER_TABLE_SIZE 88179840
#define EDGE_TABLE_SIZE 42577920


#define NEW_CORNER_TABLE new unsigned char[CORNER_TABLE_SIZE]
#define NEW_EGDE_TABLE new unsigned char[EDGE_TABLE_SIZE]

typedef struct {
	Cube cube;
	unsigned char lastMove;
	unsigned char depth;
} sdata;
/*
namespace Tables {
	unsigned char cornerTable[CORNER_TABLE_SIZE] = {};
	unsigned char edge1Table[EDGE_TABLE_SIZE] = {};
	unsigned charedge2Table[EDGE_TABLE_SIZE] = {};
}*/



bool GenerateCornerTable(unsigned char * table);
bool GenerateEdgeTable();


#endif // !Tables_H
