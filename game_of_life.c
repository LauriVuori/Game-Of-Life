/***************************************************************************
 *   Copyright (C) $Year$ by $Lauri Vuori$   *
 *   $Email$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
     $game_of_life$ 

 2.  DESCRIPTION

 3.  VERSIONS
       Original:
         $Date$ / $Lauri Vuori$

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <ncurses.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */


/* Global constants */
#define MIN_RAND 0
#define MAX_RAND 2

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

/* Global variables */

/* Global structures */
struct cell{

int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round calculation */

};




/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

void RandBoard(struct cell start[10][10]);
void PrintCurrentBoard(struct cell CurBoard[10][10]);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
/* 3 sääntöä- birth, death, survival
depends neibhpours

0 -> 1 vain jos 3 naapuria on hengissä = 0->1 >3 naapuria
1 -> 0 jos vähemmän kuin 2 hengissä tai enemmän kuin 3 ---- 
*/

int main(void){

srand(time(NULL));
            //   rivi  paikka
            //     y    x
struct cell board [BOARD_HEIGHT] [BOARD_WIDTH] = {0, 0};
    RandBoard(board);
    PrintCurrentBoard(board);

/*
int row = 0, colum = 0;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            board[row][colum].current=rand()%MAX_RAND+MIN_RAND;
        }
    }


int row,colum;
printf("current life\n");
    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum=0;colum < BOARD_WIDTH ;colum++){
            printf("%d", board[row][colum].current);
        }
        printf("\n");
    }




int sum = 0;
    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){

            
            /*sum += board[row - 1][colum - 1].current;
            sum += board[row][colum - 1].current;
            sum += board[row + 1][colum - 1].current;
            sum += board[row + 1][colum].current;
            sum += board[row + 1][colum + 1].current;
            sum += board[row][colum + 1].current;
            sum += board[row - 1][colum + 1].current;
            sum += board[row - 1][colum].current;
        }
    }
  





    for (row = 0;row < BOARD_HEIGHT; row++){
        for (colum = 0 ;colum < BOARD_WIDTH ;colum++){
            board[row][colum].future = board[row][colum].current; 
        }
    }

printf("Future life\n");
    for (row = 0; row < BOARD_HEIGHT; row++){
        for ( colum = 0; colum < BOARD_WIDTH; colum++){
            printf("%d", board[row][colum].future);
        }
        printf("\n");
    }
*/
} /* end of main */








/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:RandBoard
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
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

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void PrintCurrentBoard(struct cell CurBoard[10][10]){
    int row,colum;
    printf("current life\n");
    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum=0;colum < BOARD_WIDTH ;colum++){
            printf("%d", CurBoard[row][colum].current);
        }
        printf("\n");
    }

}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/