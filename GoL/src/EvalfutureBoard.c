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
 NAME:EvalFutureBoard
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void EvalFutureBoard(struct cell FutBoard[BOARD_HEIGHT][BOARD_WIDTH]){
int row,colum, neighbours = 0, state = 0;
int isfected = 0;
FutBoard[0][0].generation++;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            state = FutBoard[row][colum].current;

            neighbours = CountNeighbour(FutBoard, row, colum);

                //all infecteds gets lost if spawns just 1
                if (state == 0 && neighbours == 3){
                    if (isfected = (Checkinfected(FutBoard,row,colum)) == 2){ //TODO: Voisi esim. ehto syntyykö virus aina
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
                    //infectOthers(FutBoard, row, colum);
                    
                    // CHANCE TO INFECTED DIE RANDOM--->  
                    if (rand()%MAX_RAND_DEATH+MIN_RAND_DEATH== 1){
                        FutBoard[row][colum].future = 0;
                    }
                    else {
                    FutBoard[row][colum].future = 2;
                    }
                }
                else if (state == 2 && (neighbours < 2 || neighbours > 3)){
                    //infectOthers(FutBoard, row, colum); //TODO: mahd turha...
                    FutBoard[row][colum].future = 0;
                } 
                                  
                /*   
                else {
                    FutBoard[row][colum].future = state;
                }*/
        }

    }
    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            FutBoard[row][colum].current = FutBoard[row][colum].future;
        }
    }
}