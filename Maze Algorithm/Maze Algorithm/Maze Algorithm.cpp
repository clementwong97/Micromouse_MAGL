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

void check_walls(struct maze_storage *wall, struct node *n_walls)
{
	printf("Check Wall Location......\n\n");
	int check_x = n_walls->current_posX;
	int check_y = n_walls->current_posY;

	// printf("Wall Data E: %d\n", wall->east_wall[check_y][check_x]);
	// printf("Wall Data N: %d\n", wall->north_wall[check_y][check_x]);
	// printf("Wall Data S: %d\n", wall->south_wall[check_y][check_x]);
	// printf("Wall Data W: %d\n", wall->west_wall[check_y][check_x]);

	if (!(wall->north_wall[check_y][check_x]))                                  //Is the cell to the North separated by a wall?
	{
		printf("North Path Clear\n");
	}
	else
	{
		printf("North Wall \n");
	}

	if (!(wall->east_wall[check_y][check_x]))                                   //Is the cell to the East separated by a wall?
	{
		printf("East Path Clear\n");
	}
	else
	{
		printf("East Wall \n");
	}

	if (!(wall->south_wall[check_y][check_x]))                                  //Is the cell to the South separated by a wall?
	{
		printf("South Path Clear\n");
	}
	else
	{
		printf("South Wall \n");
	}

	if (!(wall->west_wall[check_y][check_x]))                                   //Is the cell to the West separated by a wall?
	{
		printf("West Path Clear\n\n");
	}
	else
	{
		printf("West Wall \n\n");
	}
}

