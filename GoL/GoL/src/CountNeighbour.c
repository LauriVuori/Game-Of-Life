#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:CountNeighbour
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
int CountNeighbour(struct cell Neighbour[BOARD_HEIGHT][BOARD_WIDTH], int cRow, int cCol){
int row,colum, sum = 0, Mcol, Mrow;

        for (row = -1; row < 2; row++){
            for (colum = -1; colum < 2; colum++){
                Mrow = (BOARD_HEIGHT + row + cRow) % BOARD_HEIGHT;
                Mcol = (BOARD_WIDTH + colum + cCol) % BOARD_WIDTH;
                    if (Neighbour[Mrow][Mcol].current > 0){
                        sum++;
                    }
            }
        }
    // minus own life
    if (Neighbour[cRow][cCol].current > 0){
        sum--;
    }
    return sum;
}