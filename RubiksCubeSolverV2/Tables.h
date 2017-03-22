#pragma once
#ifndef Tables_H
#define Tables_H

#include "Cube.h"

#define CORNER_TABLE_SIZE 44069760
#define EDGE_TABLE_SIZE 2560320

unsigned char cornerTable[CORNER_TABLE_SIZE];
unsigned char edgeTable[EDGE_TABLE_SIZE];

bool GenerateCornerTable();
bool GenerateEdgeTable();


#endif // !Tables_H
