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
 NAME:ClearVirus
 DESCRIPTION:Clear board from virus
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void ClearVirus(struct cell Clear[BOARD_HEIGHT][BOARD_WIDTH]){
int row,colum;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){

            if (Clear[row][colum].current == 2){
                // chance to die randomly on virus disappears---> 
                if (rand()%MAX_RAND_DEATH+MIN_RAND_DEATH== 1){
                        Clear[row][colum].future = 0;
                }
                else{
                    Clear[row][colum].current = 1;  
                }
                
                
            }
        }
    }
}