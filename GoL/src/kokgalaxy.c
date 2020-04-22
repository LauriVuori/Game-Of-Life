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

 3.  VERSIONS
       Original:
         $22.4.2020$ / $Lauri Vuori$

       Version history:

**********************************************************************/
/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include "game_of_life.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
/**
 * @fn void kokgalaxy(struct cell galaxy[BOARD_HEIGHT][BOARD_WIDTH])
 * @brief Draw predefined pattern on array
 * @param galaxy 2d array to draw on
 * @return game of life oscillator "kok's galaxy" on array
 */
/*********************************************************************/
void kokgalaxy(struct cell galaxy[BOARD_HEIGHT][BOARD_WIDTH]){
int i = 10;

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