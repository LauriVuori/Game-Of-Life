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

#include "main.h"


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
    int draw_speed = 100000;

do{
    clear();
    command = Navigation();

        switch (command){ //enter to exit,
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

                    if (command == KEY_1 && draw_speed >= 10000){
                        draw_speed -= 10000;
                    }

                    else if (command == KEY_2 && draw_speed <= 180000){
                        draw_speed += 10000;
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
                    usleep(draw_speed);

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