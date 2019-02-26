// Maze Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Maze.h"


void backtrack_update(struct maze_storage *update, struct node *n_update, struct history *h_update);

void next_move_South(struct maze_storage *south, struct node *n_south)
{
	int south_x = n_south->current_posX;
	int south_y = n_south->current_posY;
	//if current cell isn't more than or equal to minimum neighbour + 1
	if (south->maze_value[south_y][south_x] <= (south->temp_node_S + 1))
	{
		south->maze_value[south_y][south_x] = south->temp_node_S + 1;
		//backtrack_update(south, n_south, n_history);
	}
	//move to South Cell
	printf("Move to South Cell. \n");
	n_south->current_posY++;
	south->flag[n_south->current_posY][n_south->current_posX] = 1;
	printf("New Location: [%d][%d]\n", n_south->current_posY, n_south->current_posX);
}

void next_move_West(struct maze_storage *west, struct node *n_west)
{
	int west_x = n_west->current_posX;
	int west_y = n_west->current_posY;
	//if current cell isn't more than or equal to minimum neighbour + 1
	if (west->maze_value[west_y][west_x] <= (west->temp_node_W + 1))
	{
		west->maze_value[west_y][west_x] = west->temp_node_W + 1;
		//backtrack_update(west, n_west, n_history);
	}
	//move to West Cell
	printf("Move to West Cell. \n");
	n_west->current_posX--;
	west->flag[n_west->current_posY][n_west->current_posX] = 1;
	printf("New Location: [%d][%d]\n", n_west->current_posY, n_west->current_posX);
}

void next_move_North(struct maze_storage *north, struct node *n_north)
{
	int north_x = n_north->current_posX;
	int north_y = n_north->current_posY;
	//if current cell isn't more than or equal to minimum neighbour + 1
	if (north->maze_value[north_y][north_x] <= (north->temp_node_W + 1))
	{
		north->maze_value[north_y][north_x] = north->temp_node_W + 1;
		//backtrack_update(north, n_north, n_history);
	}
	//move to North Cell
	printf("Move to North Cell. \n");
	n_north->current_posY--;
	north->flag[n_north->current_posY][n_north->current_posX] = 1;
	printf("New Location: [%d][%d]\n", n_north->current_posY, n_north->current_posX);
}

void next_move_East(struct maze_storage *east, struct node *n_east)
{
	int east_x = n_east->current_posX;
	int east_y = n_east->current_posY;
	//if current cell isn't more than or equal to minimum neighbour + 1
	if (east->maze_value[east_y][east_x] <= (east->temp_node_W + 1))
	{
		east->maze_value[east_y][east_x] = east->temp_node_W + 1;
		//backtrack_update(east, n_east, n_history);
	}
	//move to East Cell
	printf("Move to East Cell. \n");
	n_east->current_posX++;
	east->flag[n_east->current_posY][n_east->current_posX] = 1;
	printf("New Location: [%d][%d]\n", n_east->current_posY, n_east->current_posX);
}

void next_move_No(struct maze_storage *no, struct node *n_no)
{
	int no_x = n_no->current_posX;
	int no_y = n_no->current_posY;
	//check all cells values 
	if (no->temp_node_E < no->temp_node_N)
	{
		if (no->temp_node_E <= no->temp_node_W)
		{
			if (no->temp_node_E <= no->temp_node_S)
			{
				//if current cell isn't more than or equal to minimum neighbour + 1
				if (no->maze_value[no_y][no_x] <= (no->temp_node_E + 1))
				{
					no->maze_value[no_y][no_x] = no->temp_node_E + 1;
					//backtrack_update(check, n_check, n_history);
				}
				//move to East Cell
				printf("Move to East Cell. \n");
				n_no->current_posX++;
				no->flag[n_no->current_posY][n_no->current_posX] = 1;
				printf("New Location: [%d][%d]\n", n_no->current_posY, n_no->current_posX);
			}
		}
	}
	if (no->temp_node_W < no->temp_node_N)
	{
		if (no->temp_node_W < no->temp_node_E)
		{
			if (no->temp_node_W < no->temp_node_S)
			{
				//if current cell isn't more than or equal to minimum neighbour + 1
				if (no->maze_value[no_y][no_x] <= (no->temp_node_W + 1))
				{
					no->maze_value[no_y][no_x] = no->temp_node_W + 1;
					//backtrack_update(check, n_check, n_history);
				}
				//move to West Cell
				printf("Move to West Cell. \n");
				n_no->current_posX--;
				no->flag[n_no->current_posY][n_no->current_posX] = 1;
				printf("New Location: [%d][%d]\n", n_no->current_posY, n_no->current_posX);
			}
		}
	}
	if (no->temp_node_S < no->temp_node_N)
	{
		if (no->temp_node_S <= no->temp_node_W)
		{
			if (no->temp_node_S < no->temp_node_E)
			{
				//if current cell isn't more than or equal to minimum neighbour + 1
				if (no->maze_value[no_y][no_x] <= (no->temp_node_S + 1))
				{
					no->maze_value[no_y][no_x] = no->temp_node_S + 1;
					//backtrack_update(no, n_no, n_history);
				}
				//move to South Cell
				printf("Move to South Cell. \n");
				n_no->current_posY++;
				no->flag[n_no->current_posY][n_no->current_posX] = 1;
				printf("New Location: [%d][%d]\n", n_no->current_posY, n_no->current_posX);
			}
		}
	}
	if (no->temp_node_N <= no->temp_node_E)
	{
		if (no->temp_node_N <= no->temp_node_W)
		{
			if (no->temp_node_N <= no->temp_node_S)
			{
				//if current cell isn't more than or equal to minimum neighbour + 1
				if (no->maze_value[no_y][no_x] <= (no->temp_node_N + 1))
				{
					no->maze_value[no_y][no_x] = no->temp_node_N + 1;
					//backtrack_update(no, n_no, n_history);
				}
				//move to North Cell
				printf("Move to North Cell. \n");
				n_no->current_posY--;
				no->flag[n_no->current_posY][n_no->current_posX] = 1;
				printf("New Location: [%d][%d]\n", n_no->current_posY, n_no->current_posX);
			}
		}
	}
}

