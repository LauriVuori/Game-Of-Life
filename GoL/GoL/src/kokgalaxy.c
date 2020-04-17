#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:kokgalaxy
 DESCRIPTION: Draw game of life oscillator
	  Input: Array to fill cells
	  Output: Array with predefined pattern
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void kokgalaxy(struct cell galaxy[BOARD_HEIGHT][BOARD_WIDTH]){
int i = 10;

    galaxy[i+5][i+5].current = 1;
    galaxy[i+6][i+5].current = 1;
    galaxy[i+7][i+5].current = 1;
    galaxy[i+8][i+5].current = 1;
    galaxy[i+9][i+5].current = 1;
    galaxy[i+10][i+5].current = 1;

    galaxy[i+5][i+6].current = 1;
    galaxy[i+6][i+6].current = 1;
    galaxy[i+7][i+6].current = 1;
    galaxy[i+8][i+6].current = 1;
    galaxy[i+9][i+6].current = 1;
    galaxy[i+10][i+6].current = 1;

    galaxy[i+12][i+5].current = 1;
    galaxy[i+12][i+6].current = 1;
    galaxy[i+12][i+7].current = 1;
    galaxy[i+12][i+8].current = 1;
    galaxy[i+12][i+9].current = 1;
    galaxy[i+12][i+10].current = 1;

    galaxy[i+13][i+5].current = 1;
    galaxy[i+13][i+6].current = 1;
    galaxy[i+13][i+7].current = 1;
    galaxy[i+13][i+8].current = 1;
    galaxy[i+13][i+9].current = 1;
    galaxy[i+13][i+10].current = 1;

    galaxy[i+5][i+8].current = 1;
    galaxy[i+5][i+9].current = 1;
    galaxy[i+5][i+10].current = 1;
    galaxy[i+5][i+11].current = 1;
    galaxy[i+5][i+12].current = 1;
    galaxy[i+5][i+13].current = 1;

    galaxy[i+6][i+8].current = 1;
    galaxy[i+6][i+9].current = 1;
    galaxy[i+6][i+10].current = 1;
    galaxy[i+6][i+11].current = 1;
    galaxy[i+6][i+12].current = 1;
    galaxy[i+6][i+13].current = 1;

    galaxy[i+8][i+12].current = 1;
    galaxy[i+9][i+12].current = 1;
    galaxy[i+10][i+12].current = 1;
    galaxy[i+11][i+12].current = 1;
    galaxy[i+12][i+12].current = 1;
    galaxy[i+13][i+12].current = 1;

    galaxy[i+8][i+13].current = 1;
    galaxy[i+9][i+13].current = 1;
    galaxy[i+10][i+13].current = 1;
    galaxy[i+11][i+13].current = 1;
    galaxy[i+12][i+13].current = 1;
    galaxy[i+13][i+13].current = 1;
}