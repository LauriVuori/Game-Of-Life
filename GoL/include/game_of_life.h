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
     $game_of_life.h$ 

 2.  DESCRIPTION

 3.  VERSIONS
       Original:
         $22.4.2020$ / $Lauri Vuori$

       Version history:

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

/* Global constants */

#define KEY_1 49
#define KEY_2 50 
#define KEY_3 51 
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_ESC 27
#define ENTER 10
#define UP_ARROW 450
#define DOWN_ARROW 456
#define MIN_RAND 0
#define MAX_RAND 2
#define MIN_RAND_DEATH 0
#define MAX_RAND_DEATH 100

/*100 max*/
#define BOARD_WIDTH 50
/*75 max*/
#define BOARD_HEIGHT 25


#define DEFAULT 1
#define LIVE 2
#define INFECTED 3
#define CURE 4
#define ARRAY_SIZE 1000
#define CASE_1 1
/* Global variables */

/* Global structures */
struct cell{

int current;  /* current situation, which is visible on screen */
int future;   /* temporary calculation area for next round calculation */
int generation;

};

/*!
    @struct cell
    @brief Structure to hold current and future tables
    @param current current table
    @param future future table
    @param generation adds generations every cycle
*/ 


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
void kokgalaxy(struct cell galaxy[BOARD_HEIGHT][BOARD_WIDTH]);
int Navigation(void);
void Spawn_cure_cells(struct cell SpawnCure[BOARD_HEIGHT][BOARD_WIDTH]);
int CheckCure(struct cell Cure[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol);

