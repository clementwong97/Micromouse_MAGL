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
#define NORTH_WALL 0
#define EAST_WALL  1
#define SOUTH_WALL 2
#define WEST_WALL  3

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
	bool west_wall[6][8];
	bool south_wall[6][8];
	bool east_wall[6][8];
	bool north_wall[6][8];
};
