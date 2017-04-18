#pragma once
#ifndef Tables_H
#define Tables_H

#include "Cube.h"
#include <queue>

#define CORNER_TABLE_SIZE 88179840
#define EDGE_TABLE_SIZE 42577920


#define NEW_CORNER_TABLE new unsigned char[CORNER_TABLE_SIZE]()
#define NEW_EGDE_TABLE new unsigned char[EDGE_TABLE_SIZE]()


#define	PHASE1_CORNER_SIZE 2187
#define	PHASE1_EDGE_SIZE 2048
#define PHASE1_UDSLICE_SIZE 495
#define PHASE1_FLIPUDSLICE_SIZE 1013760

#define PHASE2_CORNER_SIZE 40320
#define	PHASE2_EDGE_SIZE 40320
#define PHASE2_UDSLICE_SIZE 24

#define NEW_PHASE1_CORNER_TABLE new unsigned char[PHASE1_CORNER_SIZE]()
#define NEW_PHASE1_EDGE_TABLE new unsigned char[PHASE1_EDGE_SIZE]()
#define NEW_PHASE1_UDSLICE_TABLE new unsigned char[PHASE1_UDSLICE_SIZE]()
#define NEW_PHASE1_FLIPUDSLICE_TABLE new unsigned char[PHASE1_FLIPUDSLICE_SIZE]()
#define NEW_PHASE2_CORNER_TABLE new unsigned char[PHASE2_CORNER_SIZE]()
#define NEW_PHASE2_EDGE_TABLE new unsigned char[PHASE2_EDGE_SIZE]()
#define NEW_PHASE2_UDSLICE_TABLE new unsigned char[PHASE2_UDSLICE_SIZE]()


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
bool GenerateEdge2Table(unsigned char * table);
bool GenerateEdge1Table(unsigned char * table);

bool GenerateTables(unsigned char * table, int length, unsigned char tableID);

int GeneratePhase1CornerTable(unsigned char * table);
int GeneratePhase1EdgeTable(unsigned char * table);
int GeneratePhase1UDSliceTable(unsigned char * table);
int GeneratePhase1FlipUDSliceTable(unsigned char * table);
int GeneratePhase2CornerTable(unsigned char * table);
int GeneratePhase2EdgeTable(unsigned char * table);
int GeneratePhase2UDSliceTable(unsigned char * table);


void generateTables(unsigned char * phase1_corner_table, unsigned char * phase1_edge_table, unsigned char * phase1_UDSlice_table, unsigned char * phase1_FlipUDSlice_table, unsigned char * phase2_corner_table, unsigned char * phase2_edge_table, unsigned char * phase2_UDSlice_table);
void loadTables(unsigned char * phase1_corner_table, unsigned char * phase1_edge_table, unsigned char * phase1_UDSlice_table, unsigned char * phase1_FlipUDSlice_table, unsigned char * phase2_corner_table, unsigned char * phase2_edge_table, unsigned char * phase2_UDSlice_table);


int getIndex(Cube * cube, unsigned char tableID);
//bool GenerateEdgeTable(unsigned char * table1, unsigned char * table2);
//bool GenerateTable(unsigned char * edgeTable1, unsigned char * edgeTable2, unsigned char * cornerTable);

#endif // !Tables_H
