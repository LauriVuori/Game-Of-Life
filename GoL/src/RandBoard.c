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
 NAME:RandBoard
 DESCRIPTION: Generate random lives on board
	Input:Structure with 2 dimensional array to be filled with "lives" 
	Output:Use rand to put number 1 on random places on the board
  Used global variables:
  Used global constants:BOARD_HEIGHT, BOARD_WIDTH
 REMARKS when using this function:
*********************************************************************/
void RandBoard(struct cell start[BOARD_HEIGHT][BOARD_WIDTH]){
int row,colum;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            start[row][colum].current=rand()%MAX_RAND+MIN_RAND;
        }
    }
}