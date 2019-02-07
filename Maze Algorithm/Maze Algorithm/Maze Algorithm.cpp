// Maze Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Maze.h"

// //struct constructors and destructors
// node * new_Node ()

// //Decide which neighbouring cell has the lowest distance value (3)
// void check_lowest_cell(struct wall_directions *cell_wall)
// {
// 	//test value
// 	cell_wall->west_wall = 0;

// 	if (cell_wall->west_wall == 1)                                  //Is the cell to the North separated by a wall?
// 	{
// 		printf("North Wall \n");
// 	}
// 	else
// 	{
// 		printf("North Path Clear");
// 	}

// 	if (cell_wall->east_wall == 1)                                   //Is the cell to the East separated by a wall?
// 	{
// 		printf("East Wall \n");
// 	}
// 	else
// 	{
// 		printf("East Path Clear");
// 	}

// 	if (cell_wall->south_wall == 1)                                  //Is the cell to the South separated by a wall?
// 	{
// 		printf("South Wall \n");
// 	}
// 	else
// 	{
// 		printf("South Path Clear");
// 	}

// 	if (cell_wall->west_wall == 1)                                   //Is the cell to the West separated by a wall?
// 	{
// 		printf("West Wall \n");
// 	}
// 	else
// 	{
// 		printf("West Path Clear");
// 	}
// }

// //Move to the neighbouring cell with the lowest distance value (4)
// int move_lowest_cell(struct maze_storage *cell_data)
// {
//     cell_data->maze_value[1][0];
// }

// //Update the wall map (1)
// int update_map()
// {

// }

// //Flood the maze with new distance values (2)
// int flood_maze()
// {

// }

// void store_maze_data(struct maze_storage *cell_data)
// {

// }

void check_walls(struct maze_storage *wall)
{
	printf("Debug checkwall east wall: %d\n", wall->east_wall[0][0]);
	printf("Debug north wall: %d\n", wall->north_wall[0][0]);
	printf("Debug south wall: %d\n", wall->south_wall[0][0]);
	printf("Debug west wall: %d\n", wall->west_wall[0][0]);

	if (!(wall->north_wall[0][0]))                                  //Is the cell to the North separated by a wall?
	{
		printf("North Path Clear\n");
	}
	else
	{
		printf("North Wall \n");
	}

	if (!(wall->east_wall[0][0]))                                   //Is the cell to the East separated by a wall?
	{
		printf("East Path Clear\n");
	}
	else
	{
		printf("East Wall \n");
	}

	if (!(wall->south_wall[0][0]))                                  //Is the cell to the South separated by a wall?
	{
		printf("South Path Clear\n");
	}
	else
	{
		printf("South Wall \n");
	}

	if (!(wall->west_wall[0][0]))                                   //Is the cell to the West separated by a wall?
	{
		printf("West Path Clear\n");
	}
	else
	{
		printf("West Wall \n");
	}
}

void check_sensors(struct maze_storage *wall_sensors)
{
	//sample sensors values, when at (0,0)
	wall_sensors->east_wall[0][0] = false;
	wall_sensors->north_wall[0][0] = true;
	wall_sensors->south_wall[0][0] = false;
	wall_sensors->west_wall[0][0] = false;

	printf("Debug Sensors east wall: %d\n", wall_sensors->east_wall[0][0]);
	printf("Debug north wall: %d\n", wall_sensors->north_wall[0][0]);
	printf("Debug south wall: %d\n", wall_sensors->south_wall[0][0]);
	printf("Debug west wall: %d\n", wall_sensors->west_wall[0][0]);
}

void store_maze_data(struct maze_storage *data)
{
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			data->maze_value[y][x] = temp_cell_data[y][x];
		}
	}

	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			printf("%d ", data->maze_value[x][y]);
		}
		printf("\n");
	}

}

void move_lowest_cell(struct maze_storage *lowest)
{

}

int main(void)
{
	struct maze_storage cell_data;

	printf("Check Main \n");

	//function to store the initial maze data
	store_maze_data(&cell_data);

	//function to check the sensor values
	check_sensors(&cell_data);

	//function to check the cell paths
	check_walls(&cell_data);

	//function to move the mouse to the lowest distance value
	move_lowest_cell(&cell_data);

	


	return 0;
}