void next_move_ENS(struct maze_storage *ens, struct node *n_ens )
{
	int ens_x = n_ens->current_posX;
	int ens_y = n_ens->current_posY;

	if (ens->temp_node_E < ens->temp_node_N)
	{
		if (ens->temp_node_E <= ens->temp_node_S)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (ens->maze_value[ens_y][ens_x] <= (ens->temp_node_E + 1))
			{
				ens->maze_value[ens_y][ens_x] = ens->temp_node_E + 1;
				//backtrack_update(ens, n_ens, n_history);
			}
			//move to East Cell
			printf("Move to East Cell. \n");
			n_ens->current_posX++;
			ens->flag[n_ens->current_posY][n_ens->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_ens->current_posY, n_ens->current_posX);	
		}
	}
	else if (ens->temp_node_S < ens->temp_node_N)
	{
		if (ens->temp_node_S < ens->temp_node_E)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (ens->maze_value[ens_y][ens_x] <= (ens->temp_node_S + 1))
			{
				ens->maze_value[ens_y][ens_x] = ens->temp_node_S + 1;
				//backtrack_update(ens, n_ens, n_history);
			}
			//move to South Cell
			printf("Move to South Cell. \n");
			n_ens->current_posY++;
			ens->flag[n_ens->current_posY][n_ens->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_ens->current_posY, n_ens->current_posX);	
		}
	}
	else if (ens->temp_node_N <= ens->temp_node_E)
	{
		if (ens->temp_node_N <= ens->temp_node_S)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (ens->maze_value[ens_y][ens_x] <= (ens->temp_node_N + 1))
			{
				ens->maze_value[ens_y][ens_x] = ens->temp_node_N + 1;
				//backtrack_update(ens, n_ens, n_history);
			}
			//move to North Cell
			printf("Move to North Cell. \n");
			n_ens->current_posY--;
			ens->flag[n_ens->current_posY][n_ens->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_ens->current_posY, n_ens->current_posX);
		}
	}
}

void next_move_ENW(struct maze_storage *enw, struct node *n_enw)
{
	int enw_x = n_enw->current_posX;
	int enw_y = n_enw->current_posY;

	if (enw->temp_node_E < enw->temp_node_N)
	{
		if (enw->temp_node_E <= enw->temp_node_W)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (enw->maze_value[enw_y][enw_x] <= (enw->temp_node_E + 1))
			{
				enw->maze_value[enw_y][enw_x] = enw->temp_node_E + 1;
				//backtrack_update(enw, n_enw, n_history);
			}
			//move to East Cell
			printf("Move to East Cell. \n");
			n_enw->current_posX++;
			enw->flag[n_enw->current_posY][n_enw->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_enw->current_posY, n_enw->current_posX);
		}
	}
	if (enw->temp_node_W < enw->temp_node_N)
	{
		if (enw->temp_node_W < enw->temp_node_E)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (enw->maze_value[enw_y][enw_x] <= (enw->temp_node_W + 1))
			{
				enw->maze_value[enw_y][enw_x] = enw->temp_node_W + 1;
				//backtrack_update(enw, n_enw, n_history);
			}
			//move to West Cell
			printf("Move to West Cell. \n");
			n_enw->current_posX--;
			enw->flag[n_enw->current_posY][n_enw->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_enw->current_posY, n_enw->current_posX);
		}
	}
	if (enw->temp_node_N <= enw->temp_node_E)
	{
		if (enw->temp_node_N <= enw->temp_node_W)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (enw->maze_value[enw_y][enw_x] <= (enw->temp_node_N + 1))
			{
				enw->maze_value[enw_y][enw_x] = enw->temp_node_N + 1;
				//backtrack_update(enw, n_enw, n_history);
			}
			//move to North Cell
			printf("Move to North Cell. \n");
			n_enw->current_posY--;
			enw->flag[n_enw->current_posY][n_enw->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_enw->current_posY, n_enw->current_posX);
		}
	}
}

void next_move_EN(struct maze_storage *en, struct node *n_en)
{
	int en_x = n_en->current_posX;
	int en_y = n_en->current_posY;

	if (en->temp_node_N <= en->temp_node_E)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (en->maze_value[en_y][en_x] <= (en->temp_node_N + 1))
		{
			en->maze_value[en_y][en_x] = en->temp_node_N + 1;
			//backtrack_update(en, n_en, n_history);
		}
		//move to North Cell
		printf("Move to North Cell. \n");
		n_en->current_posY--;
		en->flag[n_en->current_posY][n_en->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_en->current_posY, n_en->current_posX);
	}
	if (en->temp_node_E < en->temp_node_N)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (en->maze_value[en_y][en_x] <= (en->temp_node_E + 1))
		{
			en->maze_value[en_y][en_x] = en->temp_node_E + 1;
			//backtrack_update(en, n_en, n_history);
		}	
		//move to East Cell
		printf("Move to East Cell. \n");
		n_en->current_posX++;
		en->flag[n_en->current_posY][n_en->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_en->current_posY, n_en->current_posX);		
	}
}

void next_move_ESW(struct maze_storage *esw, struct node *n_esw)
{
	int esw_x = n_esw->current_posX;
	int esw_y = n_esw->current_posY;

	if (esw->temp_node_E <= esw->temp_node_S)
	{
		if (esw->temp_node_E <= esw->temp_node_W)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (esw->maze_value[esw_y][esw_x] <= (esw->temp_node_E + 1))
			{
				esw->maze_value[esw_y][esw_x] = esw->temp_node_E + 1;
				//backtrack_update(esw, n_esw, n_history);
			}
			//move to East Cell
			printf("Move to East Cell. \n");
			n_esw->current_posX++;
			esw->flag[n_esw->current_posY][n_esw->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_esw->current_posY, n_esw->current_posX);	
		}
	}
	if (esw->temp_node_W < esw->temp_node_S)
	{
		if (esw->temp_node_W < esw->temp_node_E)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (esw->maze_value[esw_y][esw_x] <= (esw->temp_node_W + 1))
			{
				esw->maze_value[esw_y][esw_x] = esw->temp_node_W + 1;
				//backtrack_update(esw, n_esw, n_history);
			}
			//move to West Cell
			printf("Move to West Cell. \n");
			n_esw->current_posX--;
			esw->flag[n_esw->current_posY][n_esw->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_esw->current_posY, n_esw->current_posX);
		}
	}
	if (esw->temp_node_S < esw->temp_node_E)
	{
		if (esw->temp_node_S <= esw->temp_node_W)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (esw->maze_value[esw_y][esw_x] <= (esw->temp_node_S + 1))
			{
				esw->maze_value[esw_y][esw_x] = esw->temp_node_S + 1;
				//backtrack_update(esw, n_esw, n_history);
			}
			//move to South Cell
			printf("Move to South Cell. \n");
			n_esw->current_posY++;
			esw->flag[n_esw->current_posY][n_esw->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_esw->current_posY, n_esw->current_posX);
		}
	}
}

