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
#include <curses.h>
#include <unistd.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */


/* Global constants */
#define MIN_RAND 0
#define MAX_RAND 2

#define BOARD_WIDTH 100
#define BOARD_HEIGHT 60

/* Global variables */

/* Global structures */
struct cell{

int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round calculation */

};




/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

void RandBoard(struct cell start[BOARD_HEIGHT][BOARD_WIDTH]);
void PrintCurrentBoard(struct cell CurBoard[BOARD_HEIGHT][BOARD_WIDTH]);
int CountNeighbour(struct cell Neighbour[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol);
void EvalFutureBoard(struct cell FutBoard[BOARD_HEIGHT][BOARD_WIDTH]);
void PrintFutureBoard(struct cell PrintFutBoard[BOARD_HEIGHT][BOARD_WIDTH]);

void Drawboard(struct cell Drawboard[BOARD_HEIGHT][BOARD_WIDTH]);
/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
/* 3 sääntöä- birth, death, survival
depends neibhpours

0 -> 1 vain jos 3 naapuria on hengissä = 0->1 >3 naapuria
1 -> 0 jos vähemmän kuin 2 hengissä tai enemmän kuin 3 ---- 
*/

int main(void){
    initscr (); 
    clear ();   
    nodelay (stdscr, TRUE);	
    
    start_color(); 
    init_pair (1, COLOR_RED, COLOR_BLACK); 
    init_pair (2, COLOR_GREEN, COLOR_BLACK); 
    bkgd (COLOR_PAIR (1)); 
    noecho ();
    keypad(stdscr, TRUE);
srand(time(NULL));
            //   rivi  paikka
            //     y    x
struct cell board [BOARD_HEIGHT] [BOARD_WIDTH] = {0, 0};

    RandBoard(board);

    //PrintCurrentBoard(board); 
int i = 0;
curs_set(0);
bool ex = FALSE;
    while ( !ex )
    {
        int ch = getch();

        switch ( ch )
        {
        case ERR:
            
            break;
        case KEY_F(2): 
            ex = TRUE;
            break;
        default: 
            EvalFutureBoard(board);
            Drawboard(board);
            break;
        }

        refresh(); //Выводим на настоящий экран

    }


    //PrintFutureBoard(board);



    nodelay (stdscr, FALSE);
    getch ();
    endwin ();
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
 NAME:PrintCurrentBoard
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void PrintCurrentBoard(struct cell CurBoard[BOARD_HEIGHT][BOARD_WIDTH]){
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
int CountNeighbour(struct cell Neighbour[BOARD_HEIGHT][BOARD_WIDTH], int cRow, int cCol){

int row,colum, sum = 0;
int Mcol, Mrow;

        for (row = -1; row < 2; row++){
            for (colum = -1; colum < 2; colum++){
                Mcol = (BOARD_HEIGHT + row + cRow) % BOARD_HEIGHT;
                Mrow = (BOARD_WIDTH + colum + cCol) % BOARD_WIDTH;
                sum += Neighbour[Mcol][Mrow].current;
            }
        }
    // minus own life
    sum -= Neighbour[cRow][cCol].current;
    return sum;
}
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
    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            state = FutBoard[row][colum].current;
            neighbours = CountNeighbour(FutBoard, row, colum);

                if (state == 0 && neighbours == 3){
                    FutBoard[row][colum].future = 1;
                    
                }
                else if (state == 1 && (neighbours < 2 || neighbours > 3)){
                    FutBoard[row][colum].future = 0;
                }       
                else {
                    FutBoard[row][colum].future = state;
                }
        }

    }
    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            FutBoard[row][colum].current = FutBoard[row][colum].future;
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
void PrintFutureBoard(struct cell PrintFutBoard[BOARD_HEIGHT][BOARD_WIDTH]){
    int row,colum;
    printf("FUTURE LIFE\n");

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0;colum < BOARD_WIDTH ;colum++){

            printf("%d", PrintFutBoard[row][colum].future);
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
void Drawboard(struct cell Drawboard[BOARD_HEIGHT][BOARD_WIDTH]){
int row, colum;
    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0;colum < BOARD_WIDTH ;colum++){
            move(row,colum);
            if(Drawboard[row][colum].future == 1){
                attron(COLOR_PAIR(2));
                printw("%d", Drawboard[row][colum].future);
                attroff(COLOR_PAIR(1));
            }
            else{
            
            printw("%d", Drawboard[row][colum].future);  
            }
            
        }
    }
}