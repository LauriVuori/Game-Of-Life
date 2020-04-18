/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include "main.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:Drawboard
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void Drawboard(struct cell Drawboard[BOARD_HEIGHT][BOARD_WIDTH]){
int row, colum;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0;colum < BOARD_WIDTH ;colum++){
            move(row,colum);
            
            if(Drawboard[row][colum].future == 1){
                attron(COLOR_PAIR(LIVE));

                // Draw just green backround
                mvaddch(row, colum, ' ');
                //printw("%d", Drawboard[row][colum].future);
                attroff(COLOR_PAIR(DEFAULT));
            }
            else if (Drawboard[row][colum].future == 2){
                attron(COLOR_PAIR(INFECTED));

                // Draw just green backround
                mvaddch(row, colum, ' ');
                //printw("%d", Drawboard[row][colum].future);
                attroff(COLOR_PAIR(DEFAULT));
            }
            else{
                printw("%d", Drawboard[row][colum].future);  
            }   
        }
    }
}