void next_move_ES(struct maze_storage *es, struct node *n_es)
{
	int es_x = n_es->current_posX;
	int es_y = n_es->current_posY;

	if (es->temp_node_E <= es->temp_node_S)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (es->maze_value[es_y][es_x] <= (es->temp_node_E + 1))
		{
			es->maze_value[es_y][es_x] = es->temp_node_E + 1;
			//backtrack_update(es, n_es, n_history);
		}
		//move to East Cell
		printf("Move to East Cell. \n");
		n_es->current_posX++;
		es->flag[n_es->current_posY][n_es->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_es->current_posY, n_es->current_posX);
	}
	if (es->temp_node_S < es->temp_node_E)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (es->maze_value[es_y][es_x] <= (es->temp_node_S + 1))
		{
			es->maze_value[es_y][es_x] = es->temp_node_S + 1;
			//backtrack_update(es, n_es, n_history);
		}
		//move to South Cell
		printf("Move to South Cell. \n");
		n_es->current_posY++;
		es->flag[n_es->current_posY][n_es->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_es->current_posY, n_es->current_posX);
	}
}

void next_move_EW(struct maze_storage *ew, struct node *n_ew)
{
	int ew_x = n_ew->current_posX;
	int ew_y = n_ew->current_posY;

	if (ew->temp_node_E <= ew->temp_node_W)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (ew->maze_value[ew_y][ew_x] <= (ew->temp_node_E + 1))
		{
			ew->maze_value[ew_y][ew_x] = ew->temp_node_E + 1;
			//backtrack_update(ew, n_ew, n_history);
		}
		//move to East Cell
		printf("Move to East Cell. \n");
		n_ew->current_posX++;
		ew->flag[n_ew->current_posY][n_ew->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_ew->current_posY, n_ew->current_posX);
	
	}
	if (ew->temp_node_W < ew->temp_node_E)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (ew->maze_value[ew_y][ew_x] <= (ew->temp_node_W + 1))
		{
			ew->maze_value[ew_y][ew_x] = ew->temp_node_W + 1;
			//backtrack_update(ew, n_ew, n_history);
		}
		//move to West Cell
		printf("Move to West Cell. \n");
		n_ew->current_posX--;
		ew->flag[n_ew->current_posY][n_ew->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_ew->current_posY, n_ew->current_posX);
	}
}

void next_move_NSW(struct maze_storage *nsw, struct node *n_nsw)
{
	int nsw_x = n_nsw->current_posX;
	int nsw_y = n_nsw->current_posY;

	if (nsw->temp_node_N <= nsw->temp_node_S)
	{
		if (nsw->temp_node_N <= nsw->temp_node_W)
		{
			printf("Value of Temp_node_N: %d........\n", nsw->temp_node_N);
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (nsw->maze_value[nsw_y][nsw_x] <= (nsw->temp_node_N + 1))
			{
				nsw->maze_value[nsw_y][nsw_x] = (nsw->temp_node_W) + 1;
				//backtrack_update(nsw, n_nsw, n_history);
			}
			printf("Move to North Cell. \n");
			n_nsw->current_posY--;
			nsw->flag[n_nsw->current_posY][n_nsw->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_nsw->current_posY, n_nsw->current_posX);

		}
	}
	if (nsw->temp_node_W < nsw->temp_node_S)
	{
		if (nsw->temp_node_W < nsw->temp_node_N)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (nsw->maze_value[nsw_y][nsw_x] <= (nsw->temp_node_W + 1))
			{
				nsw->maze_value[nsw_y][nsw_x] = (nsw->temp_node_W) + 1;
				//backtrack_update(nsw, n_nsw, n_history);
			}
			//move to South Cell
			printf("Move to West Cell. \n");
			n_nsw->current_posX--;
			nsw->flag[n_nsw->current_posY][n_nsw->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_nsw->current_posY, n_nsw->current_posX);
		}
	}
	if (nsw->temp_node_S < nsw->temp_node_N)
	{
		if (nsw->temp_node_S <= nsw->temp_node_W)
		{
			//if current cell isn't more than or equal to minimum neighbour + 1
			if (nsw->maze_value[nsw_y][nsw_x] <= (nsw->temp_node_S + 1))
			{
				nsw->maze_value[nsw_y][nsw_x] = (nsw->temp_node_S) + 1;
				//backtrack_update(nsw, n_nsw, n_history);
			}
			//move to North Cell
			printf("Move to South Cell. \n");
			n_nsw->current_posY++;
			nsw->flag[n_nsw->current_posY][n_nsw->current_posX] = 1;
			printf("New Location: [%d][%d]\n", n_nsw->current_posY, n_nsw->current_posX);
		}
	}
}

void next_move_NS(struct maze_storage *ns, struct node *n_ns)
{
	int ns_x = n_ns->current_posX;
	int ns_y = n_ns->current_posY;

	if (ns->temp_node_N <= ns->temp_node_S)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (ns->maze_value[ns_y][ns_x] <= (ns->temp_node_N + 1))
		{
			ns->maze_value[ns_y][ns_x] = ns->temp_node_N + 1;
			//backtrack_update(ns, n_ns, n_history);
		}
		//move to North Cell
		printf("Move to North Cell. \n");
		n_ns->current_posY--;
		ns->flag[n_ns->current_posY][n_ns->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_ns->current_posY, n_ns->current_posX);
	}
	if (ns->temp_node_S < ns->temp_node_N)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (ns->maze_value[ns_y][ns_x] <= (ns->temp_node_S + 1))
		{
			ns->maze_value[ns_y][ns_x] = ns->temp_node_S + 1;
			//backtrack_update(ns, n_ns, n_history);
		}
		//move to South Cell
		printf("Move to South Cell. \n");
		n_ns->current_posY++;
		ns->flag[n_ns->current_posY][n_ns->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_ns->current_posY, n_ns->current_posX);
	}
}

