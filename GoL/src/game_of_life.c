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
     $game_of_life.c$ 

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

#include "game_of_life.h"

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */
/* Global constants */
/* Global variables */
/* Global structures */
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

/*********************************************************************
   MAIN PROGRAM 
**********************************************************************/
/**
 @file game_of_life.c
 @mainpage Game of Life
 @section Intro_sec Introduction
 @date 2020
 @author Lauri Vuori
 @copyright GNU Public License.

 "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.<br>
 It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. 
 One interacts with <br> the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate <br>
 a universal constructor or any other Turing machine." (Wikipedia 2020.)
 */
/**
 @fn int main(void)
 @brief Main file to operate game and initialize ncurses
 */                                                    
/**********************************************************************/
int main(void){
struct cell board [BOARD_HEIGHT][BOARD_WIDTH] ={{{0, 0, 0}}};
int command = 0;

struct timespec Delay = {0, 100000000};

srand(time(NULL));    

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
    



do{
    clear();
    command = Navigation();

        switch (command){ /*enter to exit*/
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
           
                while (command != KEY_ESC){
                    command = getch();

                    if (command == KEY_1 && Delay.tv_nsec >= 30000000){
                        Delay.tv_nsec -= 20000000;
                    }

                    else if (command == KEY_2 && Delay.tv_nsec <= 400000000){
                        Delay.tv_nsec += 20000000;
                    }

                    else if (command == KEY_3){
                        RandBoard(board);
                    }

                    else if (command == KEY_4){
                        Spawn_virus_cells(board);
                        /*save virus start time*/
                        board[0][1].generation = board[0][0].generation;
                        /*if new virus spawned, just to clear text*/
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
                    /*After time virus dissappears*/
                    if ((board[0][0].generation - board[0][1].generation)  >= 100){
                        ClearVirus(board);
                        attron(COLOR_PAIR(LIVE));
                        mvaddstr(35,BOARD_WIDTH+10, "Virus cleared itself");
                        attroff(COLOR_PAIR(DEFAULT));
                    }
                    EvalFutureBoard(board);                   
                    Drawboard(board);
                    nanosleep(&Delay, (struct timespec *) NULL);
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
}while (command != CASE_1);
    nodelay (stdscr, FALSE);
    getch ();
    endwin ();
return 0;
} /* end of main */