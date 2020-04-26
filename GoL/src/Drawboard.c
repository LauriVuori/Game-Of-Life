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
     $Drawboard.c$ 

 2.  DESCRIPTION
     Draw dots based on array
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
 * @fn void Drawboard(struct cell Drawboard[BOARD_HEIGHT][BOARD_WIDTH])
 * @brief Draw dots based on array
 * @param Drawboard 2d array 
 * @return drawn board with ncurses
 */
/*********************************************************************/
void Drawboard(struct cell Drawboard[BOARD_HEIGHT][BOARD_WIDTH]){
int row, colum;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0;colum < BOARD_WIDTH ;colum++){
            move(row,colum);
            
            if(Drawboard[row][colum].future == 1){
                attron(COLOR_PAIR(LIVE));

                /* Draw just green backround */
                mvaddch(row, colum, ' ');
                attroff(COLOR_PAIR(DEFAULT));
            }
            else if (Drawboard[row][colum].future == 2){
                attron(COLOR_PAIR(INFECTED));

                /* Draw just green backround */
                mvaddch(row, colum, ' ');
                attroff(COLOR_PAIR(DEFAULT));
            }
            else{
                printw("%d", Drawboard[row][colum].future);  
            }   
        }
    }
}