void next_move_NW(struct maze_storage *nw, struct node *n_nw)
{
	int nw_x = n_nw->current_posX;
	int nw_y = n_nw->current_posY;

	if (nw->temp_node_N <= nw->temp_node_W)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (nw->maze_value[nw_y][nw_x] <= (nw->temp_node_N + 1))
		{
			nw->maze_value[nw_y][nw_x] = nw->temp_node_N + 1;
			//backtrack_update(nw, n_nw, n_history);
		}
		//move to North Cell
		printf("Move to North Cell. \n");
		n_nw->current_posY--;
		nw->flag[n_nw->current_posY][n_nw->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_nw->current_posY, n_nw->current_posX);
	}
	if (nw->temp_node_W < nw->temp_node_N)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (nw->maze_value[nw_y][nw_x] <= (nw->temp_node_W + 1))
		{
			nw->maze_value[nw_y][nw_x] = nw->temp_node_W + 1;
			//backtrack_update(nw, n_nw, n_history);
		}
		//move to West Cell
		printf("Move to West Cell. \n");
		n_nw->current_posX--;
		nw->flag[n_nw->current_posY][n_nw->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_nw->current_posY, n_nw->current_posX);	
	}
}

void next_move_SW(struct maze_storage *sw, struct node *n_sw)
{
	int sw_x = n_sw->current_posX;
	int sw_y = n_sw->current_posY;

	if (sw->temp_node_W <= sw->temp_node_S)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (sw->maze_value[sw_y][sw_x] <= (sw->temp_node_W + 1))
		{
			sw->maze_value[sw_y][sw_x] = sw->temp_node_W + 1;
			//backtrack_update(sw, n_sw, n_history);
		}
		//move to West Cell
		printf("Move to West Cell. \n");
		n_sw->current_posX--;
		sw->flag[n_sw->current_posY][n_sw->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_sw->current_posY, n_sw->current_posX);
		
	}
	if (sw->temp_node_S < sw->temp_node_W)
	{
		//if current cell isn't more than or equal to minimum neighbour + 1
		if (sw->maze_value[sw_y][sw_x] <= (sw->temp_node_S + 1))
		{
			sw->maze_value[sw_y][sw_x] = sw->temp_node_S + 1;
			//backtrack_update(sw, n_sw, n_history);
		}
		//move to south cell
		printf("Move to South Cell. \n");
		n_sw->current_posY++;
		sw->flag[n_sw->current_posY][n_sw->current_posX] = 1;
		printf("New Location: [%d][%d]\n", n_sw->current_posY, n_sw->current_posX);
	}
}


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

void check_sensors(struct maze_storage *wall_sensors, struct node *n_sensors, struct maze_map *map)
{
	int n_x = n_sensors->current_posX;
	int n_y = n_sensors->current_posY;

	// printf("current_posX: %d\n", n_sensors->current_posX);
	// printf("current_posY: %d\n\n", n_sensors->current_posY);

	//check the virtual maze map
	wall_sensors->east_wall[n_y][n_x] = map->east_wall[n_y][n_x];
	wall_sensors->north_wall[n_y][n_x] = map->north_wall[n_y][n_x];
	wall_sensors->south_wall[n_y][n_x] = map->south_wall[n_y][n_x];
	wall_sensors->west_wall[n_y][n_x] = map->west_wall[n_y][n_x];

	// printf("Where is the wall?  (E N S W) (1 means wall present, 0 means clear path), for example input the wall status like: 0 1 1 1 \n");
	// scanf("%d %d %d %d", &wall_sensors->east_wall[n_y][n_x], &wall_sensors->north_wall[n_y][n_x], &wall_sensors->south_wall[n_y][n_x], &wall_sensors->west_wall[n_y][n_x]);

}

void store_maze_data(struct maze_storage *data)
{
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			data->maze_value[y][x] = temp_cell_data[y][x];
			data->flag[y][x] = flag_data[y][x];
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

void print_maze(struct maze_storage *print)
{
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			printf("%d ", print->maze_value[x][y]);
		}
		printf("\n");
	}

	printf("\n\n");

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d ", print->flag[i][j]);
		}
		printf("\n");
	}
}

void fix_maze_dimension(struct maze_storage *lowest, struct node *n_lowest)
{
	int x_low, x_high, y_low, y_high;
	int current_x, current_y;
	lowest->temp_node_N = 10; 
	lowest->temp_node_E = 10;
	lowest->temp_node_S = 10;
	lowest->temp_node_W = 10;

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
		lowest->temp_node_N = lowest->maze_value[y_low][current_x];
	}
	//east cell
	if (x_high <= 7)
	{
		lowest->temp_node_E = lowest->maze_value[current_y][x_high];
	}
	//south cell
	if (y_high <= 5)
	{
		lowest->temp_node_S = lowest->maze_value[y_high][current_x];
	}
	//west cell
	if (x_low >= 0)
	{
		lowest->temp_node_W = lowest->maze_value[current_y][x_low];
	}
}

