#include <stdlib.h>
#include <stdio.h>
#include "Maze.h"

// //struct constructors and destructors
// node * new_Node ()

//Decide which neighbouring cell has the lowest distance value (3)
int check_lowest_cell(struct wall_directions *cell_wall)
{
    if ((cell_wall->west_wall & NORTH_WALL) == 0)                                  //Is the cell to the North separated by a wall?


    if ((cell_wall->east_wall & EAST_WALL) == 0)                                   //Is the cell to the East separated by a wall?


    if ((cell_wall->south_wall & SOUTH_WALL) == 0)                                  //Is the cell to the South separated by a wall?


    if ((cell_wall->west_wall & WEST_WALL) == 0)                                   //Is the cell to the West separated by a wall?

}

//Move to the neighbouring cell with the lowest distance value (4)
int move_lowest_cell(struct maze_storage *cell_data)
{
    cell_data->maze_value[1][0];
}

//Update the wall map (1)
int update_map()
{

}

//Flood the maze with new distance values (2)
int flood_maze()
{

}

int main()
{
    struct wall_directions *cell_wall;
    struct maze_storage *cell_data;

    check_lowest_cell(&cell_wall);

    move_lowest_cell(&cell_data);
    


}