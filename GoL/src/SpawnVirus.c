#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:Spawn_virus_cells
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void Spawn_virus_cells(struct cell SpawnVirus[BOARD_HEIGHT][BOARD_WIDTH]){

    SpawnVirus[BOARD_HEIGHT/2+2][BOARD_WIDTH/2+3].current = 2;
    SpawnVirus[BOARD_HEIGHT/2+2][BOARD_WIDTH/2+4].current = 2;
    SpawnVirus[BOARD_HEIGHT/2+2][BOARD_WIDTH/2+5].current = 2;
    SpawnVirus[BOARD_HEIGHT/2+1][BOARD_WIDTH/2+5].current = 2;
    SpawnVirus[BOARD_HEIGHT/2+0][BOARD_WIDTH/2+4].current = 2;
    /*
    for(int i = 0; i<= 50; i++){
    SpawnVirus[rand()%BOARD_HEIGHT+0][rand()%BOARD_WIDTH+0].current= 2;
    }*/
}