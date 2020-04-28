/***************************************************************************
 *   Copyright (C) $Year$ by $Lauri Vuori$   *
 *   $ $   *
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
     $SpawnCure.c$ 

 2.  DESCRIPTION
    Spawn "cure" cells depending on neighbouring cells
    
 3.  VERSIONS
       Original:
         $Date$ / $Lauri Vuori$

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
*    FUNCTIONS                                                       *
**********************************************************************/
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
/**
 * @fn void Spawn_cure_cells(struct cell SpawnCure[BOARD_HEIGHT][BOARD_WIDTH])
 * @brief Spawn "cure" cells depending on neighbouring cells
 * @param SpawnCure 2d array 
 * @return "Cure" cells in array
 */
/*********************************************************************/
void Spawn_cure_cells(struct cell SpawnCure[BOARD_HEIGHT][BOARD_WIDTH]){
int row,colum, neighbours = 0, state = 0;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            state = SpawnCure[row][colum].current;
            neighbours = CountNeighbour(SpawnCure, row, colum);

              if (state == 2 && neighbours >= 5){
                  SpawnCure[row+2][colum+3].current = 3;
                  SpawnCure[row+2][colum+4].current = 3;
                  SpawnCure[row+2][colum+5].current = 3;
                  SpawnCure[row+1][colum+5].current = 3;
                  SpawnCure[row+0][colum+4].current = 3;
              }
        }
    }
}