void check_wall_and_value(struct maze_storage *check, struct node *n_check, struct history *n_history)
{
	int check_x = n_check->current_posX;
	int check_y = n_check->current_posY;

	printf("Print Node Values: \nTemp Node E: %d\nTemp Node W: %d\nTemp Node S: %d\nTemp Node N: %d\n", check->temp_node_E, check->temp_node_W, check->temp_node_S, check->temp_node_N);

	if (check->status_wall == WALL_NO)
	{
		//compare and find the smallest of them all
		//check if the robot has been through East path
		if (check->flag[check_y][check_x + 1] == 1)
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//check if the robot has been through South Path
					if (check->flag[check_y + 1][check_x] == 0)
					{
						//go to South
						next_move_South(check, n_check);
					}
				}
				//No history on West
				else
				{
					//check if the robot has been through South Path
					if (check->flag[check_y + 1][check_x] == 1)
					{
						//Move West
						next_move_West(check, n_check);
					}
					//No history on South
					else
					{
						//compare SW values
						next_move_SW(check, n_check);
					}
				}
			}
			//No history on North Path
			else
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//check if the robot has been through South Path
					if (check->flag[check_y + 1][check_x] == 1)
					{
						//Move to north
						next_move_North(check, n_check);
					}
					else
					{
						//NS values
						next_move_NS(check, n_check);
					}
				}
				else
				{
					//check if the robot has been through South Path
					if (check->flag[check_y + 1][check_x] == 1)
					{
						//NW
						next_move_NW(check, n_check);
					}
					else
					{
						//NSW
						next_move_NSW(check, n_check);
					}
				}
			}
		}
		//No history on East path
		else
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//check if the robot has been through South Path
					if (check->flag[check_y + 1][check_x] == 1)
					{
						//go to East
						next_move_East(check, n_check);
					}
					//No history on south
					else
					{
						//compare ES values
						next_move_ES(check, n_check);
					}
				}
				//No history on West
				else
				{
					//check if the robot has been through South Path
					if (check->flag[check_y + 1][check_x] == 1)
					{
						//compare EW values
						next_move_EW(check, n_check);
					}
					//No history on South
					else
					{
						//compare ESW values
						next_move_ESW(check, n_check);
					}
				}
			}
			//No history on North Path
			else
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//check if the robot has been through South Path
					if (check->flag[check_y + 1][check_x] == 1)
					{
						//EN values
						next_move_EN(check, n_check);
					}
					else
					{
						//ENS values
						next_move_ENS(check, n_check);
					}
				}
				else
				{
					//check if the robot has been through South Path
					if (check->flag[check_y + 1][check_x] == 1)
					{
						//ENW
						next_move_ENW(check, n_check);
					}
					else
					{
						//All
						next_move_No(check, n_check);
					}
				}
			}
		}
	}
	else if (check->status_wall == WALL_ENS)
	{
		//check if the robot has been through East path
		if (check->flag[check_y][check_x + 1] == 1)
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through South Path
				if (check->flag[check_y + 1][check_x] == 0)
				{
					//go to South
					next_move_South(check, n_check);
				}
			}
			//No history on North Path
			else
			{
				//check if the robot has been through South Path
				if (check->flag[check_y + 1][check_x] == 1)
				{
					//go to north
					next_move_North(check, n_check);
				}
				else
				{
					//NS values
					next_move_NS(check, n_check);
				}
			}
		}
		//No history on East path
		else
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through South Path
				if (check->flag[check_y + 1][check_x] == 1)
				{
					//Go to East
					next_move_East(check, n_check);
				}
				else
				{
					//ES values
					next_move_ES(check, n_check);
				}
			}
			//No history on North Path
			else
			{
				//check if the robot has been through South Path
				if (check->flag[check_y + 1][check_x] == 1)
				{
					//EN
					next_move_EN(check, n_check);
				}
				else
				{
					//ENS values
					next_move_ENS(check, n_check);
				}
			}
		}
	}
	else if (check->status_wall == WALL_ENW)
	{
		//check if the robot has been through East path
		if (check->flag[check_y][check_x + 1] == 1)
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 0)
				{
					//go to West
					next_move_West(check, n_check);
				}
			}
			//No history on North Path
			else
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//go to north
					next_move_North(check, n_check);
				}
				else
				{
					//NW values
					next_move_NW(check, n_check);
				}
			}
		}
		//No history on East path
		else
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//Go to East
					next_move_East(check, n_check);
				}
				else
				{
					//EW values
					next_move_EW(check, n_check);
				}
			}
			//No history on North Path
			else
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//EN
					next_move_EN(check, n_check);
				}
				else
				{
					//ENW values
					next_move_ENW(check, n_check);
				}
			}
		}
	}
	else if (check->status_wall == WALL_EN)
	{
		//check if the robot has been through East path
		if (check->flag[check_y][check_x + 1] == 1)
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 0)
			{
				//move to north
				next_move_North(check, n_check);
			}
		}
		else
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//move to East Path
				next_move_East(check, n_check);
			}
			else
			{
				//check EN
				next_move_EN(check, n_check);
			}
		}
		
	}
	else if (check->status_wall == WALL_ESW)
	{
		//check if the robot has been through East path
		if (check->flag[check_y][check_x + 1] == 1)
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 0)
				{
					//Move to West
					next_move_West(check, n_check);
				}
			}
			else
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//Move to North
					next_move_North(check, n_check);
				}
				else
				{
					//Check NW
					next_move_NW(check, n_check);
				}
			}
		}	
		else
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//Move to East
					next_move_East(check, n_check);
				}
				else
				{
					//Check EW
					next_move_EW(check, n_check);
				}
			}
			else
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//Check EN
					next_move_EN(check, n_check);
				}
				else
				{
					//Check ENW
					next_move_ENW(check, n_check);
				}
			}
		}			
	}
	else if (check->status_wall == WALL_ES)
	{
		//check if the robot has been through East path
		if (check->flag[check_y][check_x + 1] == 1)
		{
			//check if the robot has been through South Path
			if (check->flag[check_y + 1][check_x] == 0)
			{
				//move to south
				next_move_South(check, n_check);
			}
		}
		else
		{
			//check if the robot has been through South Path
			if (check->flag[check_y + 1][check_x] == 1)
			{
				//move to East Path
				next_move_East(check, n_check);
			}
			else
			{
				//check ES
				next_move_ES(check, n_check);
			}
		}
	}
	else if (check->status_wall == WALL_EW)
	{
		//check if the robot has been through East path
		if (check->flag[check_y][check_x + 1] == 1)
		{
			//check if the robot has been through West Path
			if (check->flag[check_y][check_x - 1] == 0)
			{
				//move to West
				next_move_West(check, n_check);
			}
		}
		else
		{
			//check if the robot has been through West Path
			if (check->flag[check_y][check_x - 1] == 1)
			{
				//move to East Path
				next_move_East(check, n_check);
			}
			else
			{
				//check EW
				next_move_EW(check, n_check);
			}
		}
	}
	else if (check->status_wall == WALL_NSW)
	{
		//check if the robot has been through South path
		if (check->flag[check_y + 1][check_x] == 1)
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 0)
				{
					//Move to West
					next_move_West(check, n_check);
				}
			}
			else
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//Move to North
					next_move_North(check, n_check);
				}
				else
				{
					//Check NW
					next_move_NW(check, n_check);
				}
			}
		}	
		else
		{
			//check if the robot has been through North Path
			if (check->flag[check_y - 1][check_x] == 1)
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//Move to South
					next_move_South(check, n_check);
				}
				else
				{
					//Check SW
					next_move_SW(check, n_check);
				}
			}
			else
			{
				//check if the robot has been through West Path
				if (check->flag[check_y][check_x - 1] == 1)
				{
					//Check NS
					next_move_NS(check, n_check);
				}
				else
				{
					//Check NSW
					next_move_NSW(check, n_check);
				}
			}
		}
	}
	else if (check->status_wall == WALL_NS)
	{
		//check if the robot has been through North path
		if (check->flag[check_y - 1][check_x] == 1)
		{
			//check if the robot has been through South Path
			if (check->flag[check_y + 1][check_x] == 0)
			{
				//move to south
				next_move_South(check, n_check);
			}
		}
		else
		{
			//check if the robot has been through South Path
			if (check->flag[check_y + 1][check_x] == 1)
			{
				//move to North Path
				next_move_North(check, n_check);
			}
			else
			{
				//check NS
				next_move_NS(check, n_check);
			}
		}
	}
	else if (check->status_wall == WALL_NW)
	{
		//check if the robot has been through North path
		if (check->flag[check_y - 1][check_x] == 1)
		{
			//check if the robot has been through West Path
			if (check->flag[check_y][check_x - 1] == 0)
			{
				//move to West
				next_move_West(check, n_check);
			}
		}
		else
		{
			//check if the robot has been through west Path
			if (check->flag[check_y][check_x - 1] == 1)
			{
				//move to North Path
				next_move_North(check, n_check);
			}
			else
			{
				//check NW
				next_move_NW(check, n_check);
			}
		}
	}
	else if (check->status_wall == WALL_SW)
	{
		printf("Debug SW....\n");
		//check if the robot has been through West path
		if (check->flag[check_y][check_x - 1] == 1)
		{
			printf("<----- Check West path\n");
			printf("South flag: %d...\n", check->flag[check_y + 1][check_x]);
			//check if the robot has been through South Path
			if (check->flag[check_y + 1][check_x] == 0)
			{
				printf("Debug move south...\n");
				//move to south
				next_move_South(check, n_check);
			}
		}
		else
		{
			printf("<----- Check else West path\n");
			//check if the robot has been through South Path
			if (check->flag[check_y + 1][check_x] == 1)
			{
				//move to West Path
				next_move_West(check, n_check);
			}
			else
			{
				//check SW
				next_move_SW(check, n_check);
			}
		}
	}

}

