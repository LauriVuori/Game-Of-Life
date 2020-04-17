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
       |14:22 - Added generations/ board[0][0] adds one in every gene 
       |20.11 - Added infect and Checkinfected, need to do something to spawning, only spawning 1 doesnt work
       |21.23 - Check works with new spawning is there virus in neighbours
       |21.49 - Added random death on live while infected
       >
       TODO: ENUM

**********************************************************************/


/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */


/* Global constants */
#define KEY_1 49 
#define KEY_2 50 
#define KEY_3 51 
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55

#define MIN_RAND 0
#define MAX_RAND 2
#define MIN_RAND_DEATH 0
#define MAX_RAND_DEATH 100

#define BOARD_WIDTH 50 //100 max
#define BOARD_HEIGHT 50 //75 max

#define UP_ARROW 450
#define DOWN_ARROW 456

#define DEFAULT 1
#define LIVE 2
#define INFECTED 3

//MENU
#define ARRAY_SIZE 1000
#define MIN_MENU_OPTIONS -1
#define MAX_MENU_OPTIONS 2
#define WIN_HEIGHT 25
#define WIN_WIDTH 30
#define WIN_START_Y 0
#define WIN_START_X 120

#define OPTIONS 2

#define WIN_TOPBOT '-'
#define WIN_SIDES  '|'
#define WIN_TBLC   '+'
#define WIN_TBRC   '+'

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
int CountNeighbour(struct cell Neighbour[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol);
void EvalFutureBoard(struct cell FutBoard[BOARD_HEIGHT][BOARD_WIDTH]);
void Spawn_virus_cells(struct cell SpawnVirus[BOARD_HEIGHT][BOARD_WIDTH]);
void ClearVirus(struct cell board[BOARD_HEIGHT][BOARD_WIDTH]);
void Drawboard(struct cell Drawboard[BOARD_HEIGHT][BOARD_WIDTH]);
int Checkinfected(struct cell infected[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol);

// Testing patterns and oscillators
void kokgalaxy(struct cell galaxy[BOARD_HEIGHT][BOARD_WIDTH]);

int Navigation(void);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
int main(void){
    srand(time(NULL));
    struct cell board [BOARD_HEIGHT][BOARD_WIDTH] = {0, 0};

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
    curs_set(0);

    int command = 0;
    int speed = 100000;


do{
    clear();

    command = Navigation();

        switch(command){ //enter to exit,
            case 0:
                clear();
                attron(COLOR_PAIR(LIVE));
                mvaddstr(10,BOARD_WIDTH+10, "Esc to exit");
                mvaddstr(11,BOARD_WIDTH+10, "Key 1 Faster");
                mvaddstr(12,BOARD_WIDTH+10, "Key 2 slower");
                mvaddstr(14,BOARD_WIDTH+10, "Key 3 Spawn live cells");
                mvaddstr(15,BOARD_WIDTH+10, "Key 4 Virus cells");
                mvaddstr(17,BOARD_WIDTH+10, "Key 5 spawn kokgalaxy");
                mvaddstr(18,BOARD_WIDTH+10, "Key 6 Clear table");
                mvaddstr(19,BOARD_WIDTH+10, "Key 7 Clear virus");
                attroff(COLOR_PAIR(DEFAULT));
           
                while(command != 27){
                    command = getch();

                    if (command == KEY_1 && speed >= 10000){
                        speed -= 10000;
                    }

                    else if (command == KEY_2 && speed <= 180000){
                        speed += 10000;
                    }

                    else if (command == KEY_3){
                        RandBoard(board);
                    }

                    else if (command == KEY_4){
                        Spawn_virus_cells(board);
                        //save virus start time
                        board[0][1].generation = board[0][0].generation;
                        //if new virus spawned, just to clear text
                        mvaddstr(35,BOARD_WIDTH+10, "                     ");
                    }

                    else if (command == KEY_5){
                        kokgalaxy(board);
                    }

                    else if (command == KEY_6){
                        memset(board, 0, sizeof board);
                    }

                    else if (command == KEY_7){
                        ClearVirus(board);
                    }
                    //After time virus dissappears
                    if ((board[0][0].generation - board[0][1].generation)  >= 100){
                        ClearVirus(board);
                        attron(COLOR_PAIR(LIVE));
                        mvaddstr(35,BOARD_WIDTH+10, "Virus cleared itself");
                        attroff(COLOR_PAIR(DEFAULT));
                    }

                    EvalFutureBoard(board);                   
                    Drawboard(board);
                    usleep(speed);

                }
                break;
            case 1:
                clear();
                attron(COLOR_PAIR(LIVE));
                mvaddstr(15,15, "Press enter to exit");
                attroff(COLOR_PAIR(DEFAULT));
                break;    
        default:
        break;
        }
}while(command != 1);
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
 NAME:Navigation
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
int Navigation(void){
    int choice, highlight = 0;
    int i = 0;              
    char choices[ARRAY_SIZE][ARRAY_SIZE] = {
                            "Start game with live cells",
                            "exit",
    };

//print game of life on screen
attron(COLOR_PAIR(LIVE));
mvaddstr(5,5, " ______     ______     __    __     ______        ______     ______      __         __     ______   ______");
mvaddstr(6,5, "/\\  ___\\   /\\  __ \\   /\\  -./  \\   /\\  ___\\      /\\  __ \\   /\\  ___\\    /\\ \\       /\\ \\   /\\  ___\\ /\\  ___\\");
mvaddstr(7,5, "\\ \\ \\__ \\  \\ \\  __ \\  \\ \\ \\-./\\ \\  \\ \\  __\\      \\ \\ \\/\\ \\  \\ \\  __\\    \\ \\ \\____  \\ \\ \\  \\ \\  __\\ \\ \\  __\\"); 
mvaddstr(8,5, " \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\     \\ \\_____\\  \\ \\_\\       \\ \\_____\\  \\ \\_\\  \\ \\_\\    \\ \\_____\\");
mvaddstr(9,5, "  \\/_____/   \\/_/\\/_/   \\/_/  \\/_/   \\/_____/      \\/_____/   \\/_/        \\/_____/   \\/_/   \\/_/     \\/_____/");
attroff(COLOR_PAIR(DEFAULT));

    WINDOW * menuwindow = newwin(WIN_HEIGHT, WIN_WIDTH, WIN_START_Y, WIN_START_X);
    wborder(menuwindow, WIN_SIDES, WIN_SIDES, WIN_TOPBOT, WIN_TOPBOT, WIN_TBLC, WIN_TBLC, WIN_TBRC, WIN_TBRC);
    refresh();
    wrefresh(menuwindow);

    keypad(menuwindow, TRUE);

    while(1){
       
        for (i = 0; i < MAX_MENU_OPTIONS; i++){
            if (i == highlight){
                wattron(menuwindow, A_REVERSE);
            }
            mvwprintw(menuwindow, i+1, 1, choices[i]);
            wattroff(menuwindow, A_REVERSE);

        }
        choice = wgetch(menuwindow);
        
        switch (choice){
            case KEY_UP: //TODO: vaihda KEY_UP, ei toimi vsc terminal, windows nuoli ylös 450
                highlight--;
                
                    if (highlight == MIN_MENU_OPTIONS){ 
                        highlight = MIN_MENU_OPTIONS+1;
                    }
                break;
        
            case KEY_DOWN: //TODO: vaihda KEY_DOWN, ei toimi vsc terminal, windows nuoli alas
                highlight++;
                    
                    if (highlight == MAX_MENU_OPTIONS){ 
                        highlight = MAX_MENU_OPTIONS-1;
                    }
                break;
        default:
            break;
        }
        if (choice == 10){ // enter
            return highlight;
            break;
        }
    }

}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME:ClearVirus
 DESCRIPTION:Clear board from virus
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function: //TODO: Maybe rand if survives
*********************************************************************/
void ClearVirus(struct cell Clear[BOARD_HEIGHT][BOARD_WIDTH]){
    int row,colum;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){

            if (Clear[row][colum].current == 2){
                Clear[row][colum].current = 1;
                //TODO: rand death:
            }
        }
    }
}
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
 NAME:Spawn virus
 DESCRIPTION:
	Input:
	Output:
  Used global variables:
  Used global constants:
 REMARKS when using this function:
*********************************************************************/
void Spawn_virus_cells(struct cell SpawnVirus[BOARD_HEIGHT][BOARD_WIDTH]){

    SpawnVirus[BOARD_HEIGHT/2+2][BOARD_WIDTH/2+3].current = 2;
    SpawnVirus[BOARD_HEIGHT/2+2][BOARD_WIDTH/2+4].current = 2;
    SpawnVirus[BOARD_HEIGHT/2+2][BOARD_WIDTH/2+5].current = 2;
    SpawnVirus[BOARD_HEIGHT/2+1][BOARD_WIDTH/2+5].current = 2;
    SpawnVirus[BOARD_HEIGHT/2+0][BOARD_WIDTH/2+4].current = 2;
    /*
    for(int i = 0; i<= 50; i++){
    SpawnVirus[rand()%BOARD_HEIGHT+0][rand()%BOARD_WIDTH+0].current= 2;
    }*/
}
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
    int i = 10;
    //left
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

    //bottom 11 rivi väli

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

    // top 7 väli

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

    //right 7 väli

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