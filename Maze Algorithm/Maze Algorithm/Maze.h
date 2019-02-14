#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define TRUE  1
#define FALSE 0

#define SIZE  16


// Directions
/*   N(0)
W(3)  E(1)
S(2)  */
#define WALL_NO  0
#define WALL_ENS 1
#define WALL_ENW 2
#define WALL_EN  3
#define WALL_ESW 4
#define WALL_ES  5
#define WALL_EW  6
#define WALL_NSW 7
#define WALL_NS  8
#define WALL_NW  9
#define WALL_SW  10

// typedef struct node
// {
//     /* data field */
//     int floodval;
//     int row;
//     int column;
//     int visited;

//     /* pointers to neighbours */
//     struct node * left;

// } node;

// struct cell_bit
// {
//     bool West_bit;
//     bool South_bit;
//     bool East_bit;
//     bool North_bit;

// } neighbour[4] ;

// struct maze_cell
// {
//     int 
// };

int temp_cell_data [6][8] = 
{
	{5, 4, 3, 2, 2, 3, 4, 5},
	{4, 3, 2, 1, 1, 2, 3, 4},
	{3, 2, 1, 0, 0, 1, 2, 3},
	{3, 2, 1, 0, 0, 1, 2, 3},
	{4, 3, 2, 1, 1, 2, 3, 4}, 
	{5, 4, 3, 2, 2, 3, 4, 5}

};

// struct wall_directions
// {
// 	bool west_wall[6][8];
// 	bool south_wall[6][8];
// 	bool east_wall[6][8];
// 	bool north_wall[6][8];
// };

struct maze_storage
{
	int maze_value[6][8];
	int temp_node_N;
	int temp_node_E;
	int temp_node_S;
	int temp_node_W;
	bool west_wall[6][8];
	bool south_wall[6][8];
	bool east_wall[6][8];
	bool north_wall[6][8];
	int status_wall;
};

struct node
{
	int current_posX;
	int current_posY;
	int lowest_neigh;
};