void track_position(struct maze_storage *track, struct node *n_track)
{
	//eg. current position at [5][0]
	printf("Enter the initial position of mouse [y][x] For example: 5 0 : ");
	scanf("%d %d", &n_track->current_posY, &n_track->current_posX);
	printf("Initial position is at [%d][%d]\n", n_track->current_posY, n_track->current_posX);
	// n_track->current_posX = 0;
	// n_track->current_posY = 5;

}

void next_move(struct maze_storage *next, struct node *n_next, struct history *h_history)
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
					check_wall_and_value(next, n_next, h_history);
				}
				else if (next->west_wall[current_y][current_x])
				{
					//if clear on the E, N, S
					//Check East, North, South cell values
					next->status_wall = WALL_ENS;
					check_wall_and_value(next, n_next, h_history);
				}		
			}
			else if (next->south_wall[current_y][current_x])
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the E, N, W
					//Check East, north, west cell values
					next->status_wall = WALL_ENW;
					check_wall_and_value(next, n_next, h_history);
				}
				else if (next->west_wall[current_y][current_x])
				{
					//if clear on the E, N
					//Check East, North cell values
					next->status_wall = WALL_EN;
					check_wall_and_value(next, n_next, h_history);
				}
			}	
		}
		else if (next->north_wall[current_y][current_x])
		{
			if (!(next->south_wall[current_y][current_x]))
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the E, S, W
					//Check east, south, west cell values
					next->status_wall = WALL_ESW;
					check_wall_and_value(next, n_next, h_history);
				}
				else if (next->west_wall[current_y][current_x])
				{
					//if clear on the E, S
					//Check East, South cell values
					next->status_wall = WALL_ES;
					check_wall_and_value(next, n_next, h_history);
				}	
			}
			else if (next->south_wall[current_y][current_x])
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the E, W
					//Check East, West cell values
					next->status_wall = WALL_EW;
					check_wall_and_value(next, n_next, h_history);
				}
				else if (next->west_wall[current_y][current_x])
				{
					//clear on E
					//Move to East
					printf("Move to the East. \n");
					current_x++;
					n_next->current_posX = current_x;
					n_next->current_posY = current_y;
					printf("New Location: [%d][%d]\n", n_next->current_posY, n_next->current_posX);
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
					check_wall_and_value(next, n_next, h_history);
				}
				else if (next->west_wall[current_y][current_x])
				{
					//if clear on the N, S
					//Check North, South cell values
					next->status_wall = WALL_NS;
					check_wall_and_value(next, n_next, h_history);
				}		
			}
			else if (next->south_wall[current_y][current_x])
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the N, W
					//Check north, west cell values
					next->status_wall = WALL_NW;
					check_wall_and_value(next, n_next, h_history);
				}
				else if (next->west_wall[current_y][current_x])
				{
					//if clear on the N
					//Move to the North
					printf("Move to the North. \n");
					current_y--;
					n_next->current_posX = current_x;
					n_next->current_posY = current_y;
					printf("New Location: [%d][%d]\n", n_next->current_posY, n_next->current_posX);
				}
			}	
		}
		else if (next->north_wall[current_y][current_x])
		{
			if (!(next->south_wall[current_y][current_x]))
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the S, W
					//Check south, west cell values
					next->status_wall = WALL_SW;
					check_wall_and_value(next, n_next, h_history);
				}
				else if (next->west_wall[current_y][current_x])
				{
					//if clear on the S
					//Move to the South
					printf("Move to the South. \n");
					current_y++;
					n_next->current_posX = current_x;
					n_next->current_posY = current_y;
					printf("New Location: [%d][%d]\n", n_next->current_posY, n_next->current_posX);
				}	
			}
			else if (next->south_wall[current_y][current_x])
			{
				if (!(next->west_wall[current_y][current_x]))
				{
					//if clear on the W
					//move to west
					printf("Move to the West. \n");
					current_x--;
					n_next->current_posX = current_x;
					n_next->current_posY = current_y;
					printf("New Location: [%d][%d]\n", n_next->current_posY, n_next->current_posX);
				}
			}
		}
		
	}
	
}

