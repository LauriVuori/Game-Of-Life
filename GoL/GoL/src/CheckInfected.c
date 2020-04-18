/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:Checkinfected
 DESCRIPTION:Chech neighbour cells if there is infected
	Input:2d array to go trough cells
	Output: If there is number 2 in nearby cells
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
int Checkinfected(struct cell infected[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol){
int row,colum, Mcol, Mrow, isInfected;

        for (row = -1; row < 2; row++){
            for (colum = -1; colum < 2; colum++){
                Mrow = (BOARD_HEIGHT + row + cRow) % BOARD_HEIGHT;
                Mcol = (BOARD_WIDTH + colum + cCol) % BOARD_WIDTH;

                    if (infected[Mrow][Mcol].current == 2){
                        isInfected = 2;
                        return isInfected;
                    }
            }
        }
    return 0;
}