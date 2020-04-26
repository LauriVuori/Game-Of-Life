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
    Spawn virus randomly to board
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
 * @fn void Spawn_virus_cells(struct cell SpawnVirus[BOARD_HEIGHT][BOARD_WIDTH])
 * @brief Spawn virus randomly to board
 * @param SpawnVirus 2d to spawn virus on
 * @return Spawned virus on board
 */
/*********************************************************************/
void Spawn_virus_cells(struct cell SpawnVirus[BOARD_HEIGHT][BOARD_WIDTH]){
int startrow = 0;
int startcolum= 0;

    startrow = rand()%BOARD_HEIGHT + 0;
    startcolum = rand()%BOARD_WIDTH + 0;
    SpawnVirus[startrow+2][startcolum+3].current = 2;
    SpawnVirus[startrow+2][startcolum+4].current = 2;
    SpawnVirus[startrow+2][startcolum+5].current = 2;
    SpawnVirus[startrow+1][startcolum+5].current = 2;
    SpawnVirus[startrow+0][startcolum+4].current = 2;
}