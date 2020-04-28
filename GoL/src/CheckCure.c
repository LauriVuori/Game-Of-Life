
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
     $CheckCure.c$ 

 2.  DESCRIPTION

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
 * @fn int CheckCure(struct cell Cure[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol)
 * @brief Chech neighbour cells if there is cure(num 3)	
 * @param Cure 2d array to go trough cells
 * @param cRow interger to determine current row
 * @param cCol interger to determine current colum	
 * @return If there is number 3 in nearby cells return 3 else 1.
 */
/*********************************************************************/
int CheckCure(struct cell Cure[BOARD_HEIGHT][BOARD_WIDTH],int cRow, int cCol){
int row,colum, Mcol, Mrow, Cured;

        for (row = -1; row < 2; row++){
            for (colum = -1; colum < 2; colum++){
                Mrow = (BOARD_HEIGHT + row + cRow) % BOARD_HEIGHT;
                Mcol = (BOARD_WIDTH + colum + cCol) % BOARD_WIDTH;
                
                    if (Cure[Mrow][Mcol].current == 3){
                        Cured = 3;
                        return Cured;
                    }
                    else if (Cure[Mrow][Mcol].current == 1){
                        Cured = 1;
                        return Cured;
                    }
            }
        }
    return 0;
}