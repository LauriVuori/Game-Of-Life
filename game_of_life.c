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
       <5.4.2020-14:08 Normal GOF works, define INCCURSES to use curses. Start working on "virus".
       |14:10 - walls tested, and all different statements
       |14:22 - Added generations/ board[0][0] adds one in every gene TODO: FIX generations to not array
       |20.11 - Added infect and Checkinfected, need to do something to spawning, only spawning 1 doesnt work
       |21.23 - Check works with new spawning is there virus in neighbours
       |21.49 - Added random death on live while infected
       >

**********************************************************************/

// define this to include curses drawing,
//#define INCCURSES

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#ifdef INCCURSES
#include <curses.h>
#endif

#include <time.h>
#include <unistd.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */


/* Global constants */
#define MIN_RAND 0
#define MAX_RAND 2
#define MIN_RAND_DEATH 0
#define MAX_RAND_DEATH 10

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

#define DEFAULT 1
#define LIVE 2
#define INFECTED 3

/* Global variables */

/* Global structures */
struct cell{

int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round calculation */
int generation;

};




/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

void RandBoard(struct cell start[BOARD_HEIGHT][BOARD_WIDTH]);
void PrintCurrentBoard(struct cell CurBoard[BOARD_HEIGHT][BOARD_WIDTH]);
int CountNeighbour(struct cell Neighbour[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol);
void EvalFutureBoard(struct cell FutBoard[BOARD_HEIGHT][BOARD_WIDTH]);
void PrintFutureBoard(struct cell PrintFutBoard[BOARD_HEIGHT][BOARD_WIDTH]);

#ifdef INCCURSES
void Drawboard(struct cell Drawboard[BOARD_HEIGHT][BOARD_WIDTH]);
#endif
int Checkinfected(struct cell infected[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol);
void infectOthers(struct cell infect[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol);
// Testing patterns and oscillators
void kokgalaxy(struct cell galaxy[BOARD_HEIGHT][BOARD_WIDTH]);
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


    /*--> beehive
    board[5][5].current = 1;
    board[5][6].current = 1;
    board[5][7].current = 1;
    board[5][8].current = 1;
    */
    /*--> beehive
    board[5][5].current = 1;
    board[6][5].current = 1;
    board[6][6].current = 1;
    board[6][7].current = 1;
    */
    /*--> traffic light
    board[3][2].current = 1;
    board[3][3].current = 1;
    board[3][4].current = 1;
    board[2][3].current = 1;
    */



//include curses and drawing

//RandBoard(board);
#ifdef INCCURSES
    initscr (); 
    clear ();   
    nodelay (stdscr, TRUE);	
    
    start_color(); 
    init_pair (DEFAULT, COLOR_BLACK, COLOR_BLACK);
    init_pair (LIVE, COLOR_BLACK, COLOR_RED); 
    init_pair (INFECTED, COLOR_BLACK, COLOR_GREEN);  
    bkgd (COLOR_PAIR (DEFAULT));
    noecho ();
    keypad(stdscr, TRUE);

    int i = 0;
    //kokgalaxy(board);

    /*missile
    board[2][3].current = 1;
    board[2][4].current = 1;
    board[2][5].current = 1;
    board[1][5].current = 1;
    board[0][4].current = 1;
    */
    RandBoard(board);
    board[35][75].current = 2;
    board[35][77].current = 2;
    board[35][76].current = 2;
    board[35][77].current = 2;
    board[35][77].current = 2;
    board[35][76].current = 2;
    board[35][79].current = 2;
        while(i < 500000000){
            refresh();
                    
                    EvalFutureBoard(board);
                    Drawboard(board);
                    //isompi hitaampi
                    usleep(100000);
            refresh();
        i++;
        }




    nodelay (stdscr, FALSE);
    getch ();
    endwin ();
#else
char command = 10;

// add dots on board
//kokgalaxy(board);
   /* board[5][5].current = 1;
    board[6][5].current = 2;
    board[7][5].current = 1;
    */
    /*
    board[5][6].current = 1;
    board[6][6].current = 1;
    board[6][7].current = 2;
    board[7][6].current = 1;*/

    board[5][5].current = 2;
    board[6][6].current = 2;
    board[5][6].current = 2;
PrintCurrentBoard(board);
while(command == 10){
    EvalFutureBoard(board);
    PrintFutureBoard(board);
    printf("Enter to continue/ any char/key stop");
    scanf("%c", &command);
}
#endif
} /* end of main */








/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

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
CurBoard[0][0].generation++;
    printf("current life, GENER:%d\n", CurBoard[0][0].generation);

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
                    if (isfected = (Checkinfected(FutBoard,row,colum)) == 2){
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
                    
                    // 1/10 chance to die
                    if (rand()%MAX_RAND_DEATH+MIN_RAND_DEATH == 1){
                        FutBoard[row][colum].future = 0;
                    }
                    else {
                    FutBoard[row][colum].future = 2;
                    }
                }
                else if (state == 2 && (neighbours < 2 || neighbours > 3)){
                    //infectOthers(FutBoard, row, colum);
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
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:Checkinfected
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
int Checkinfected(struct cell infected[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol){
int row,colum;
int Mcol, Mrow;
int isInfected;

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
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:infect
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void infectOthers(struct cell infect[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol){
int row,colum;
int Mcol, Mrow;

        for (row = -1; row < 2; row++){
            for (colum = -1; colum < 2; colum++){
                Mrow = (BOARD_HEIGHT + row + cRow) % BOARD_HEIGHT;
                Mcol = (BOARD_WIDTH + colum + cCol) % BOARD_WIDTH;
                    if (infect[Mrow][Mcol].current == 1){
                        infect[Mrow][Mcol].future = 2;
                    }
            }
        }
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:PrintFutureBoard
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void PrintFutureBoard(struct cell PrintFutBoard[BOARD_HEIGHT][BOARD_WIDTH]){
    int row,colum;
    printf("FUTURE LIFE- GENERATION:%d\n", PrintFutBoard[0][0].generation);

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH ;colum++){

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
#ifdef INCCURSES
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
#endif

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:kokgalaxy
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void kokgalaxy(struct cell galaxy[BOARD_HEIGHT][BOARD_WIDTH]){
    //left
    galaxy[5][5].current = 2;
    galaxy[6][5].current = 1;
    galaxy[7][5].current = 1;
    galaxy[8][5].current = 1;
    galaxy[9][5].current = 1;
    galaxy[10][5].current = 1;

    galaxy[5][6].current = 1;
    galaxy[6][6].current = 1;
    galaxy[7][6].current = 1;
    galaxy[8][6].current = 1;
    galaxy[9][6].current = 1;
    galaxy[10][6].current = 1;

    //bottom 11 rivi väli

    galaxy[12][5].current = 1;
    galaxy[12][6].current = 1;
    galaxy[12][7].current = 1;
    galaxy[12][8].current = 1;
    galaxy[12][9].current = 1;
    galaxy[12][10].current = 1;

    galaxy[13][5].current = 1;
    galaxy[13][6].current = 1;
    galaxy[13][7].current = 1;
    galaxy[13][8].current = 1;
    galaxy[13][9].current = 1;
    galaxy[13][10].current = 1;

    // top 7 väli

    galaxy[5][8].current = 1;
    galaxy[5][9].current = 1;
    galaxy[5][10].current = 1;
    galaxy[5][11].current = 1;
    galaxy[5][12].current = 1;
    galaxy[5][13].current = 1;

    galaxy[6][8].current = 1;
    galaxy[6][9].current = 1;
    galaxy[6][10].current = 1;
    galaxy[6][11].current = 1;
    galaxy[6][12].current = 1;
    galaxy[6][13].current = 1;

    //right 7 väli

    galaxy[8][12].current = 1;
    galaxy[9][12].current = 1;
    galaxy[10][12].current = 1;
    galaxy[11][12].current = 1;
    galaxy[12][12].current = 1;
    galaxy[13][12].current = 1;

    galaxy[8][13].current = 1;
    galaxy[9][13].current = 1;
    galaxy[10][13].current = 1;
    galaxy[11][13].current = 1;
    galaxy[12][13].current = 1;
    galaxy[13][13].current = 1;
}