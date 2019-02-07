// #include <stdlib.h>
// #include <stdbool.h>
// #include "maze.h"

// //Maze Algorithm

// //Initialise the all the cells, give all cells a value from 0 to 6

// /* 
// 6 5 4 3 3 4 5 6 
// 5 4 3 2 2 3 4 5
// 4 3 2 1 1 2 3 4
// 3 2 1 0 0 1 2 3
// 3 2 1 0 0 1 2 3
// 4 3 2 1 1 2 3 4 
// 5 4 3 2 2 3 4 5
// 6 5 4 3 3 4 5 6 
// */

// struct initial_cell
// {
//     int initial_cell [8][8] =   { {6, 5, 4, 3, 3, 4, 5, 6}, 
//                                   {5, 4, 3, 2, 2, 3, 4, 5},
//                                   {4, 3, 2, 1, 1, 2, 3, 4},
//                                   {3, 2, 1, 0, 0, 1, 2, 3},
//                                   {3, 2, 1, 0, 0, 1, 2, 3},
//                                   {4, 3, 2, 1, 1, 2, 3, 4}, 
//                                   {5, 4, 3, 2, 2, 3, 4, 5},
//                                   {6, 5, 4, 3, 3, 4, 5, 6} };
// }; 

// void walls()
// {
//     //check for walls in all directions
//     //North, West, South, East
//     int walls [4] = {'N', 'W', 'S', 'E'}; 
// }

// /*when the mouse starts*/

// //Read Sensors
// void Read_Sensors(int sensor_bin[])
// {
//     bool current_wall[4]; 
//     //Check North
//     if (sensor_bin[0] == 1)
//     {
//         current_wall[0] = 1;
//         //print walls infomation on UART
//         //print walls [0];
//     }
//     //Check West
//     if (sensor_bin[1] == 1)
//     {
//         current_wall[1] = 1;
//         //print walls infomation on UART
//         //print walls [1];
//     }
//     //Check South
//     if (sensor_bin[2] == 1)
//     {
//         current_wall[2] = 1;
//         //print walls infomation on UART
//         //print walls [2];
//     }
//     //Check East
//     if (sensor_bin[3] == 1)
//     {
//         current_wall[3] = 1;
//         //print walls infomation on UART
//         //print walls [3];
//     }
// }


// //Update Wall Map
  
// //Update Cell Map

// //Find Smallest Neighbour cell Value
// void check_Neighbour()
// {
    
// }
// //Move to smallest Neighbour cell value