/*The virtual drawing of the maze map (assuming the mouse does not know anything about it)*/
void wall_map(struct maze_map *map)
{
	//first row 
	//cell [5][0]
	map->east_wall[5][0] = 1; map->north_wall[5][0] = 0; map->south_wall[5][0] = 1; map->west_wall[5][0] = 1;
	//cell [4][0]
	map->east_wall[4][0] = 0; map->north_wall[4][0] = 1; map->south_wall[4][0] = 0; map->west_wall[4][0] = 1;
	//cell [3][0]
	map->east_wall[3][0] = 0; map->north_wall[3][0] = 0; map->south_wall[3][0] = 1; map->west_wall[3][0] = 1;
	//cell [2][0]
	map->east_wall[2][0] = 1; map->north_wall[2][0] = 0; map->south_wall[2][0] = 0;	map->west_wall[2][0] = 1;
	//cell [1][0]
	map->east_wall[1][0] = 1; map->north_wall[1][0] = 0; map->south_wall[1][0] = 0;	map->west_wall[1][0] = 1;
	//cell [0][0]
	map->east_wall[0][0] = 0; map->north_wall[0][0] = 1; map->south_wall[0][0] = 0; map->west_wall[0][0] = 1;

	//second row
	//cell [5][1]
	map->east_wall[5][1] = 0; map->north_wall[5][1] = 0; map->south_wall[5][1] = 1; map->west_wall[5][1] = 1;
	//cell [4][1]
	map->east_wall[4][1] = 0; map->north_wall[4][1] = 0; map->south_wall[4][1] = 0; map->west_wall[4][1] = 0;
	//cell [3][1]
	map->east_wall[3][1] = 1; map->north_wall[3][1] = 0; map->south_wall[3][1] = 0; map->west_wall[3][1] = 0;
	//cell [2][1]
	map->east_wall[2][1] = 1; map->north_wall[2][1] = 0; map->south_wall[2][1] = 0;	map->west_wall[2][1] = 1;
	//cell [1][1]
	map->east_wall[1][1] = 0; map->north_wall[1][1] = 0; map->south_wall[1][1] = 0;	map->west_wall[1][1] = 1;
	//cell [0][1]
	map->east_wall[0][1] = 0; map->north_wall[0][1] = 1; map->south_wall[0][1] = 0; map->west_wall[0][1] = 0;

	//3rd row
	//cell [5][2]
	map->east_wall[5][2] = 0; map->north_wall[5][2] = 0; map->south_wall[5][2] = 1; map->west_wall[5][2] = 0;
	//cell [4][2]
	map->east_wall[4][2] = 1; map->north_wall[4][2] = 1; map->south_wall[4][2] = 0; map->west_wall[4][2] = 0;
	//cell [3][2]
	map->east_wall[3][2] = 1; map->north_wall[3][2] = 0; map->south_wall[3][2] = 1; map->west_wall[3][2] = 1;
	//cell [2][2]
	map->east_wall[2][2] = 1; map->north_wall[2][2] = 0; map->south_wall[2][2] = 0;	map->west_wall[2][2] = 1;
	//cell [1][2]
	map->east_wall[1][2] = 0; map->north_wall[1][2] = 1; map->south_wall[1][2] = 0;	map->west_wall[1][2] = 0;
	//cell [0][2]
	map->east_wall[0][2] = 0; map->north_wall[0][2] = 1; map->south_wall[0][2] = 1; map->west_wall[0][2] = 0;

	//4th row 
	//cell [5][3]
	map->east_wall[5][3] = 0; map->north_wall[5][3] = 1; map->south_wall[5][3] = 1; map->west_wall[5][3] = 0;
	//cell [4][3]
	map->east_wall[4][3] = 0; map->north_wall[4][3] = 1; map->south_wall[4][3] = 1; map->west_wall[4][3] = 1;
	//cell [3][3]
	map->east_wall[3][3] = 0; map->north_wall[3][3] = 0; map->south_wall[3][3] = 1; map->west_wall[3][3] = 1;
	//cell [2][3]
	map->east_wall[2][3] = 0; map->north_wall[2][3] = 1; map->south_wall[2][3] = 0;	map->west_wall[2][3] = 1;
	//cell [1][3]
	map->east_wall[1][3] = 0; map->north_wall[1][3] = 1; map->south_wall[1][3] = 1;	map->west_wall[1][3] = 0;
	//cell [0][3]
	map->east_wall[0][3] = 0; map->north_wall[0][3] = 1; map->south_wall[0][3] = 1; map->west_wall[0][3] = 0;

	//5th row
	//cell [5][4]
	map->east_wall[5][4] = 0; map->north_wall[5][4] = 1; map->south_wall[5][4] = 1; map->west_wall[5][4] = 0;
	//cell [4][4]
	map->east_wall[4][4] = 0; map->north_wall[4][4] = 1; map->south_wall[4][4] = 1; map->west_wall[4][4] = 0;
	//cell [3][4]
	map->east_wall[3][4] = 0; map->north_wall[3][4] = 0; map->south_wall[3][4] = 1; map->west_wall[3][4] = 0;
	//cell [2][4]
	map->east_wall[2][4] = 0; map->north_wall[2][4] = 1; map->south_wall[2][4] = 0;	map->west_wall[2][4] = 1;
	//cell [1][4]
	map->east_wall[1][4] = 0; map->north_wall[1][4] = 1; map->south_wall[1][4] = 1;	map->west_wall[1][4] = 0;
	//cell [0][4]
	map->east_wall[0][4] = 0; map->north_wall[0][4] = 1; map->south_wall[0][4] = 1; map->west_wall[0][4] = 0;

	//6th row -->here now
	//cell [5][5]
	map->east_wall[5][5] = 0; map->north_wall[5][5] = 1; map->south_wall[5][5] = 1; map->west_wall[5][5] = 0;
	//cell [4][5]
	map->east_wall[4][5] = 0; map->north_wall[4][5] = 0; map->south_wall[4][5] = 1; map->west_wall[4][5] = 0;
	//cell [3][5]
	map->east_wall[3][5] = 0; map->north_wall[3][5] = 1; map->south_wall[3][5] = 0; map->west_wall[3][5] = 0;
	//cell [2][5]
	map->east_wall[2][5] = 0; map->north_wall[2][5] = 0; map->south_wall[2][5] = 1;	map->west_wall[2][5] = 1;
	//cell [1][5]
	map->east_wall[1][5] = 1; map->north_wall[1][5] = 1; map->south_wall[1][5] = 0;	map->west_wall[1][5] = 0;
	//cell [0][5]
	map->east_wall[0][5] = 0; map->north_wall[0][5] = 1; map->south_wall[0][5] = 1; map->west_wall[0][5] = 0;

	//7th row
	//cell [5][6]
	map->east_wall[5][6] = 0; map->north_wall[5][6] = 0; map->south_wall[5][6] = 1; map->west_wall[5][6] = 0;
	//cell [4][6]
	map->east_wall[4][6] = 1; map->north_wall[4][6] = 0; map->south_wall[4][6] = 0; map->west_wall[4][6] = 0;
	//cell [3][6]
	map->east_wall[3][6] = 1; map->north_wall[3][6] = 1; map->south_wall[3][6] = 0; map->west_wall[3][6] = 0;
	//cell [2][6]
	map->east_wall[2][6] = 0; map->north_wall[2][6] = 0; map->south_wall[2][6] = 1;	map->west_wall[2][6] = 0;
	//cell [1][6]
	map->east_wall[1][6] = 1; map->north_wall[1][6] = 0; map->south_wall[1][6] = 0;	map->west_wall[1][6] = 1;
	//cell [0][6]
	map->east_wall[0][6] = 1; map->north_wall[0][6] = 1; map->south_wall[0][6] = 0; map->west_wall[0][6] = 0;

	//8th row
	//cell [5][7]
	map->east_wall[5][7] = 1; map->north_wall[5][7] = 0; map->south_wall[5][7] = 1; map->west_wall[5][7] = 0;
	//cell [4][7]
	map->east_wall[4][7] = 1; map->north_wall[4][7] = 0; map->south_wall[4][7] = 0; map->west_wall[4][7] = 1;
	//cell [3][7]
	map->east_wall[3][7] = 1; map->north_wall[3][7] = 0; map->south_wall[3][7] = 0; map->west_wall[3][7] = 1;
	//cell [2][7]
	map->east_wall[2][7] = 1; map->north_wall[2][7] = 0; map->south_wall[2][7] = 0;	map->west_wall[2][7] = 0;
	//cell [1][7]
	map->east_wall[1][7] = 1; map->north_wall[1][7] = 0; map->south_wall[1][7] = 0;	map->west_wall[1][7] = 1;
	//cell [0][7]
	map->east_wall[0][7] = 1; map->north_wall[0][7] = 1; map->south_wall[0][7] = 0; map->west_wall[0][7] = 1;

}

