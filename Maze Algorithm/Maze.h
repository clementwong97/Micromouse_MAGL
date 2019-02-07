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
#define EAST  1
#define SOUTH 2
#define WEST  3

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

struct maze_storage
{
    int maze_value[6][8];

} cell_data, wall_data;

struct maze_storage cell_data = 
{
    {
    
        {5, 4, 3, 2, 2, 3, 4, 5},
        {4, 3, 2, 1, 1, 2, 3, 4},
        {3, 2, 1, 0, 0, 1, 2, 3},
        {3, 2, 1, 0, 0, 1, 2, 3},
        {4, 3, 2, 1, 1, 2, 3, 4}, 
        {5, 4, 3, 2, 2, 3, 4, 5}
    
    }
};

struct wall_directions
{
    bool west_wall;
    bool south_wall;
    bool east_wall;
    bool north_wall;
};
