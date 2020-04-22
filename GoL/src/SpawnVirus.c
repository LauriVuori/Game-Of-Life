/**
 * @fn 
 * @brief 
 * @param 
 * @return 
 */
/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:Spawn_virus_cells
 DESCRIPTION: Spawn cells randomly to 2d array
	  Input: 2d array to fill cells with "virus"
	  Output: fixed spots filled with 2:s
  Used global variables:
  Used global constants:BOARD_HEIGHT,BOARD_WIDTH
 REMARKS when using this function:
*********************************************************************/
void Spawn_virus_cells(struct cell SpawnVirus[BOARD_HEIGHT][BOARD_WIDTH]){
int startrow = 0;
int startcolum= 0;

    startrow = rand()%BOARD_HEIGHT + 0;
    startcolum = rand()%BOARD_WIDTH + 0;
    SpawnVirus[startrow+2][startcolum+3].current = 2;
    SpawnVirus[startrow+2][startcolum+4].current = 2;
    SpawnVirus[startrow+2][startcolum+5].current = 2;
    SpawnVirus[startrow+1][startcolum+5].current = 2;
    SpawnVirus[startrow+0][startcolum+4].current = 2;
}