void path_history(struct maze_storage *history, struct node *n_history, struct history *data)
{
	//for every move, the cell coordinates are stored in the stack
	int a = n_history->steps;
	data->history_posX[a] = n_history->current_posX;
	data->history_posY[a] = n_history->current_posY;

	// if (a > 0)
	// {
	// 	printf("History Data X: %d\n", data->history_posX[a - 1]);
	// 	printf("History Data Y: %d\n", data->history_posY[a - 1]);
	// 	//backtrack_update(history, n_history, data);
	// }
}

void backtrack_update(struct maze_storage *update, struct node *n_update, struct history *h_update)
{
	if ((n_update->steps > 0))
	{
		printf("Backtrack_update: %d.........\n", n_update->steps);
		//every move, the previous cell value should increase as the path continues
		// for (int i = 0; i < (n_update->steps); i++)
		// {
		// 	int x_update = h_update->history_posX[i];
		// 	int y_update = h_update->history_posY[i];
		// 	update->maze_value[y_update][x_update]++;
		// }

		//two step behind
		int x_1 = h_update->history_posX[n_update->steps - 1];
		int y_1 = h_update->history_posY[n_update->steps - 1];
		// //two step behind
		// int x_2 = h_update->history_posX[n_update->steps - 2];
		// int y_2 = h_update->history_posY[n_update->steps - 2];

		printf("Test Previous Cell data [%d][%d]: %d  \n", y_1, x_1, update->maze_value[y_1][x_1]);
		printf("Test Current Cell data [%d][%d]: %d   \n", n_update->current_posY, n_update->current_posX, (update->maze_value[n_update->current_posY][n_update->current_posX]));

		// if ((update->maze_value[n_update->current_posY][n_update->current_posX]) >= (update->maze_value[y_1][x_1]))
		// {
		for (int i = 0; i < (n_update->steps - 1); i++)
		{
			int x_2 = h_update->history_posX[i];
			int y_2 = h_update->history_posY[i];
			update->maze_value[y_2][x_2] = update->maze_value[y_2][x_2] + 1; //((n_update->steps - 1) - i);
			printf("Updated cell data [%d][%d]: %d  \n", y_2, x_2, update->maze_value[y_2][x_2]);
		}
		// } 
	}
}

int main(void)
{
	struct maze_storage cell_data;
	struct node node_data;
	struct maze_map map_data;
	struct history history_data;

	printf("Check Main \n");

	cell_data.status_wall = 0;
	node_data.steps = 0;
	cell_data.goal = 5;

	//function to track the real time coordinates of the node
	track_position(&cell_data, &node_data);

	//function to store the initial maze data
	store_maze_data(&cell_data);

	//function for virtual maze map
	wall_map(&map_data);

	while (cell_data.goal > 0)
	{
		//function to stack cell history
		path_history(&cell_data, &node_data, &history_data);

		//function to convert sensors reading to algorithm
		check_sensors(&cell_data, &node_data, &map_data);

		//function to check the cell paths
		check_walls(&cell_data, &node_data);

		// //function to move the mouse to the lowest distance value
		// move_lowest_cell(&cell_data, &node_data);
		fix_maze_dimension(&cell_data, &node_data);

		//function to compare the wall status and lowest distance value
		next_move(&cell_data, &node_data, &history_data);

		backtrack_update(&cell_data, &node_data, &history_data);

		printf("Current cell value: %d\n", cell_data.maze_value[node_data.current_posY][node_data.current_posX]);
		cell_data.goal = cell_data.maze_value[node_data.current_posY][node_data.current_posX];

		print_maze(&cell_data); 

		node_data.steps++;
		printf("Number of Steps: %d \n", node_data.steps);
	}

	return 0;
}
