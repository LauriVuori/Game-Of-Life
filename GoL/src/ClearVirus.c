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
     $ClearVirus.c$ 

 2.  DESCRIPTION
    Clear array from number '2' and change them randomly to 0 and 1
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
	F U N C T I O N    D E S C R I P T I O N
----------------------------------------------------------------------*/
/**
 * @fn void ClearVirus(struct cell Clear[BOARD_HEIGHT][BOARD_WIDTH])
 * @brief Clear board from virus(num 2)
 * @param Array to remove 2's from it
 * @return Array without 2's
 */
/*********************************************************************/
void ClearVirus(struct cell Clear[BOARD_HEIGHT][BOARD_WIDTH]){
int row,colum;

    for (row = 0; row < BOARD_HEIGHT; row++){
        for (colum = 0; colum < BOARD_WIDTH; colum++){
            if (Clear[row][colum].current == 3){
                Clear[row][colum].current = 1; 
            }
            else if (Clear[row][colum].current == 2){
                /* chance to die randomly on virus disappears--->*/
                if (rand()%MAX_RAND_DEATH+MIN_RAND_DEATH== 1){
                        Clear[row][colum].future = 0;
                }
                else{
                    Clear[row][colum].current = 1;  
                }
                
                
            }
        }
    }
}