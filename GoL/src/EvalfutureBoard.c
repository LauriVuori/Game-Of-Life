#include "main.h"


/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:EvalFutureBoard
 DESCRIPTION: Evaluate what happens to current cell
	Input: Array to determine cells future
	Output: Array with new values
  Used global variables: BOARD_HEIGHT, BOARD_WIDTH
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void EvalFutureBoard(struct cell FutBoard[BOARD_HEIGHT][BOARD_WIDTH]){
int row,colum, neighbours = 0, state = 0, isfected;
int isinfected = 0;

//Start counting generations
FutBoard[0][0].generation++;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            state = FutBoard[row][colum].current;
            neighbours = CountNeighbour(FutBoard, row, colum);

                if (state == 0 && neighbours == 3){
                    if (isinfected = (Checkinfected(FutBoard,row,colum)) == 2){
                        FutBoard[row][colum].future = 2;
                    }
                    else{
                        FutBoard[row][colum].future = 1;
                    } 
                }
                else if (state == 1 && (neighbours < 2 || neighbours > 3)){
                    FutBoard[row][colum].future = 0;
                } 
                else if (state == 1 && (neighbours == 2 || neighbours == 3)){
                    FutBoard[row][colum].future = 1;
                }
                else if (state == 2 && (neighbours == 2 || neighbours == 3)){
                    // CHANCE TO INFECTED DIE RANDOM--->  
                    if (rand()%MAX_RAND_DEATH+MIN_RAND_DEATH== 1){
                        FutBoard[row][colum].future = 0;
                    }
                    else {
                    FutBoard[row][colum].future = 2;
                    }
                }
                else if (state == 2 && (neighbours < 2 || neighbours > 3)){
                    FutBoard[row][colum].future = 0;
                } 
        }

    }
    //Current to new array
    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            FutBoard[row][colum].current = FutBoard[row][colum].future;
        }
    }
}