void check_sensors(struct maze_storage *wall_sensors, struct node *n_sensors)
{
	printf("Check Sensors Reading.......\n\n");

	int n_x = n_sensors->current_posX;
	int n_y = n_sensors->current_posY;

	printf("current_posX: %d\n", n_sensors->current_posX);
	printf("current_posY: %d\n\n", n_sensors->current_posY);

	printf("Where is the wall?  (E N S W) (1 means wall present, 0 means clear path), for example input the wall status like: 0 1 1 1 \n");
	scanf("%d %d %d %d", &wall_sensors->east_wall[n_y][n_x], &wall_sensors->north_wall[n_y][n_x], &wall_sensors->south_wall[n_y][n_x], &wall_sensors->west_wall[n_y][n_x]);

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

void fix_maze_dimension(struct maze_storage *lowest, struct node *n_lowest)
{
	printf("Debug move lowest cell...........\n");
	int x_low, x_high, y_low, y_high;
	lowest->temp_node_N = 10; 
	lowest->temp_node_E = 10;
	lowest->temp_node_S = 10;
	lowest->temp_node_W = 10;
	int current_x, current_y;

	current_x = n_lowest->current_posX;
	current_y = n_lowest->current_posY;

	int current_value = lowest->maze_value[current_y][current_x];

	x_low = current_x - 1;			//left side of node
	x_high = current_x + 1;			//right side of node
	y_low = current_y - 1;			//above of node
	y_high = current_y + 1;			//below of node

	//north cell
	if (y_low >= 0)
	{
		if ((lowest->maze_value[y_low][current_x]) < current_value)
		{	
			lowest->temp_node_N = lowest->maze_value[y_low][current_x];
		}
	}
	//east cell
	if (x_high <= 7)
	{
		if ((lowest->maze_value[current_y][x_high]) < current_value)
		{	
			lowest->temp_node_E = lowest->maze_value[current_y][x_high];
		}
	}
	//south cell
	if (y_high <= 5)
	{
		if ((lowest->maze_value[y_high][current_x]) < current_value)
		{	
			lowest->temp_node_S = lowest->maze_value[y_low][current_x];
		}
	}
	//west cell
	if (x_low >= 0)
	{
		if ((lowest->maze_value[current_y][x_low]) < current_value)
		{	
			lowest->temp_node_W = lowest->maze_value[current_y][x_low];
		}
	}
}

void check_wall_and_value(struct maze_storage *check, struct node *n_check)
{
	printf("Check wall and value.........\n");
	fix_maze_dimension(check, n_check);

	switch (check->status_wall)
	{
		case WALL_NO:
		{
			//compare and find the smallest of them all
			if (check->temp_node_E < check->temp_node_N)
			{
				if (check->temp_node_E < check->temp_node_W)
				{
					if (check->temp_node_E < check->temp_node_S)
					{
						//move to East Cell
						printf("Move to East Cell. \n");
					}
				}
			}
			if (check->temp_node_W < check->temp_node_N)
			{
				if (check->temp_node_W <= check->temp_node_E)
				{
					if (check->temp_node_W <= check->temp_node_S)
					{
						//move to West Cell
						printf("Move to West Cell. \n");
					}
				}
			}
			if (check->temp_node_S < check->temp_node_N)
			{
				if (check->temp_node_S < check->temp_node_W)
				{
					if (check->temp_node_S < check->temp_node_E)
					{
						//move to South Cell
						printf("Move to South Cell. \n");
					}
				}
			}
			if (check->temp_node_N <= check->temp_node_E)
			{
				if (check->temp_node_N <= check->temp_node_W)
				{
					if (check->temp_node_N <= check->temp_node_S)
					{
						//move to North Cell
						printf("Move to North Cell. \n");
					}
				}
			}
		}
		case WALL_ENS:
		{
			if (check->temp_node_E < check->temp_node_N)
			{
				if (check->temp_node_E < check->temp_node_S)
				{
					//move to East Cell
					printf("Move to East Cell. \n");
				}
			}
			if (check->temp_node_S < check->temp_node_N)
			{
				if (check->temp_node_S < check->temp_node_E)
				{
					//move to South Cell
					printf("Move to South Cell. \n");
				}
			}
			if (check->temp_node_N <= check->temp_node_E)
			{
				if (check->temp_node_N <= check->temp_node_S)
				{
					//move to North Cell
					printf("Move to North Cell. \n");
				}
			}
		}
		case WALL_ENW:
		{
			if (check->temp_node_E < check->temp_node_N)
			{
				if (check->temp_node_E < check->temp_node_W)
				{
					//move to East Cell
					printf("Move to East Cell. \n");
				}
			}
			if (check->temp_node_W < check->temp_node_N)
			{
				if (check->temp_node_W < check->temp_node_E)
				{
					//move to West Cell
					printf("Move to West Cell. \n");
				}
			}
			if (check->temp_node_N <= check->temp_node_E)
			{
				if (check->temp_node_N <= check->temp_node_W)
				{
					//move to North Cell
					printf("Move to North Cell. \n");
				}
			}
		}
		case WALL_EN:
		{
			if (check->temp_node_E < check->temp_node_N)
			{
				//move to East Cell
				printf("Move to East Cell. \n");
			
			}
			if (check->temp_node_N <= check->temp_node_E)
			{
				//move to North Cell
				printf("Move to North Cell. \n");
			}
		}
		case WALL_ESW:
		{
			if (check->temp_node_E <= check->temp_node_S)
			{
				if (check->temp_node_E <= check->temp_node_W)
				{
					//move to East Cell
					printf("Move to East Cell. \n");
				}
			}
			if (check->temp_node_W < check->temp_node_S)
			{
				if (check->temp_node_W < check->temp_node_E)
				{
					//move to West Cell
					printf("Move to West Cell. \n");
				}
			}
			if (check->temp_node_S < check->temp_node_E)
			{
				if (check->temp_node_S < check->temp_node_W)
				{
					//move to South Cell
					printf("Move to South Cell. \n");
				}
			}
		}
		case WALL_ES:
		{
			if (check->temp_node_E <= check->temp_node_S)
			{
				//move to East Cell
				printf("Move to East Cell. \n");
			
			}
			if (check->temp_node_S < check->temp_node_E)
			{
				//move to South Cell
				printf("Move to South Cell. \n");
			}
		}
		case WALL_EW:
		{
			if (check->temp_node_E <= check->temp_node_W)
			{
				//move to East Cell
				printf("Move to East Cell. \n");
			
			}
			if (check->temp_node_W < check->temp_node_E)
			{
				//move to West Cell
				printf("Move to West Cell. \n");
			}
		}
		case WALL_NSW:
		{
			if (check->temp_node_N <= check->temp_node_S)
			{
				if (check->temp_node_N <= check->temp_node_W)
				{
					//move to North Cell
					printf("Move to North Cell. \n");
				}
			}
			if (check->temp_node_W < check->temp_node_S)
			{
				if (check->temp_node_W < check->temp_node_N)
				{
					//move to South Cell
					printf("Move to West Cell. \n");
				}
			}
			if (check->temp_node_S < check->temp_node_N)
			{
				if (check->temp_node_S < check->temp_node_W)
				{
					//move to North Cell
					printf("Move to South Cell. \n");
				}
			}
		}
		case WALL_NS:
		{
			if (check->temp_node_N <= check->temp_node_S)
			{
				//move to North Cell
				printf("Move to North Cell. \n");
			
			}
			if (check->temp_node_S < check->temp_node_N)
			{
				//move to South Cell
				printf("Move to South Cell. \n");
			}
		}
		case WALL_NW:
		{
			if (check->temp_node_N <= check->temp_node_W)
			{
				//move to North Cell
				printf("Move to North Cell. \n");
			
			}
			if (check->temp_node_W < check->temp_node_N)
			{
				//move to West Cell
				printf("Move to West Cell. \n");
			}
		}
		case WALL_SW:
		{
			if (check->temp_node_S < check->temp_node_W)
			{
				//move to South Cell
				printf("Move to South Cell. \n");
			
			}
			if (check->temp_node_W <= check->temp_node_S)
			{
				//move to West Cell
				printf("Move to West Cell. \n");
			}
		}

	}
}

void track_position(struct maze_storage *track, struct node *n_track)
{
	//eg. current position at [5][0]
	printf("Enter the current position of mouse [y][x] For example: 5 0 : ");
	scanf("%d %d", &n_track->current_posY, &n_track->current_posX);
	printf("Current position is at [%d][%d]\n", n_track->current_posY, n_track->current_posX);
	// n_track->current_posX = 0;
	// n_track->current_posY = 5;

}

void next_move(struct maze_storage *next, struct node *n_next)
{
	printf("Next_move................\n\n");
	int current_x = n_next->current_posX;
	int current_y = n_next->current_posY;
	//check which is the best cell to move to
	//if no walls around the cell
	if (!(next->east_wall[current_y][current_x])) 
	{
		if (!(next->north_wall[current_y][current_x]))
		{
			if (!(next->south_wall[current_y][current_x]))
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//All Clear
					//Check where is the lowest
					next->status_wall = WALL_NO;
					check_wall_and_value(next, n_next);
				}
				else
				{
					//if clear on the E, N, S
					//Check East, North, South cell values
					next->status_wall = WALL_ENS;
					check_wall_and_value(next, n_next);
				}		
			}
			else
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the E, N, W
					//Check East, north, west cell values
					next->status_wall = WALL_ENW;
					check_wall_and_value(next, n_next);
				}
				else
				{
					//if clear on the E, N
					//Check East, North cell values
					next->status_wall = WALL_EN;
					check_wall_and_value(next, n_next);
				}
			}	
		}
		else
		{
			if (!(next->south_wall[current_y][current_x]))
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the E, S, W
					//Check east, south, west cell values
					next->status_wall = WALL_ESW;
					check_wall_and_value(next, n_next);
				}
				else
				{
					//if clear on the E, S
					//Check East, South cell values
					next->status_wall = WALL_ES;
					check_wall_and_value(next, n_next);
				}	
			}
			else
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the E, W
					//Check East, West cell values
					next->status_wall = WALL_EW;
					check_wall_and_value(next, n_next);
				}
				else
				{
					//clear on E
					//Move to East
					printf("Robot move to the East. \n");
				}
				
			}
		}
	}
	else if (next->east_wall[current_y][current_x])
	{
		if (!(next->north_wall[current_y][current_x]))
		{
			if (!(next->south_wall[current_y][current_x]))
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the N, S, W
					//Check north, south, west cell values
					next->status_wall = WALL_NSW;
					check_wall_and_value(next, n_next);
				}
				else
				{
					//if clear on the N, S
					//Check North, South cell values
					next->status_wall = WALL_NS;
					check_wall_and_value(next, n_next);
				}		
			}
			else
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the N, W
					//Check north, west cell values
					next->status_wall = WALL_NW;
					check_wall_and_value(next, n_next);
				}
				else
				{
					//if clear on the N
					//Move to the North
					printf("Robot move to the North. \n");
				}
			}	
		}
		else
		{
			if (!(next->south_wall[current_y][current_x]))
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the S, W
					//Check south, west cell values
					next->status_wall = WALL_SW;
					check_wall_and_value(next, n_next);
				}
				else
				{
					//if clear on the S
					//Move to the South
					printf("Robot move to the South. \n");
				}	
			}
			else
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the W
					//move to west
					printf("Robot move to the West. \n");
				}
			}
		}
		
	}
	
}

int main(void)
{
	struct maze_storage cell_data;
	struct node node_data;

	printf("Check Main \n");

	//function to track the real time coordinates of the node
	track_position(&cell_data, &node_data);

	//function to store the initial maze data
	store_maze_data(&cell_data);

	//function to convert sensors reading to algorithm
	check_sensors(&cell_data, &node_data);

	//function to check the cell paths
	check_walls(&cell_data, &node_data);

	// //function to move the mouse to the lowest distance value
	// move_lowest_cell(&cell_data, &node_data);

	//function to compare the wall status and lowest distance value
	next_move(&cell_data, &node_data);


	return 0;
}
