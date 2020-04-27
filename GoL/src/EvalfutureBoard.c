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
     $Source$ 

 2.  DESCRIPTION
    Evaluate what happens to cell
 3.  VERSIONS
       Original:
         $22.4.2020$ / $Lauri Vuori$

       Version history:

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
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/
/**
 * @fn void EvalFutureBoard(struct cell FutBoard[BOARD_HEIGHT][BOARD_WIDTH])
 * @brief Evaluate what happens to cell
 * @param FutBoard 2d array to evaluate cells future
 * @return New value in cells depending on terms
 */
/*********************************************************************/
void EvalFutureBoard(struct cell FutBoard[BOARD_HEIGHT][BOARD_WIDTH]){
int row,colum, neighbours = 0, state = 0;
/*Start counting generations*/
FutBoard[0][0].generation++;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            state = FutBoard[row][colum].current;
            neighbours = CountNeighbour(FutBoard, row, colum);

                if (state == 0 && neighbours == 3){
                    if((CheckCure(FutBoard,row,colum)) == 3){
                        FutBoard[row][colum].future = 3;
                    }

                    else if ((Checkinfected(FutBoard,row,colum)) == 2){
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
                    /* CHANCE TO INFECTED DIE RANDOM--->*/
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
                else if (state == 3 && (neighbours == 2 || neighbours == 3)){
                    FutBoard[row][colum].future = 3;
                }
                else if (state == 3 && (neighbours < 2 || neighbours > 3)){
                    FutBoard[row][colum].future = 0;
                }
        }

    }
    /*Current to new array */
    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            FutBoard[row][colum].current = FutBoard[row][colum].future;
        }
    }
}